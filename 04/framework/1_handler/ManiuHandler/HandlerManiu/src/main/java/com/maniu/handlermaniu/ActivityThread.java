package com.maniu.handlermaniu;

public class ActivityThread {
    private static Handler handler111;
    private static Handler handler222;
    public static void main(String[] args) {

        Looper.prepare();
        handler111 = new Handler() {
            @Override
            public void handleMessage(Message msg) {
                System.out.println("handler111 " + msg + " thread  " + Thread.currentThread().getName());
            }
        };
//        handler   一个队列   for循环
        new Thread() {
            @Override
            public void run() {
                handler111.sendMessage(new Message("david---->jett"));
            }
        }.start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        Looper.looper();
//       1 大量消息 过来的   容易阻塞 队列
//       2  不能做到线程通信 +线程切换 sheng

    }
}