package com.maniu.maniuhandler;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

public class MainActivity extends AppCompatActivity {
//    google handler  开发   拖鞋
//    一种妥协的产物 架构
    class Person{

}
    class  MyHandler{
        public void  sendMessage(Message message) {
            handleMessage(message);
        }


        public void handleMessage(Message message) {
//阻塞

        }
    }
    Person person;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        person = new Person();

        MyHandler handler = new MyHandler();
            handler.sendMessage(new Message());
        handler.sendMessage(new Message());
        handler.sendMessage(new Message());
        handler.sendMessage(new Message());
        handler.sendMessage(new Message());
        handler.sendMessage(new Message());
        handler.sendMessage(new Message());



    }
}