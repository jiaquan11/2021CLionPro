//
// Created by jiaquanxia on 2021/6/28.
//
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

template<class T>
class Person {
public:
#if 1

    //重载左移操作符
    template<class T1>
    friend ostream &operator<<(ostream &out, Person<T1> &p);

    //重载普通友元
    template<class T2>
    friend void FriendPerson(Person<T2> &p);

#endif

    //构造函数
    Person(T property);

    //成员函数
    void PrintPerson();

private:
    T mProperty;
};

#endif
