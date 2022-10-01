#include <iostream>

using namespace std;
int main1(){
     int d;
//     struct 20
     printf("d %d", d);
//     <<
//    int a = 1 << 2;
//    printf("d %d", a); //<<插入  endl 实时刷新  flush（）
    cout << "Hello, World!"<<"daivd"<<endl;
    cout << "Hello, World!"<<endl;
    cout << "Hello, World!"<<endl;
    cout << "this is"
         << " c ++"
         << "program"<<endl;


    cout << "please";
    cout<<"input";
    cout<<endl;
    int a, b, c ;

    cin>>a>>b>>c>>d;

    cout<<a  //注意没有分号
        << b
        <<c
        <<endl;
//
//cin>>输入

    return 0;

}

int main2(){
    cout << "please";
    cout<<"input";
    cout<<endl;
    int a, b, c,d ;

    cin>>a>>b>>c>>d;
    //输入要对应类型
    cout<<a  //注意没有分号
        << b
        <<c
        <<d
        <<endl;


}


int main3(){
    char c1,c2;int a;
    float b;
    cin>>c1>>c2>>a>>b;
    cout   //注意没有分号
        << c1
        <<c2
        <<a
        <<b
        <<endl;
}

int main(){
    //main1();
    //main2();
    main3();
}
