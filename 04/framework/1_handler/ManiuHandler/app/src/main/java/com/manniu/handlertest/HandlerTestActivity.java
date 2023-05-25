package com.manniu.handlertest;

import android.graphics.PixelFormat;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.maniu.maniuhandler.databinding.ActivityHandlerTestBinding;

/**
 * Time:2023-04-29 上午 11:43
 * Author:
 * Description:
 */
public class HandlerTestActivity extends AppCompatActivity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ActivityHandlerTestBinding binding = ActivityHandlerTestBinding.inflate(LayoutInflater.from(this));
        setContentView(binding.getRoot());
        binding.add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new NonUiThread().start();
            }
        });
        binding.handlerLoop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handlerLoop();
            }
        });
    }

    private void handlerLoop() {
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(HandlerTestActivity.this, "loop执行", Toast.LENGTH_SHORT).show();
                    }
                });

                Looper.prepare();
                Handler handler = new Handler(Looper.myLooper());
                Looper.loop();
                //不会执行
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(HandlerTestActivity.this, "loop执行结束", Toast.LENGTH_SHORT).show();
                    }
                });
            }
        });
        thread.start();
    }

    class NonUiThread extends Thread {
        @Override
        public void run() {
            Looper.prepare();
            TextView tx = new TextView(HandlerTestActivity.this);
            tx.setText("non-UiThread update textview");

            WindowManager windowManager = HandlerTestActivity.this.getWindowManager();
            WindowManager.LayoutParams params = new WindowManager.LayoutParams(
                200, 200, 200, 200, WindowManager.LayoutParams.FIRST_SUB_WINDOW,
                WindowManager.LayoutParams.TYPE_TOAST, PixelFormat.OPAQUE);
            windowManager.addView(tx, params);
            Looper.loop();
        }
    }

}
