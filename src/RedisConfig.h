#ifndef REDISCONFIG_H
#define REDISCONFIG_H
#include <string.h>
#include <iostream>
#include <hiredis/hiredis.h>

namespace XY
{
    class RedisConfig
    {
    private:
        /* data */
    public:
        RedisConfig(/* args */)
        {
        }
        ~RedisConfig()
        {
        }
        // get ip address
        std::string getRedisIP()
        {
            return "127.0.0.1";
        }
        // get port
        int getRedisPort()
        {
            return 6379;
        }
        redisConnectionType getConnectionType()
        {
            return REDIS_CONN_TCP; // connection type : tcp
        }
        timeval getTimeout()
        {
            timeval t = {1, 50000};
            return t;
        }
        int getReconnMax()
        {
            return 10; // try 10 times to reconnect
        }
        int getReconnInterval()
        {
            return 1;
        }
    };

} // namespace XY

#endif
