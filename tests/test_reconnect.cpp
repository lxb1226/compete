#include <stdio.h>
#include <hiredis/hiredis.h>
#include "../src/RedisTools.h"
#include <unistd.h>

using namespace std;

int main()
{
    RedisTool redis;

    while (1)
    {
        int ret = redis.setString("foo", "testing");
        if (redis.getState() != REDIS_STATE::ESTABLISH)
        {
            cout << "redis 断开了连接" << endl;
            break;
        }

        std::string result = redis.getString("foo");
        if (redis.getState() != REDIS_STATE::ESTABLISH)
        {
            cout << "redis 断开了连接" << endl;
            break;
        }
        std::cout << "result = " << result << endl;
        sleep(2);
    }

    return 0;
}
