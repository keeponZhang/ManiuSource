package com.maniu.camera1maniu;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    ManiuSurfaceView maniuSurfaceView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        maniuSurfaceView = (ManiuSurfaceView) findViewById(R.id.surface);
    }

    public void captrue(View view) {
        maniuSurfaceView.startCaptrue();
    }
}