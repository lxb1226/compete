#ifndef REDIS_CONFIG_H
#define REDIS_CONFIG_H

#include <string.h>
#include <iostream>
#include <hiredis/hiredis.h>

class RedisConfig
{
private:
    std::string ip;
    int port;
    redisConnectionType type;
    timeval timeout;
    int reconn_max;
    int reconn_interval;

public:
    // RedisConfig(/* args */)
    // {
    // }

    RedisConfig(std::string ip_ = std::string("127.0.0.1"), int port_ = 6379, redisConnectionType type_ = REDIS_CONN_TCP, timeval timeout_ = {1, 50000}, int reconn_max_ = 10, int reconn_interval_ = 1) : ip(ip_), port(port_), type(type_), timeout(timeout_), reconn_max(reconn_max_), reconn_interval(reconn_interval_) {}

    ~RedisConfig()
    {
    }
    // get ip address
    std::string getRedisIP()
    {
        return ip;
    }
    // get port
    int getRedisPort()
    {
        return port;
    }
    redisConnectionType getConnectionType()
    {
        return type; // connection type : tcp
    }
    timeval getTimeout()
    {
        return timeout;
    }
    int getReconnMax()
    {
        return reconn_max; // try 10 times to reconnect
    }
    int getReconnInterval()
    {
        return reconn_interval;
    }
};

#endif