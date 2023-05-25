package com.example.ipclib.core;

import android.text.TextUtils;
import android.util.Log;

import com.example.ipclib.DavidServiceManager;
import com.google.gson.Gson;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class DavidBinderProxy implements InvocationHandler {
    private Class clazz;

    private static final Gson GSON = new Gson();
    public DavidBinderProxy( Class clazz) {
        this.clazz = clazz;
    }
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        Log.i("david", "invoke: "+method.getName());
//        接下来
        String data = DavidBinderIPC.getDefault().sendRequest(clazz, method,
                args, DavidServiceManager.TYPE_INVOKE);
        if (!TextUtils.isEmpty(data)) {
            Object object= GSON.fromJson(data, method.getReturnType());
            return object;
        }
        return null;
    }
}
