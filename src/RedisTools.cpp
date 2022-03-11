#include "RedisTools.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <unistd.h>

RedisTool::RedisTool()
{
    m_redis = NULL;
    init();
}

RedisTool::~RedisTool()
{

    if (m_redis != NULL)
    {
        redisFree(m_redis);
        cout << "~RedisTool :: free redis connection " << endl;
    }
}

void RedisTool::init()
{
    struct timeval timeout = {1, 500000}; // 1.5 seconds set connetion wait time

    type = m_config.getConnectionType();
    std::cout << "init : connection type = " << type << endl;

    reconn_max = m_config.getReconnMax();
    std::cout << "init : reconn max = " << reconn_max << endl;

    reconn_interval = m_config.getReconnInterval();
    std::cout << "init : reconn interval = " << reconn_interval << endl;

    strcpy(ip, m_config.getRedisIP().c_str());
    std::cout << "init : ip = " << ip << endl;

    port = m_config.getRedisPort();
    std::cout << "init : port = " << port << endl;

    if (NULL == m_redis)
    {
        if (type == REDIS_CONN_TCP)
            m_redis = redisConnectWithTimeout(ip, port, timeout);
        else
            m_redis = redisConnectUnixWithTimeout(path, timeout);

        if (NULL == m_redis)
        {
            std::cout << "redis allocate context fail\n"
                      << endl;
            return;
        }
        else if (m_redis->err)
        {
            std::cout << "redis connection " << ip << " " << port << " " << m_redis->errstr << endl;
            redisFree(m_redis);
            m_redis = NULL;
            return;
        }
        state = REDIS_STATE::ESTABLISH;
        std::cout << " redis connected " << endl;
    }
}

int RedisTool::setString(string key, string value)
{
    if (m_redis == NULL || m_redis->err)
    {
        int ret = redisAutoConnect(&m_redis, reconn_max, reconn_interval);
        if (ret < 0)
        {
            state = REDIS_STATE::RECONN_FIALED;
            return -1;
        }

        // init();
    }

    redisReply *reply;
    reply = (redisReply *)redisCommand(m_redis, "SET %s %s", key.c_str(), value.c_str());
    if (reply == NULL)
    {
        // redisFree(m_redis);
        // m_redis == NULL;
        std::cout << " set string fail : reply->str = NULL " << endl;

        return -1;
    }
    else if (strcmp(reply->str, "OK") == 0)
    {
        std::cout << "set: " << reply->str << endl;
    }
    else
    {
        std::cout << "set string fail : " << reply->str << endl;
        return -1;
    }
    freeReplyObject(reply);
    return 1;
}

string RedisTool::getString(string key)
{
    if (m_redis == NULL || m_redis->err)
    {
        int ret = redisAutoConnect(&m_redis, reconn_max, reconn_interval);
        if (ret < 0)
        {
            state = REDIS_STATE::RECONN_FIALED;
            return "";
        }
    }

    redisReply *reply;
    reply = (redisReply *)redisCommand(m_redis, "GET %s", key.c_str());
    std::cout << "get string type = " << reply->type << endl;

    if (reply == NULL)
    {
        // redisFree(m_redis);
        // m_redis = NULL;
        std::cout << "ERROR getString : reply = NULL !!!" << endl;
        return NULL;
    }
    else if (reply->len <= 0)
    {
        freeReplyObject(reply);
        return NULL;
    }
    else
    {
        stringstream ss;
        ss << reply->str;
        freeReplyObject(reply);
        return ss.str();
    }
}

string RedisTool::ping()
{
    if (m_redis == NULL || m_redis->err)
    {
        return NULL;
    }

    redisReply *reply = (redisReply *)redisCommand(m_redis, "PING");
    std::cout << reply->str << endl;

    if (reply == NULL)
    {
        // redisFree(m_redis);
        // m_redis = NULL;
        std::cout << "ERROR PING : reply = NULL !!! " << endl;
        return NULL;
    }
    else if (reply->len <= 0)
    {
        freeReplyObject(reply);
        return NULL;
    }
    else
    {
        stringstream ss;
        ss << reply->str;
        freeReplyObject(reply);
        return ss.str();
    }
}

int RedisTool::redisAutoConnect(redisContext **redis, int max, int interval)
{
    // std::cout<<"redis auto connect "<< endl;

    if (NULL == *redis)
    {
        std::cout << "redis auto connect : m_redis is NULL" << endl;
        struct timeval timeout = {1, 500000}; // 1.5 seconds set connetion wait time
        redisContext *ctx;
        if (type == REDIS_CONN_TCP)
            ctx = redisConnectWithTimeout(ip, port, timeout);
        else
            ctx = redisConnectUnixWithTimeout(path, timeout);

        if (NULL == ctx)
        {
            std::cout << "redis allocate context fail\n"
                      << endl;
            return -1;
        }
        else if (ctx->err)
        {
            std::cout << "redis connection " << ip << " " << port << " " << ctx->errstr << endl;
            redisFree(ctx);
            ctx = NULL;
            return -1;
        }

        *redis = ctx;

        if (*redis == NULL)
        {
            std::cout << "redis auto connect redis = ctx = NULL " << endl;
        }
        else
        {
            std::cout << "redis -> flag : " << (*redis)->flags << endl;
        }
    }
    else
    {
        if (redisBulkGetReply(*redis) == 0)
        {
            std::cout << "redis auto connect : redis bulk get reply return 0 " << endl;
            return 0;
        }

        if (!((*redis)->flags & REDIS_CONNECTED)) // *******
        {
            std::cout << "redis auto reconnect " << endl;
            int retry = max, n = 0;
            do
            {
                if (REDIS_OK == redisReconnect(*redis))
                {
                    state = REDIS_STATE::ESTABLISH;
                    return 0;
                }
                std::cout << " redis reconnect " << ++n << " error : " << (*redis)->errstr << endl;
                sleep(interval);

            } while (--retry > 0);
            return -1;
        }
    }

    return 0;
}

int RedisTool::redisBulkGetReply(redisContext *redis)
{
    redisReply *r;
    int i = 0;

    if (REDIS_OK == redisGetReply(redis, (void **)&r))
    {
        if (r->type == REDIS_REPLY_ERROR)
        {
            std::cout << "redis get reply error: " << r->len << " " << r->str << endl;
            freeReplyObject(r);
            return -1;
        }
        freeReplyObject(r);
    }
    else
    {
        if (redis->err == REDIS_ERR_IO || redis->err == REDIS_ERR_EOF)
            redis->flags &= ~REDIS_CONNECTED;
        std::cout << "redis get reply fail: " << redis->errstr << endl;
        return -1;
    }

    return 0;
}