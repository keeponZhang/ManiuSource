package com.maniu.bindermaniu;
//码牛A
//  开辟物理内存
//  虚拟地址---》 物理内存


//B 找到物理内存
//虚拟地址---》 物理内存
// 读取虚拟地址   A
public class ManiuBinder {
    static {
        System.loadLibrary("native-lib");
    }
    public native void write();
    public native String read();


}
