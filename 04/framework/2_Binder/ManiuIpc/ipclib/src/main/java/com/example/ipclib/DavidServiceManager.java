package com.example.ipclib;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;

import androidx.annotation.Nullable;

import com.example.ipclib.bean.RequestBean;
import com.example.ipclib.bean.RequestParamter;
import com.example.ipclib.cache.CacheCenter;
import com.google.gson.Gson;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class DavidServiceManager extends Service {
    CacheCenter cacheCenter = CacheCenter.getInstance();
    //服务获取  实例化对象
    public static final int TYPE_GET = 1;
    //服务调用
    public static final int TYPE_INVOKE = 2;

    Gson gson = new Gson();
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {


        return new DavidBinderInterface.Stub() {
            @Override
            public String reuqest(String reuqest) throws RemoteException {
//                主进程 1    B进程  2
//                json
                RequestBean requestBean = gson.fromJson(reuqest, RequestBean.class);
                int type = requestBean.getType();
                switch (type) {
                    case TYPE_GET:
//                        缓存
                        Method method=cacheCenter.getMethod(requestBean);

                        Object[] parameters = makeParameterObject(requestBean);
                        if (method != null) {
                            try {
                                Object object= method.invoke(null, parameters);
                                if (object != null) {
                                    cacheCenter.putObject(requestBean.getClassName(), object);
                                }
                            } catch (IllegalAccessException e) {
                                e.printStackTrace();
                            } catch (InvocationTargetException e) {
                                e.printStackTrace();
                            }
                        }
                        break;
                    case TYPE_INVOKE:
                        Object object = cacheCenter.getObject(requestBean.getClassName());

                        Method tempMethod = cacheCenter.getMethod(requestBean);
                        Object[] mParameters = makeParameterObject(requestBean);
                        try {
                            Object result=tempMethod.invoke(object, mParameters);
                            String data = gson.toJson(result);
                            return data;
                        } catch (IllegalAccessException e) {
                            e.printStackTrace();
                        } catch (InvocationTargetException e) {
                            e.printStackTrace();
                        }

                        break;
                }
                return null;
            }
        };
    }
    private Object[] makeParameterObject(RequestBean requestBean) {

        Object[] mParameters = null;
        RequestParamter[] requestParamters = requestBean.getRequestParamters();
        if (requestParamters != null && requestParamters.length > 0) {
            mParameters = new Object[requestBean.getRequestParamters().length];
            for (int i = 0; i < requestParamters.length; i++) {
                RequestParamter requestParamter = requestParamters[i];
                Class<?> clazz = cacheCenter.getClassType(requestParamter.getParameterClassName());
//                    clazz   value  object
                mParameters[i] = gson.fromJson(requestParamter.getParameterValue(), clazz);
            }

        }else {
            mParameters = new Object[0];
        }
        return mParameters;
    }


}
