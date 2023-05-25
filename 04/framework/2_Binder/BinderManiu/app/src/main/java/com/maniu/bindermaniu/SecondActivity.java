package com.maniu.bindermaniu;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {

    ManiuBinder maniuBinder;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sceond);
        maniuBinder = new ManiuBinder();
    }
    public void read(View view) {
        Toast.makeText(this, "跨进程读取消息" + maniuBinder.read(), Toast.LENGTH_SHORT).show();
    }
}
