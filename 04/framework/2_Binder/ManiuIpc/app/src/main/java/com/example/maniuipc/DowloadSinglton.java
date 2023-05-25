package com.example.maniuipc;

import android.util.Log;

// 服务      service层面   子类  对应   父类
public class DowloadSinglton implements IDowloadSinglton {
    private static DowloadSinglton sInstance = null;
    private DowloadSinglton() {
    }
    //    对象---》   值  "1"   值  java.lang.String
    public static synchronized DowloadSinglton getInstance(  ) {
        if (sInstance == null) {
            sInstance = new DowloadSinglton();
        }
        return sInstance;
    }


    @Override
    public String download(String url) {
        return "下载成功";
    }
}
