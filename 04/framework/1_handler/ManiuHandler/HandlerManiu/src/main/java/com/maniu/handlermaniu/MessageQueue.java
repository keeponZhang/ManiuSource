package com.maniu.handlermaniu;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class MessageQueue {
//


    BlockingQueue<Message> queue = new ArrayBlockingQueue<>(100);

//   put  =enqueueMessage

    public void enqueueMessage(Message msg) {
        try {
            queue.put(msg);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
//    0----
    public Message next() {
        Message msg = null;
        try {
            msg = queue.take();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return msg;
    }


}
