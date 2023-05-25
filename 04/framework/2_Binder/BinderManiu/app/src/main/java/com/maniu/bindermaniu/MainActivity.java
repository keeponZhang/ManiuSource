package com.maniu.bindermaniu;

import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    ManiuBinder maniuBinder;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        内存
//        初级  内存
//        2年 业务逻辑  api
//        bat
        maniuBinder = new ManiuBinder();
        checkPermission();
    }

    public boolean checkPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && checkSelfPermission(
                Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[]{
                    Manifest.permission.READ_EXTERNAL_STORAGE,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE
            }, 1);
        }
        return false;
    }
    public void write(View view) {
        maniuBinder.write();
    }

    public void jump(View view) {
        new Thread() {

            @Override
            public void run() {
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                intent.putExtra("david", new byte[1024 * 1024 - 8 * 1024]);
                startActivity(intent);
            }
        }.start();
    }
}
