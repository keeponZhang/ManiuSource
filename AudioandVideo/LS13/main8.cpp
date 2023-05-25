#include <iostream>

using namespace std;

#include <string>
#include <string.h>
//泛型 这个说法  函数模板=泛型

//字符串
int main1() {
    printf("---------main1---------------\n");
//    显示调度
    string s1();
    string s2("Hello");
    cout << "data s2:  " << s2 << endl;

    //4个k组成
    string s3(4, 'k');
    cout << "data s3:  " << s3 << endl;
    //"123456".substring(1,4)
    string s4("123456", 1, 4);
    cout << "data s4:  " << s4 << endl;
    return 0;
}

int main2() {
    printf("---------main2---------------\n");
//    下面2个会报错，没有字符的构造函数
//    string s1('K');
//    string s2(123);

}

int main3() {
    printf("---------main3---------------\n");
    string s1("123");
    string s2("abc");
    s1.append(s2);
    cout << "data s1:  " << s1 << endl;
}

int main4() {
    printf("---------main4---------------\n");
//    c++的string是对象 ,封装了一个C字符串
    string s = "david";
    //这里是常量指针，指向的内容是常量（方法执行结束后，arr就被销毁了）
    const char *arr = s.c_str();//C++字符串转换为C字符串
//   *arr = "1q23"; 不允许

    printf("string arr: %s\n", arr);
    printf("string *(arr + 1): %c\n", *(arr + 1));
    printf("string *(arr + 2): %c\n", *(arr + 2));
}

int main5() {
    printf("---------main5---------------\n");

}

int main6() {
    printf("---------main6---------------\n");
    char c[20];
    string s = "maniu";
    //拷贝一份放到c，s被析构之后，c还能用
    strcpy(c, s.c_str());
}

int main7() {
    printf("---------main7---------------\n");
    //会在堆区开辟一个字符串数组
    string s1("123");
    string s2("maniu");
    s1.append(s2);
    cout << "data:  " << s1 << endl;
    s1.append(s2, 1, 3);//substring(1,3)
    cout << "data:  " << s1 << endl;
}

int main8() {
    printf("---------main8---------------\n");
    string s1("david"), s2("99");
    cout << "s1:  " << s1 << "   s2:  " << s2 << endl;
    string s3 = s1.substr(2, 2);
    cout << "s3:  " << s3 << "   s2:  " << s2 << endl;
}

int main9() {
    printf("---------main9---------------\n");
    string s1("david"), s2("99");
    cout << "s1:  " << s1 << "   s2:  " << s2 << endl;
//    引用
    s1.swap(s2);
    cout << "s1:  " << s1 << "   s2:  " << s2 << endl;
}

int main10() {
    printf("---------main10---------------\n");
    string s1("Real Steel");
    s1.erase(1, 3); //删除子串(1, 3)，此后 s1 = "R Steel"
    cout << "s1:  " << s1 << endl;
    s1.erase(5); //删除下标5及其后面的所有字符，此后 s1 = "R Ste"
    cout << "s1:  " << s1 << endl;
}

int main11() {
    printf("---------main11---------------\n");
    string s1("hello"),
            s2("hello, world");
    int n = s1.compare(s2);
    cout << "n:  " << n << endl;
//    比较长度
    n = s1.compare(0, 3, s2, 0, 1);


    cout << "n:  " << n << endl;
}

int main12() {
    printf("---------main12---------------\n");
}

int main13() {
    printf("---------main13---------------\n");
    string s1("Source Code");
    int n;
//     string::npos 类静态变量     失败  npos =-1
    if ((n = s1.find('u')) != -1) {
//        查找成功
        cout << "u " << n << endl;
        cout << s1.substr(n) << endl;
    }

    if ((n = s1.find('Source')) != -1) {
//        查找成功
        cout << "u " << n << endl;
        cout << s1.substr(n) << endl;
    }

}

int main14() {
    printf("---------main14---------------\n");
    string s1("Real Steel");
    s1.replace(1, 3, "123456", 2, 4);
    cout << "s1 " << s1 << endl;

    string s2("Harry Potter");

    s2.replace(2, 3, 5, '0');
    cout << "s2 " << s2 << endl;

    int n = s2.find("OOOOO");  //查找子串 "00000" 的位置，n=2
    n = 2;
    s2.replace(n, 0, "XXX");
    cout << "s2 " << s2 << endl;
}

int main15() {
    printf("---------main15---------------\n");
    //    后面用的比较多    string  ---内存
// 路径   url
//        string s1("Limitless"), s2("00");
//ArrayList.cpp  int  ->T
//布置的作业
//
};

int main() {
    //main1();
    //main2();
    //main3();
    main4();
    //main5();
    //main6();
    //main7();
    //main8();
    //main9();
    //main10();
    //main11();
    //main12();
    //main13();
    //main14();
    //main15();

}