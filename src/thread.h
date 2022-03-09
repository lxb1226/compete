// 线程对象

#ifndef XY_thread_H
#define XY_thread_H


#include <pthread.h>

#include <string>
using namespace std;


namespace XY
{
    class Thread
    {
    public:
        Thread();
        virtual ~Thread();

    protected:
        void            start   ();         // 启动线程
        void            stop    ();         // 停止线程

        virtual void    runOnce () = 0;     // 被重复调用的线程执行函数，需要被重载

    private:
        static  void *  func    (void *);   // 线程类的执行函数，被线程创建函数调用

        void            run     ();         // 线程函数

    private:
        pthread_t       m_tid;
        bool            m_run;
    };


}   // namespace XY


#endif

