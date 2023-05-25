package com.maniu.handlermaniu;

public class Message {
    String obj;
    Handler target;
    public Message() {
    }
    public Message(String obj) {
        this.obj = obj;
    }
    public String toString(){
        return obj.toString();
    }
}
