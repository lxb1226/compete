#ifndef _H_REDIS_TOOLS_
#define _H_REDIS_TOOLS_

#include <iostream>
#include <vector>
#include <hiredis/hiredis.h>
#include "RedisConfig.h"
#include "thread.h"
#include "serialization.h"

#include "serialtest.h"

using namespace std;

namespace XY
{
        class RedisTool : public Thread
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
                void runOnce();

                string ping();
                // template<class T = McpttCall>
                // void writeRedis(const T& t, string& name);
                
                // template<class T = McpttCall>
                // T readFromRedis(string& name);

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

                // Serialization seriaTool;
        };
}

#endif