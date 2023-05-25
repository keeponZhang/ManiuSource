package com.example.maniuipc;

import com.example.ipclib.ClassId;

@ClassId("com.example.maniuipc.DowloadSinglton")
public interface IDowloadSinglton {
    String download(String url);
}
