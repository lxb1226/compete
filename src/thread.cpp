// 线程对象

#include "thread.h"
using namespace XY;


// 构造函数
Thread::Thread()
    :   m_run(false)
{
}


// 析构函数
Thread::~Thread()
{
    stop();
}


// 线程执行函数，被线程创建函数调用
void * Thread::func(void *arg)
{
    if (NULL != arg)
    {
        ((Thread *) arg)->run();
    }

    pthread_exit(0);
}


// 启动线程
void Thread::start()
{
    if (!m_run)
    {
        m_run = true;
        pthread_create(&m_tid, NULL, func, this);
    }
}


// 停止线程
void Thread::stop()
{
    if (m_run)
    {
        m_run = false;
        pthread_join(m_tid, NULL);
    }
}


// 线程函数
void Thread::run()
{
    while (m_run)
    {
        runOnce();
    }
}

