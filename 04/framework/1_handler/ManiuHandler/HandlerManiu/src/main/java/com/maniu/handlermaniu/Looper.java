package com.maniu.handlermaniu;

public class Looper {
//    一个线程 几个loop
//    1个  1

    //    ThreadLocal
//  利用threadLocal  ---》ThreadLocalMap
    static ThreadLocal<Looper> sThreadLocal = new ThreadLocal<>();
//    N个  2
    MessageQueue messageQueue;
    //    保证Looper唯一   messageQueue也唯一了
    private Looper() {
        messageQueue = new MessageQueue();
    }
    public static Looper myLooper() {
        return sThreadLocal.get();
    }
//    Looper   的生命周期   多长  当前线程生命周期的长度
    public static void  prepare() {
//   自己的对象 作为key  -----》 Looper
//   一个 线程 ----保证只有一个Looper
//    利用 sThreadLocal   讲  Loooper 对象 存到了Thread对象中map中
//2
        if (sThreadLocal.get() != null) {
            throw new RuntimeException("Only one Looper may be created per thread");
        }
//       sThreadLocal       key--- Looper
        sThreadLocal.set(new Looper());
    }

    public static  void looper() {
        final Looper me = myLooper();
        final MessageQueue queue = me.messageQueue;
        for (; ; ) {
            Message msg=   queue. next();
            msg.target.handleMessage(msg);
//            无 解   架构师  程序 使用 架构  声明个Handler
//            Google工程师
//            handleMessage(msg);
        }
    }
}
