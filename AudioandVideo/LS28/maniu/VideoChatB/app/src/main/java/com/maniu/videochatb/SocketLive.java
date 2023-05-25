package com.maniu.videochatb;

import android.util.Log;

import org.java_websocket.WebSocket;
import org.java_websocket.handshake.ClientHandshake;
import org.java_websocket.server.WebSocketServer;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
//音视频通话服务端
public class SocketLive {
    private static final String TAG = "David";
    private WebSocket webSocket;
    private SocketCallback socketCallback;
    public SocketLive(SocketCallback socketCallback ) {
        this.socketCallback = socketCallback;
    }

    public void start() {
        webSocketServer.start();
    }
    public void close() {
        try {
            webSocket.close();
            webSocketServer.stop();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
//   服务端
    private WebSocketServer webSocketServer = new WebSocketServer(new InetSocketAddress(60002)) {
        @Override
        public void onOpen(WebSocket webSocket, ClientHandshake clientHandshake) {
            SocketLive.this.webSocket = webSocket;
//            自定义  json   字符串
//            webSocket.send();
        }

        @Override
        public void onClose(WebSocket webSocket, int i, String s, boolean b) {
            Log.i(TAG, "onClose: 关闭 socket ");
        }

        @Override
        public void onMessage(WebSocket webSocket, String s) {

        }

        @Override
        public void onMessage(WebSocket conn, ByteBuffer bytes) {
            Log.i(TAG, "消息长度  : " + bytes.remaining());
            byte[] buf = new byte[bytes.remaining()];
            bytes.get(buf);
            socketCallback.callBack(buf);
        }

        @Override
        public void onError(WebSocket webSocket, Exception e) {
            Log.i(TAG, "onError:  " + e.toString());
        }

        @Override
        public void onStart() {

        }
    };
    public void sendData(byte[] bytes) {
        if (webSocket != null && webSocket.isOpen()) {
            webSocket.send(bytes);
        }
    }
    public interface SocketCallback {
        void callBack(byte[] data);
    }
}
