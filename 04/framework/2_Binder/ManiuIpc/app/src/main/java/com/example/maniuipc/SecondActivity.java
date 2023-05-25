package com.example.maniuipc;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;

import com.example.ipclib.core.DavidBinderIPC;

public class SecondActivity  extends Activity {
    //    不要拿实现类  接口
    IDavidSinglton davidService = null;
    IDowloadSinglton dowloadSinglton = null;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        DavidBinderIPC.getDefault().open(this);
    }

    public void davidService(View view) {
//        拿到接口   一定要   服务顾客
//        davidService = DavidBinderIPC.getDefault().getInstance(IDavidSinglton.class,
//                "david",111);
        dowloadSinglton = DavidBinderIPC.getDefault().getInstance(IDowloadSinglton.class);

    }

    public void getUser(View view) {
        String data =   dowloadSinglton.download("http://baidu/1.jpg") ;
        Toast.makeText(this, data, Toast.LENGTH_SHORT).show();
    }
}
