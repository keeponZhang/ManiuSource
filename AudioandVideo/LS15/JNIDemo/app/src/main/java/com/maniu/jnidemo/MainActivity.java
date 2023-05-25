package com.maniu.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        //
        TextView tv = findViewById(R.id.sample_text);
    }
//naitve代码 非常频繁调用 会导致 性能降低
    public native void  memery();
    public native void  memery1();
    public native void  destroy();
}
