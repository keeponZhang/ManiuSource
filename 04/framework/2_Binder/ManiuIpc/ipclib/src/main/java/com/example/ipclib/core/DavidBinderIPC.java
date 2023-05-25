package com.example.ipclib.core;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.text.TextUtils;

import com.example.ipclib.ClassId;
import com.example.ipclib.DavidBinderInterface;
import com.example.ipclib.DavidServiceManager;
import com.example.ipclib.bean.RequestBean;
import com.example.ipclib.bean.RequestParamter;
import com.example.ipclib.cache.CacheCenter;
import com.google.gson.Gson;

import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.net.HttpURLConnection;

public class DavidBinderIPC {
    HttpURLConnection httpURLConnection;
    DavidBinderInterface davidBinderInterface;
    private static final Gson GSON = new Gson();
//    -----------------------主进程---------------------------------
    CacheCenter cacheCenter = CacheCenter.getInstance();
    private static final DavidBinderIPC ourInstance = new DavidBinderIPC();

    public static DavidBinderIPC getDefault() {
        return ourInstance;
    }

    private Context sContext;

    public void init(Context context) {
        sContext = context.getApplicationContext();
    }

    //    服务注册
    public void register(Class<?> clazz) {
//        注册 交给 CacheCenter
        cacheCenter.register(clazz);


    }


    //    ------------------------------B进程-----------------------------------
    public <T> T getInstance(Class<T> clazz, Object... parameters) {
//        通知主进程
//        httpURLConnection.connect();

//        组织请求头  主进程  服务对象 在主进程获取到了 没有办法返回给你
        sendRequest(clazz, null, parameters,DavidServiceManager.TYPE_GET);
// 不需要    返回   我能够给你提供这些功能
//         动态    娃娃  张三  日本
//        张三 20:00
//         再返回给B进程
        return  getProxy(clazz);
    }

    private <T> T getProxy(Class<T> clazz) {
        ClassLoader classLoader = sContext.getClassLoader();
        return (T) Proxy.newProxyInstance(classLoader, new Class[]{clazz}, new DavidBinderProxy(clazz));
    }

    //B进程
    public <T> String sendRequest(Class<T> clazz, Method method, Object[] parameters, int type) {
        String className = clazz.getAnnotation(ClassId.class).value();
        String methodName = method == null ? "getInstance" : method.getName();

        RequestParamter[] requestParamters = null;
        if (parameters != null && parameters.length >0) {
            requestParamters = new RequestParamter[parameters.length];
            for (int i = 0; i < parameters.length; i++) {
                Object parameter = parameters[i];
                String parameterClassName = parameter.getClass().getName();
                String parameterValue =GSON.toJson(parameter);
                RequestParamter requestParamter = new RequestParamter(parameterClassName, parameterValue);
                requestParamters[i] = requestParamter;
            }
        }
//        javabean ---》json


        RequestBean requestBean = new RequestBean(type, className, methodName, requestParamters);
//请求头
        String request = GSON.toJson(requestBean);

//        做真正的请求
        String respoce = null;
        try {
              respoce= davidBinderInterface.reuqest(request);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
        return respoce;
    }
    //  开启服务
    public void open(Context context) {

        open(context, null);
    }

    public void open(Context context, String packageName) {
        init(context);
        bind(context.getApplicationContext(), packageName, DavidServiceManager.class);
    }

    public void bind(Context context, String packageName, Class<? extends DavidServiceManager> service) {

        Intent intent = null;
        if (TextUtils.isEmpty(packageName)) {
            intent = new Intent(context, service);
        }else {
            ComponentName component = new ComponentName(packageName, service.getName());
            intent = new Intent();
            intent.setComponent(component);
            intent.setAction(service.getName());
        }
        DavidServiceConnection davidServiceConnection = new DavidServiceConnection();
        context.bindService(intent, davidServiceConnection, Context.BIND_AUTO_CREATE);
    }

    private class DavidServiceConnection implements ServiceConnection {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            davidBinderInterface = DavidBinderInterface.Stub.asInterface(service);
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {

        }
    }
}