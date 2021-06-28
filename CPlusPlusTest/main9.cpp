//
// Created by jiaquanxia on 2021/6/28.
//
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/*
 * C++读写二进制文件操作
 * */
class Person {
public:
    Person(){

    }

    Person(char *name, int age) {
        strcpy(this->mName, name);
        this->mAge = age;
    }

public:
    char mName[64];
    int mAge;
};

int main() {
    char *fileName = "person.txt";
    //二进制模式读写文件
    //创建文件对象输出流
    std::ofstream osm(fileName, ios::out | ios::binary);

    Person p1("John", 33);
    Person p2("Edward", 34);

    //Person对象写入文件
    osm.write((const char *) &p1, sizeof(Person));
    osm.write((const char *) &p2, sizeof(Person));

    //关闭文件输出流
    osm.close();

    //从文件中读取对象数组
    ifstream ism(fileName, ios::in | ios::binary);
    if (!ism) {
        cout << "打开失败!" << endl;
    }

    Person p3;
    Person p4;

    ism.read((char *) &p3, sizeof(Person));
    ism.read((char *) &p4, sizeof(Person));

    cout << "Name:" << p3.mName << " Age:" << p3.mAge << endl;
    cout << "Age:" << p4.mName << " Age:" << p4.mAge << endl;

    //关闭文件输入流
    ism.close();
    return 0;
}
