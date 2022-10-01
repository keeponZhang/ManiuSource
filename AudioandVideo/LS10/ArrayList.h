//
// Created by Administrator on 2020/11/12.
//

#ifndef LS10_ARRAYLIST_H
#define LS10_ARRAYLIST_H


class ArrayList {
public:
    ArrayList();
//    不能通过隐士调用
    explicit ArrayList(int capacity);
    ArrayList(const ArrayList &arrayList);
//    要是
// 析构函数
    ~ArrayList();
    void add(int val);

    void add(int val, int size);

    int get(int pos);

    void remove(int index);

    int getLength();
    bool isEmpty();
//    数组不够了 扩容机制
    void resize();

    void toString();

    void test();

private:
//    数组.length（）
    int size;
    int actulSize;
//    int arr[] ;//1    2   int *[]
    int *arr;//常量
};


#endif //LS10_ARRAYLIST_H
