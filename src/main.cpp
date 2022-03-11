#include <stdio.h>
#include <hiredis/hiredis.h>
#include "RedisTools.h"
#include <unistd.h>

using namespace std;

int main()
{
    RedisTool redis;

    while (1)
    {
        int ret = redis.setString("foo", "testing");
        if (ret < 0)
        {
            sleep(5);
            continue;
        }

        std::string result = redis.getString("foo");
        std::cout << "result = " << result << endl;
        sleep(5);
    }

    return 0;
}
