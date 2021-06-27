//
// Created by jiaquanxia on 2021/6/27.
//
#include <iostream>

using namespace std;

/**
 * 类模板
 */
//类模板
template<class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->mName = name;
        this->mAge = age;
    }

    void PrintPerson() {
        cout << "Name:" << this->mName << " Age:" << this->mAge << endl;
    }

public:
    NameType mName;
    AgeType mAge;
};

void test01() {
    //记住：类模板只能显式指定类型，不能自动类型推导
    Person<string, int> p("John", 30);
    p.PrintPerson();
}

//类模板做函数参数
void DoBussiness(Person<string,int>& p){
    p.mAge += 20;
    p.mName += "_vip";
    p.PrintPerson();
}

int main() {
    test01();

    Person<string, int> p("Henny", 50);
    DoBussiness(p);
    return 0;
}

