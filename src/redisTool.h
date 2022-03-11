#ifndef REDIS_TOOL_H
#define REDIS_TOOL_H

#include <sw/redis++/redis++.h>
#include <chrono>
#include <iostream>

using namespace std;
using namespace sw::redis;
using MS = std::chrono::milliseconds;

class RedisTool
{
public:
    RedisTool(string host, int port, int pool_size, MS socket_timeout_, MS wait_timeout_, MS connection_lifetime_, int max_reconntime_ = 20, string uri = "tcp://127.0.0.1:6379") : redis(Redis(uri)), socket_timeout(socket_timeout_), wait_timeout(wait_timeout_), connection_lifetime(connection_lifetime_), reconn_max(max_reconntime_)
    {
        connection_options.host = host;
        connection_options.port = port;
        connection_options.socket_timeout = socket_timeout;

        pool_options.size = pool_size;
        pool_options.wait_timeout = wait_timeout;
        pool_options.connection_lifetime = connection_lifetime_;

        redis = std::move(Redis(connection_options, pool_options));
    }

    void setString(string key, string val)
    {
        try
        {
            redis.set(key, val);
            cnt = 0;
        }
        catch (const ClosedError &error)
        {
        }
        catch (const IoError &error)
        {
        }
    }

    string getString(string key)
    {
        try
        {
            auto val = redis.get(key);
            cnt = 0;
            return *val;
        }
        catch (const ClosedError &error)
        {

        }
        catch (const IoError &error)
        {

        }
    }

    void reconnect(){

    }

    ~RedisTool()
    {
    }

private:
    Redis redis;
    ConnectionOptions connection_options;
    ConnectionPoolOptions pool_options;
    MS socket_timeout;
    MS wait_timeout;
    MS connection_lifetime;
    int cnt;
    int reconn_max;
    
};

#endif