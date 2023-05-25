package com.android.coordinatorLayout;


import java.io.File;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;

public class ReNameFile {

    // public static final String SPLASH_SLOAN_PNG = "【瑞客 论坛 www.ruike1.com】";
    // public static final String SPLASH_SLOAN_PNG = "【瑞客论坛 www.ruike1.com 】";
    // public static final String SPLASH_SLOAN_PNG = "【瑞客论坛 www.ruike1.com】";
    public static final String SPLASH_SLOAN_PNG = "【瑞客 论坛 www.ruike1.com】";
    public static final String  RENAME = "";

    public static void main(String[] args) {
        String filePath = "I:\\android逆向\\android逆向系统培训课程";
        File file = new File(filePath);
        printFileList(file);
    }

    public static void printFileList(File dirFile) {
        File current = dirFile;    //返回的必定是目录
        if (current == null || !current.exists()) {
            return;
        }
        if (current.isFile()) {
            judge(current);

        } else {
            File[] files = current.listFiles();
            for (File file : files) {
                if (file.isDirectory()) {
                    // System.out.println("[printFileList][dir]path:" + file.getPath());
                    printFileList(file);
                } else {
                    judge(file);
                }
            }
        }
    }

    private static void judge(File file) {
        boolean b = false;
        String name = file.getName();
         b = name.contains(SPLASH_SLOAN_PNG);
        if (b){
            String replace = name.replace(SPLASH_SLOAN_PNG, RENAME);
            String parentPath = file.getParentFile().getPath();
            File reNamefile = new File(parentPath, replace);

            System.out.println( "ReNameFile before="+name+"    ---after="+replace);
            file.renameTo(reNamefile);
        }else{
            System.out.println("不符合="+file.getPath());
        }
    }
}