package com.example.moudle4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.ipclib.core.DavidBinderIPC;
import com.example.maniuipc.IDavidSinglton;

public class MainActivity extends AppCompatActivity {
    IDavidSinglton davidService = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        DavidBinderIPC.getDefault().open(this,"com.example.maniuipc");
    }

    public void davidService(View view) {
        davidService = DavidBinderIPC.getDefault().getInstance(IDavidSinglton.class,"david",12213);
    }

    public void getUser(View view) {
        String data = davidService.getUserInfo().toString();
        Toast.makeText(this, data, Toast.LENGTH_SHORT).show();

    }
}