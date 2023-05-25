package com.maniu.handlermaniu;

public class Handler {
//Google 就是这样写的
    Looper mLooper;
    public Handler() {
        mLooper = Looper.myLooper();
    }
    public void sendMessage(Message msg) {
        enqueueMessage(msg);
    }
    private void enqueueMessage(Message msg) {
        msg.target = this;
        mLooper.messageQueue.enqueueMessage(msg);
    }
    public void handleMessage(Message msg) {


    }
}
