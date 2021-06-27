//
// Created by jiaquanxia on 2021/6/27.
//

#include <iostream>

using namespace std;

//函数模板不允许自动类型转化
//普通函数能够自动进行类型转化
//函数模板
template<class T>
T MyPlus(T a, T b) {
    cout << "T MyPlus" << endl;
    T ret = a + b;
    return ret;
}

//普通函数
int MyPlus(int a, char b) {
    cout << "normal MyPlus" << endl;
    int ret = a + b;
    return ret;
}

void test01() {
    int a = 10;
    char b = 'a';

    //调用函数模板，严格匹配类型
    MyPlus(a, a);
    MyPlus(b, b);

    //调用普通函数
    MyPlus(a, b);
    //调用普通函数  普通函数可以隐式类型转换
    MyPlus(b, a);

    //结论：
    //函数模板不允许自动类型转换，必须严格匹配类型
    //普通函数可以进行自动类型转换
}


//-------------------------------------------------------
//函数模板和普通函数在一起调用规则
//函数模板可以像普通函数那样可以被重载
//c++编译器优先考虑普通函数
//如果函数模板可以产生一个更好的匹配，那么选择模板
//        可以通过空模板实参列表的语法限定编译器只能通过模板匹配
//函数模板
template<class T>
T MyPlus02(T a, T b) {
    cout<<"T MyPlus02"<<endl;
    T ret = a + b;
    return ret;
}

//普通函数
int MyPlus02(int a, int b) {
    cout<<"normal MyPlus02"<<endl;
    int ret = a + b;
    return ret;
}

void test02() {
    int a = 10;
    int b = 20;
    char c = 'a';
    char d = 'b';
    //如果函数模板和普通函数都能匹配，c++编译器优先考虑普通函数
    cout << MyPlus02(a, b) << endl;
    //如果我必须要调用函数模板,那么怎么办?
    cout << MyPlus02<>(a, b) << endl;
    //此时普通函数也可以匹配，因为普通函数可以自动类型转换
    //但是此时函数模板能够有更好的匹配
    //如果函数模板可以产生一个更好的匹配，那么选择模板
    cout << MyPlus02(c, d)<<endl;
}

//函数模板重载
template<class T>
T MyPlus02(T a, T b, T c) {
    T ret = a + b + c;
    return ret;
}

void test03() {
    int a = 10;
    int b = 20;
    int c = 30;
    cout << MyPlus02(a, b, c) << endl;
    //如果函数模板和普通函数都能匹配，c++编译器优先考虑普通函数
}

int main() {
    test01();

    test02();
    test03();
    return 0;
}
/*
模板机制剖析
思考:为什么函数模板可以和普通函数放在一起?c++编译器是如何实现函数模板机制的？函数模板机制结论：
编译器并不是把函数模板处理成能够处理任何类型的函数
函数模板通过具体类型产生不同的函数
编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译。
编译器根据函数的调用情况，产生具体函数，这个具体函数根据类型产生。
 */