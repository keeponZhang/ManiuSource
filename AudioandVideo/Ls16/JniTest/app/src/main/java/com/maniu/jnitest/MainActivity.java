package com.maniu.jnitest;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Person;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.lang.reflect.Method;

public class MainActivity extends AppCompatActivity {

    MainActivity activity;
//
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    TextView tv  ;

    public String text = "maniu";
    public int num = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        throw new RuntimeException("excetim");
    }

    public native String func1();
    public native String func2();

    public native String func4();

//    static   jlcass   jobject
    public     native String func3();
    public void func1(View view) {
        tv.setText(func1());
    }

    public void func2(View view) {
        tv.setText(func2());
    }
    public void func3(View view) {
        String s = func3();
        tv.setText(text);
    }


    public void func4(View view) {
        func4();
    }
//    FFmppeg mp4  回调  (I)V

    public void callBack(int code){
        Toast.makeText(this, "native层回调  " + code, Toast.LENGTH_SHORT).show();
    }
}
