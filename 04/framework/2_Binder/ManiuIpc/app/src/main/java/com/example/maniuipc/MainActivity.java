package com.example.maniuipc;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.example.ipclib.core.DavidBinderIPC;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        开启服务
        DavidBinderIPC.getDefault().open(this);
//        服务注册
       DavidBinderIPC.getDefault().register(DavidSinglton.class);
        DavidBinderIPC.getDefault().register(DowloadSinglton.class);
       DavidSinglton.getInstance("david",1111).setUserInfo(new UserInfo("maniu", "david   love  99"));
//服务发现
    }

    public void change(View view) {
        startActivity(new Intent(this, SecondActivity.class));
    }
}