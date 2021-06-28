//
// Created by jiaquanxia on 2021/6/28.
//
#include <iostream>

using namespace std;

/*
 * 类模板派生普通类
 * */
//类模板
template<class T>
class MyClass01 {
public:
    MyClass01(T property) {
        this->mProperty = property;
    }

public:
    T mProperty;
};

//子类实例化的时候需要具体化的父类，子类需要知道父类的具体类型是什么样的
//这样c++编译器才能知道给子类分配多少内存

//普通派生类
class SubClass : public MyClass01<int> {
public:
    SubClass(int b) : MyClass01<int>(20) {
        this->mB = b;
    }

public:
    int mB;
};

//------------------------------------------------------------------
/*
 * 类模板派生类模板
 * */
//父类类模板
template<class T>
class MyClass02 {
public:
    MyClass02(T property) {
        this->mProperty = property;
    }

public:
    T mProperty;
};

//子类类模板
template<class T>
class SubClass02 : public MyClass02<T> {
public:
    SubClass02(T b) : MyClass02<T>(b) {
        this->mB = b;
    }

public:
    T mB;
};

//------------------------------------------------------------------
//类模板类内实现
//类模板类内实现  函数体在类模板的内部实现
template<class T>
class Person01 {
public:
    //重载左移操作符
    friend ostream &operator<<(ostream &out, Person01 &p) {
        out << p.mProperty << endl;
        return out;
    }

    //重载普通友元
    friend void FriendPerson(Person01 &p) {
        cout << p.mProperty << endl;
    }

    Person01(T property) {
        this->mProperty = property;
    }

    void PrintPerson() {
        cout << this->mProperty << endl;
    }

private:
    T mProperty;
};

void test() {
    Person01<int> p(10);
    //调用类的成员函数打印
    p.PrintPerson();
    //重载左移操作符 友元函数
    cout << p;
    //普通友元函数
    FriendPerson(p);
}

//--------------------------------------------------------------------------------
//类模板类外实现
//类模板类内实现  函数体在类模板的内部实现
template<class T>
class Person02 {
public:
    //重载左移操作符
    template<class T1>
    friend ostream &operator<<(ostream &out, Person02<T1> &p);

    //重载普通友元
    template<class T2>
    friend void FriendPerson(Person02<T2> &p);

    //构造函数
    Person02(T property);

    //成员函数
    void PrintPerson();

private:
    T mProperty;
};

//----------类外实现--------------------
template<class T>
Person02<T>::Person02(T property) {
    this->mProperty = property;
}

template<class T>
void Person02<T>::PrintPerson() {
    cout << this->mProperty << endl;
}

//重载左移操作符
template<class T>
ostream &operator<<(ostream &out, Person02<T> &p) {
    out << p.mProperty << endl;
    return out;
}

//重载普通友元
template<class T>
void FriendPerson(Person02<T> &p) {
    cout << p.mProperty << endl;
}

int main() {
    test();

    //编译通过，那么咱们来用用
    Person02<int> p(20);
    //调用成员方法 编译通过 执行通过
    p.PrintPerson();
    //调用普通友元函数 编译报错 无法解析的外部符号
    FriendPerson(p);
    //调用重载左移操作符 编译报错 无法解析的外部符号
    cout << p;
    return 0;
}