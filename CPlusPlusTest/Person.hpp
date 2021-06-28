//
// Created by jiaquanxia on 2021/6/28.
//

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

template<class T>
Person<T>::Person(T property) {
    this->mProperty = property;
}

template<class T>
void Person<T>::PrintPerson() {
    cout << this->mProperty << endl;
}

#if 1

//重载左移操作符
template<class T>
ostream &operator<<(ostream &out, Person<T> &p) {
    out << p.mProperty << endl;
    return out;
}

//重载普通友元
template<class T>
void FriendPerson(Person<T> &p) {
    cout << p.mProperty << endl;
}

#endif