#include <stdio.h>
//int[]   数组 常量
//int* getArray(){
//
//
//}
int main() {
    printf("Hello, World!\n");
//    指针   规则  晕头转
//
/**
 * 首先找到那个未定义的标识符，就是func，
 * 它的外面有一对圆括号，而且左边是一个*号，这说明func是一个指针，
然后跳出这个圆括号，先看右边，也是一个圆括号，这说明(*func)是一个函数，
 *而func是一个指向这类函数的指针，就是一个函数指针，

 *这类函数具有int*类型的形参，返回值类型是 int。

 */
    int (*func)(int *pInt);
/**
   func被一对括号包含，且左边有一个*号，说明func是一个指针，
   跳出括号，右边也有个括号，那么func是一个指向函数的指针，
   这类函数具有int *和int (*)(int*)这样的形参，返回值为int类型。
   再来看一看func的形参int (*f)(int*)，类似前面的解释，f也是一个函数指针，
   指向的函数具有int*类型的形参，返回值为int。
 */
//复杂  规则 本质
    int (*func1)(int *p, int (*f)(int *));


/**
 * func右边是一个[]运算符，说明func是一个具有5个元素的数组，
 * func的左边有一个*，说明func的元素是指针，要注意这里的*不是修饰 func的，
 * 而是修饰func[5]的，原因是[]运算符优先级比*高，func先跟[]结合，
 * 因此*修饰的是func[5]。跳出这个括号，看右边，也是一对圆括号，
 * 说明func数组的元素是函数类型的指针，它所指向的函数具有int*类型的形参，
 * 返回值类型为int。
 */
//    func2  本质 数组1     指针 2

    int (*func2[5])(int *pInt);

//func3   数组1   指针2
/**
 * func被一个圆括号包含，左边又有一个*，
 * 那么func是一个指针，跳出括号，
 * 右边是一个[]运算符号，说明func是一个指向数组的指针，
  现在往左看，左边有一个*号，说明这个数组的元素是指针，


    */
    int (*(*func3)[5])(int *pInt);

//输入  int * 地址变量  输出   int (*result)[5]
    int (*(*func4)(int *pInt))[5];
/**
 * func是一个返回值为具有5个int元素的数组的函数。
 * 但C语言的函数返回值不能为数组，这是因为如果允许函数返回值为数组，
 * 那么接收这个数组的内容的东西，也必须是一个数组，但C语言的数组名是一个右值，
 * 它不能作为左值来接收另一个数组，
 * 因此函数返回值不能为数组。
 */
//    int func8(void)[5];//非法

/**
 *
 func是一个具有5个元素的数组，这个数组的元素都是函数。
 这也是非法的，因为数组的元素除了类型必须一样外，
 每个元素所占用的内存空间也必须相同，显然函数是无法达到这个要求的，
 即使函数的类型一样，但函数所占用的空间通常是不相同的。
 */
//    int func9[5](void)
    int func10(void);
    return 0;
}
