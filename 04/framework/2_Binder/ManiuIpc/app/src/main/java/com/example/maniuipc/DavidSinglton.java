package com.example.maniuipc;

import android.app.Service;
import android.util.Log;

// 服务      service层面   子类  对应   父类
public class DavidSinglton  implements IDavidSinglton {
    private static DavidSinglton sInstance = null;
    private DavidSinglton() {
    }
    UserInfo userInfo;
//    一定要是单例    单例获取  getInstance 方法名一定 getInstance
//    对象---》   值  "1"   值  java.lang.Interger
//public static synchronized DavidSinglton getInstance(Integer name) {
//
//
//}

    //    对象---》   值  "1"   值  java.lang.String
    public static synchronized DavidSinglton getInstance(String name,Integer value    ) {
        Log.i("david", "getInstance:服务获取成功 name: "+name+  "  value:  "+value);
        if (sInstance == null) {
            sInstance = new DavidSinglton();
        }
        return sInstance;
    }

    public UserInfo getUserInfo() {
        return userInfo;
    }


    public void setUserInfo(UserInfo userInfo) {
        this.userInfo = userInfo;
    }
}
