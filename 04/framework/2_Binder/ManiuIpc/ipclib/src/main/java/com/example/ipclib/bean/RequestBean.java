package com.example.ipclib.bean;

public class RequestBean {
    private String className;
    private String methodName;
// 1 实例化对象  2    调用 这个对象方法
    private int type;
    //参数  变化  数组  值   值类型   数值
    private RequestParamter[] requestParamters;

    public RequestBean() {
    }

    public RequestBean(int type, String className, String methodName, RequestParamter[] requestParamters) {
        this.type = type;
        this.className = className;
        this.methodName = methodName;
        this.requestParamters = requestParamters;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public String getMethodName() {
        return methodName;
    }

    public void setMethodName(String methodName) {
        this.methodName = methodName;
    }

    public RequestParamter[] getRequestParamters() {
        return requestParamters;
    }

    public void setRequestParamters(RequestParamter[] requestParamters) {
        this.requestParamters = requestParamters;
    }

}
