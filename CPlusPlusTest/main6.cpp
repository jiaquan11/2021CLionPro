//
// Created by jiaquanxia on 2021/6/28.
//
#include <iostream>

using namespace std;

/*
 * C++类型转换
 * */
/*
 静态转换(static_cast)
用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
用于基本数据类型之间的转换，如把int转换成char，把char转换成int。这种转换的安全性也要开发人员来保证。
*/
class Animal01 {
};

class Dog01 : public Animal01 {
};

class Other01 {
};

//基础数据类型转换
void test0101() {
    char a = 'a';
    double b = static_cast<double>(a);
}

//继承关系指针互相转换
void test0102() {
    //继承关系指针转换
    Animal01 *animal01 = NULL;
    Dog01 *dog01 = NULL;
    //子类指针转成父类指针,安全
    Animal01 *animal02 = static_cast<Animal01 *>(dog01);
    //父类指针转成子类指针，不安全
    Dog01 *dog02 = static_cast<Dog01 *>(animal01);
}

//继承关系引用相互转换
void test0103() {
    Animal01 ani_ref;
    Dog01 dog_ref;
    //继承关系指针转换
    Animal01 &animal01 = ani_ref;
    Dog01 &dog01 = dog_ref;
    //子类指针转成父类指针,安全
    Animal01 &animal02 = static_cast<Animal01 &>(dog01);
    //父类指针转成子类指针，不安全
    Dog01 &dog02 = static_cast<Dog01 &>(animal01);
}

//无继承关系指针转换
void test0104() {
    Animal01 *animal01 = NULL;
    Other01 *other01 = NULL;

    //转换失败
    //Animal01* animal02 = static_cast<Animal01*>(other01);
}

//--------------------------------------------------------------
//动态转换(dynamic_cast)
//dynamic_cast主要用于类层次间的上行转换和下行转换；
//在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；
//在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全；
class Animal02 {
public:
    virtual void ShowName() = 0;
};

class Dog02 : public Animal02 {
    virtual void ShowName() {
        cout << "I am a dog!" << endl;
    }
};

class Other02 {
public:
    void PrintSomething() {
        cout << "我是其他类!" << endl;
    }
};

//普通类型转换
void test0201() {
    //不支持基础数据类型
    int a = 10;
    //double a = dynamic_cast<double>(a);
}

//继承关系指针
void test0202() {
    Animal02 *animal01 = NULL;
    Dog02 *dog01 = new Dog02;

    //子类指针转换成父类指针 可以
    Animal02 *animal02 = dynamic_cast<Animal02 *>(dog01);
    animal02->ShowName();
    //父类指针转换成子类指针 不可以
    //Dog* dog02 = dynamic_cast<Dog*>(animal01);
}

//继承关系引用
void test0203() {
    Dog02 dog_ref;
    Dog02 &dog01 = dog_ref;

    //子类引用转换成父类引用 可以
    Animal02 &animal02 = dynamic_cast<Animal02 &>(dog01);
    animal02.ShowName();
}

//无继承关系指针转换
void test0204() {
    Animal02 *animal01 = NULL;
    Other02 *other = NULL;

    //不可以
    //Animal* animal02 = dynamic_cast<Animal*>(other);
}

//-----------------------------------------------------------------------
//常量转换(const_cast)
//该运算符用来修改类型的const属性。。
//常量指针被转化成非常量指针，并且仍然指向原来的对象；
//常量引用被转换成非常量引用，并且仍然指向原来的对象；
//注意:不能直接对非指针和非引用的变量使用const_cast操作符去直接移除它的const.
//常量指针转换成非常量指针
class Person {
public:
    Person() {}

    Person(string name, int age) {
        this->mName = name;
        this->mAge = age;
    }

public:
    string mName;
    int mAge;
};

void test0301() {
    //给指针增加const
    int *p = new int;
    Person *person = new Person;
    const int *const_p = const_cast<const int *>(p);
    const Person *const_person = const_cast<const Person *>(person);

    delete person;
    delete p;

    //去掉const
    const Person *p2 = new Person;
    Person *p3 = const_cast<Person *>(p2);
}

//常量引用转换成非常量引用
void test0302() {
    int a = 10;
    int &p_ref = a;
    Person person;
    Person &person_ref = person;

    const int &const_b = const_cast<const int &>(p_ref);
    const Person &const_person = const_cast<const Person &>(person_ref);
}

/*
重新解释转换(reinterpret_cast)。。。。。
这是最不安全的一种转换机制，最有可能出问题。
主要用于将一种数据类型从一种类型转换为另一种类型。它可以将一个指针转换成一个整数，也可以将一个整数转换成一个指针.
 */

int main() {

    return 0;
}
