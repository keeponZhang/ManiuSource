#include <iostream>
class Student{
public:
    //类包含的变量
    char *name;
    int age;
    float score;
    void say(){
        printf("name %s age %d score %f\n",  name,  age,  score);
    }
};

int main(){
    class Student stu1;
    stu1.name = "xiaoming";
    stu1.age = 15;
    stu1.score = 92.5f;
    //调用类的成员函数
    stu1.say();
    return 0;
}


