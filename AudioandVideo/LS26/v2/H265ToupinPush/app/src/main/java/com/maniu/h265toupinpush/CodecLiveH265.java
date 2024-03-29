package com.maniu.h265toupinpush;

import android.Manifest;
import android.content.pm.PackageManager;
import android.hardware.display.DisplayManager;
import android.hardware.display.VirtualDisplay;
import android.media.MediaCodec;
import android.media.MediaCodecInfo;
import android.media.MediaFormat;
import android.media.projection.MediaProjection;
import android.os.Build;
import android.os.Environment;
import android.util.Log;
import android.view.Surface;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;

import static android.media.MediaFormat.KEY_BIT_RATE;
import static android.media.MediaFormat.KEY_FRAME_RATE;
import static android.media.MediaFormat.KEY_I_FRAME_INTERVAL;

public class CodecLiveH265 extends Thread {

    private static final String TAG = "David";
    //    yuv数据   FFmpeg 牛逼多了  编码工具
    private MediaCodec mediaCodec;

    private int width = 720;
    private int height = 1280;
    //    录屏
    private MediaProjection mediaProjection;
    VirtualDisplay virtualDisplay;
    private SocketLive socketLive;

    public CodecLiveH265(SocketLive socketLive, MediaProjection mediaProjection) {
        this.mediaProjection = mediaProjection;
        this.socketLive = socketLive;
    }

    public void startLive() {
        try {
            //            mediacodec  中间联系人      dsp芯片   帧
            MediaFormat format = MediaFormat.createVideoFormat(MediaFormat.MIMETYPE_VIDEO_HEVC, width, height);
            format.setInteger(MediaFormat.KEY_COLOR_FORMAT, MediaCodecInfo.CodecCapabilities.COLOR_FormatSurface);
            format.setInteger(KEY_BIT_RATE, width * height);
            format.setInteger(KEY_FRAME_RATE, 20);
            format.setInteger(KEY_I_FRAME_INTERVAL, 1);
            mediaCodec = MediaCodec.createEncoderByType("video/hevc");
            mediaCodec.configure(format, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE);
            Surface surface = mediaCodec.createInputSurface();
            //创建场地
            virtualDisplay = mediaProjection.createVirtualDisplay(
                "-display",
                width, height, 1,
                DisplayManager.VIRTUAL_DISPLAY_FLAG_PUBLIC, surface, null, null);

        } catch (IOException e) {
            e.printStackTrace();
        }


        start();
    }

    @Override
    public void run() {
        mediaCodec.start();
        MediaCodec.BufferInfo bufferInfo = new MediaCodec.BufferInfo();
        while (true) {
            //            ByteBuffer byteBuffer
            //查询索引

            try {
                int outputBufferId = mediaCodec.dequeueOutputBuffer(bufferInfo, 10000);
                if (outputBufferId >= 0) {
                    // 编码好的H265的数据
                    ByteBuffer byteBuffer = mediaCodec.getOutputBuffer(outputBufferId);
                    // byte[] outData = new byte[bufferInfo.size];
                    // byteBuffer.get(outData);
                    //以字符串的方式写入
                    //  writeContent(outData);
                    ////写成 文件  我们就能够播放起来
                    //  writeBytes(outData);
                    dealFrame(byteBuffer, bufferInfo);

                    mediaCodec.releaseOutputBuffer(outputBufferId, false);
                }
            } catch (Exception e) {
                e.printStackTrace();
                break;
            }

        }
    }

    public static final int NAL_I = 19;
    public static final int NAL_VPS = 32;
    private byte[] vps_sps_pps_buf;

    private void dealFrame(ByteBuffer bb, MediaCodec.BufferInfo bufferInfo) {
        int offset = 4;
        if (bb.get(2) == 0x01) {
            offset = 3;
        }
        int type = (bb.get(offset) & 0x7E) >> 1;
        if (type == NAL_VPS) {
            vps_sps_pps_buf = new byte[bufferInfo.size];
            //放到数组
            bb.get(vps_sps_pps_buf);
        } else if (type == NAL_I) {

            final byte[] bytes = new byte[bufferInfo.size];
            bb.get(bytes);

            byte[] newBuf = new byte[vps_sps_pps_buf.length + bytes.length];
            System.arraycopy(vps_sps_pps_buf, 0, newBuf, 0, vps_sps_pps_buf.length);
            System.arraycopy(bytes, 0, newBuf, vps_sps_pps_buf.length, bytes.length);
            this.socketLive.sendData(newBuf);
        } else {
            final byte[] bytes = new byte[bufferInfo.size];
            bb.get(bytes);
            this.socketLive.sendData(bytes);
            Log.v(TAG, "视频数据  " + Arrays.toString(bytes));
        }

    }

    public void writeBytes(byte[] array) {
        FileOutputStream writer = null;
        try {
            // 打开一个写文件器，构造函数中的第二个参数true表示以追加形式写文件
            writer = new FileOutputStream(Environment.getExternalStorageDirectory() + "/codec.h265", true);
            writer.write(array);
            writer.write('\n');


        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (writer != null) {
                    writer.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public String writeContent(byte[] array) {
        char[] HEX_CHAR_TABLE = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
        };
        StringBuilder sb = new StringBuilder();
        for (byte b : array) {
            sb.append(HEX_CHAR_TABLE[(b & 0xf0) >> 4]);
            sb.append(HEX_CHAR_TABLE[b & 0x0f]);
        }
        Log.i(TAG, "writeContent: " + sb.toString());
        FileWriter writer = null;
        try {
            // 打开一个写文件器，构造函数中的第二个参数true表示以追加形式写文件
            writer = new FileWriter(Environment.getExternalStorageDirectory() + "/codecH265.txt", true);
            writer.write(sb.toString());
            writer.write("\n");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (writer != null) {
                    writer.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return sb.toString();
    }
}
