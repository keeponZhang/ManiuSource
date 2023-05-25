package com.example.ipclib.cache;

import com.example.ipclib.bean.RequestBean;
import com.example.ipclib.bean.RequestParamter;

import java.lang.reflect.Method;
import java.util.concurrent.ConcurrentHashMap;

public class CacheCenter {
//类名 ------Class
    private   ConcurrentHashMap<String, Class<?>> mClassMap;
//类名--》 对外能够提供服务的方法
    private   ConcurrentHashMap<String, ConcurrentHashMap<String, Method>> mAllMethodMap;

    private   ConcurrentHashMap<String, Object> mInstanceObjectMap;
    private static final CacheCenter ourInstance = new CacheCenter();
    public static CacheCenter getInstance() {

        return ourInstance;
    }

    public void putObject(String className, Object instance) {
        mInstanceObjectMap.put(className, instance);
    }
    public Object getObject(String className) {
        return mInstanceObjectMap.get(className);
    }

    private CacheCenter() {
        mClassMap = new ConcurrentHashMap<String, Class<?>>();
        mAllMethodMap = new ConcurrentHashMap<String, ConcurrentHashMap<String, Method>>();
        mInstanceObjectMap = new ConcurrentHashMap<String, Object>();
    }
    public void register(Class clazz) {
//注册class
        registerClass(clazz);
        registerMethod(clazz);
    }
    private void registerClass(Class clazz) {
        String className = clazz.getName();
        mClassMap.put(className, clazz);
    }

    private void registerMethod(Class clazz) {
        Method[] methods = clazz.getDeclaredMethods();
        for (Method method : methods) {
            ConcurrentHashMap<String, Method> map = mAllMethodMap.get(clazz.getName());
            if (map == null) {
                map = new ConcurrentHashMap<String, Method>();
                mAllMethodMap.put(clazz.getName(),map);
            }
//            getInstance-String-String
            String key = getMethodParameters(method);
            map.put(key, method);
        }
    }
    public Method getMethod(RequestBean requestBean) {

        ConcurrentHashMap<String, Method> map = mAllMethodMap.get(requestBean.getClassName());
        if (map != null) {
//            java 可以重载

            String key = getMethodParameters(requestBean);
            return map.get(key);

        }
        return null;

    }

    public Class<?> getClassType(String parameterClassName) {
        try {
            Class clazz = Class.forName(parameterClassName);
            return clazz;
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }
    public static String getMethodParameters(RequestBean requestBean) {
        StringBuilder result = new StringBuilder();
        result.append(requestBean.getMethodName());
        if (requestBean.getRequestParamters() == null || requestBean.getRequestParamters().length == 0) {
            return result.toString();
        }
        int length = requestBean.getRequestParamters().length;
        RequestParamter[] requestParamters=requestBean.getRequestParamters();
        for (int i = 0; i < length; ++i) {
            result.append("-").append(requestParamters[i].getParameterClassName());
        }
        return result.toString();
    }

    public static String getMethodParameters(Method method) {
        //        方法签名
        StringBuilder result = new StringBuilder();
        result.append(method.getName());
        Class<?>[] classes=method.getParameterTypes();
        int length = classes.length;
        if (length == 0) {
            return result.toString();
        }
        for (int i = 0; i < length; ++i) {
            result.append("-").append(classes[i].getName());
        }
        return result.toString();
    }

}
