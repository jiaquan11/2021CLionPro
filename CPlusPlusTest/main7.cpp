//
// Created by jiaquanxia on 2021/6/28.
//

#include <iostream>

using namespace std;

//异常基类
class AbstractException {
public:
    virtual void printError() = 0;
};

//目标空间为空异常
class TargetSpaceNullException : public AbstractException {
public:
    TargetSpaceNullException() {
        cout << "TargetSpaceNullException Constrctor!" << endl;
    }

    TargetSpaceNullException(const TargetSpaceNullException &) {
        cout << "TargetSpaceNullException Copy Constructor!" << endl;
    }

    virtual void printError() {
        cout << "Taget Space Null Exception!" << endl;
    }

    ~TargetSpaceNullException() {
        cout << "TargetSpaceNullException Destructor!" << endl;
    }
};

//源空间为空异常
class SourceSpaceNullException : public AbstractException {
public:
    SourceSpaceNullException() {
        cout << "SourceSpaceNullException Constrctor!" << endl;
    }

    SourceSpaceNullException(const SourceSpaceNullException &) {
        cout << "SourceSpaceNullException Copy Constructor!" << endl;
    }

    virtual void printError() {
        cout << "Source Space Null Exception!!" << endl;
    }

    ~SourceSpaceNullException() {
        cout << "SourceSpaceNullException Destructor!" << endl;
    }

    int a;
};

void Copy_String(char *dest, char *source) {
    if (dest == NULL) {
        throw TargetSpaceNullException();
    }

    if (source == NULL) {
        throw SourceSpaceNullException();
    }

    cout<<"Copy_String 1111"<<endl;
    while (*source != '0') {
        *dest = *source;
        dest++;
        source++;
    }
}

//元素方式
void test01() {
    //字符串拷贝
    char *sourceSpace = "abcdefgh";
    //目标空间
    char destSpace[1024] = {0};
    //拷贝
    try {
        Copy_String(destSpace, NULL);
    }
    catch (TargetSpaceNullException ex) {
        ex.printError();
    }
    catch (SourceSpaceNullException ex) {
        ex.printError();
    }

    cout << "destSpace:" << destSpace << endl;
}

//引用方式
void test02() {
    //字符串拷贝
    char *sourceSpace = "abcdefgh";
    //目标空间
    char destSpace[1024] = {0};
    //拷贝
    try {
        Copy_String(destSpace, NULL);
    }
    catch (TargetSpaceNullException &ex) {
        ex.printError();
    }
    catch (SourceSpaceNullException &ex) {
        ex.printError();
    }

    cout << "destSpace:" << destSpace << endl;
}

//指针方式
void test03() {
    //字符串拷贝
    char *sourceSpace = "abcdefgh";
    //目标空间
    char destSpace[1024] = {0};
    //拷贝
    try {
        Copy_String(destSpace, NULL);
    }
    catch (TargetSpaceNullException *ex) {
        ex->printError();

    }
    catch (SourceSpaceNullException *ex) {
        cout<<"test03 SourceSpaceNullException *ex"<<endl;
        ex->printError();
    }

    cout << "destSpace:" << destSpace << endl;
}

void test04() {
    //字符串拷贝
    char *sourceSpace = "abcdefgh";
    //目标空间
    char destSpace[1024] = {0};
    //拷贝
    try {
        Copy_String(destSpace, NULL);
    }
    catch (AbstractException &ex) {
        ex.printError();
    }

    cout << "destSpace:" << destSpace << endl;
}

int main() {
    test01();
    test02();
//    test03();//会崩溃
    test04();
//    SourceSpaceNullException ex11;
//    SourceSpaceNullException *ex = &ex11;
    return 0;
}