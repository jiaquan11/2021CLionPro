//
// Created by jiaquanxia on 2021/6/28.
//

#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

//�Զ����쳣��
class My_Out_Of_Range_Exception : public exception {
public:
    My_Out_Of_Range_Exception(char *str) {
        this->pError = new char[strlen(str) + 1];
        strcpy(this->pError, str);
    }

    virtual const char *what() const noexcept override {
        return this->pError;
    }

    virtual ~My_Out_Of_Range_Exception() {
        cout << "������������" << endl;
        if (this->pError != NULL) {
            delete this->pError;
        }
    }

public:
    char *pError;
};

class Person {
public:
    Person(int age) {
        if (age < 0 || age > 150) {
//            throw out_of_range("����Ӧ����0-150��֮��!");
            throw My_Out_Of_Range_Exception("����Ӧ����0-150��֮��!");
        }
    }

public:
    int mAge;
};

int main() {
//    try {
//        Person p(151);
//    }
//    catch (out_of_range &ex) {
//        cout << ex.what() << endl;
//    }

    try {
        Person p(151);
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
