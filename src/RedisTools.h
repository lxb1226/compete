#ifndef _H_REDIS_TOOLS_
#define _H_REDIS_TOOLS_

#include <iostream>
#include <vector>
#include <hiredis/hiredis.h>
#include "redisConfig.h"
#include "thread.h"

using namespace std;

enum class REDIS_STATE : int8_t
{
    ESTABLISH = 0,
    RECONN_FIALED
};

class RedisTool
{
public:
    RedisTool();
    ~RedisTool();
    int setString(string key, string value);
    string getString(string key);

    int setList(string key, vector<int> value);
    vector<int> getList(string key);

    int redisAutoConnect(redisContext **redis, int max, int interval);
    int redisBulkGetReply(redisContext *redis);
    // void runOnce();
    REDIS_STATE getState()
    {
        return state;
    }
    string ping();

private:
    void init();
    redisContext *m_redis;
    RedisConfig m_config;
    redisConnectionType type;

    timeval timeout_rw;
    timeval timeout_conn;

    int reconn_interval;
    int reconn_max;
    char ip[255];
    int port;
    char *path;
    REDIS_STATE state;
};

#endif