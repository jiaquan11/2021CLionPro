//
// Created by jiaquanxia on 2021/6/28.
//
#include <iostream>

using namespace std;

//类模板的应用
//数组类模板
template<class T>
class MyArray {
public:
    MyArray(int capacity) {
        this->mCapacity = capacity;
        this->mSize = 0;
        this->pAddr = new T[this->mCapacity];
    }

    //拷贝构造
    MyArray(const MyArray &myarray) {
        this->mCapacity = myarray.mCapacity;
        this->mSize = myarray.mSize;
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++) {
            this->pAddr[i] = myarray[i];
        }
    }

    //重载=号操作符
    MyArray &operator=(const MyArray &myarray) {
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
            this->mCapacity = 0;
            this->mSize = 0;
        }

        this->mCapacity = myarray.mCapacity;
        this->mSize = myarray.mSize;
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++) {
            this->pAddr[i] = myarray[i];
        }

        return *this;
    }

    //重载[]操作符
    T &operator[](int index) {
        return this->pAddr[index];
    }

    //尾插法添加元素
    void Push_Back(T val) {
        if (this->mSize == this->mCapacity) {
            return;
        }
        this->pAddr[this->mSize] = val;
        this->mSize++;
    }

    //尾删法删除数组尾部元素
    void Remove_Back() {
        this->mSize--;
    }

    //指定位置删除
    void Remove_Position(int pos) {
        if (pos < 0 || pos > this->mSize) {
            return;
        }

        //移动元素
        for (int i = pos; i < this->mSize - 1; i++) {
            this->pAddr[i] = this->pAddr[i + 1];
        }
    }

    //析构函数
    ~MyArray() {
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
    }

public:
    T *pAddr;
    int mCapacity;
    int mSize;
};

//打印函数
void PrintMyArrayInt(MyArray<int> &arr) {
    for (int i = 0; i < arr.mSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//测试 存储基础数据类型
void test01() {
    MyArray<int> arr(20);
    for (int i = 0; i < 20; i++) {
        arr.Push_Back(i + 1);
    }
    PrintMyArrayInt(arr);
}


//测试 存储自定义数据类型
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

//打印函数
void PrintMyArrayPerson(MyArray<Person> &arr) {
    for (int i = 0; i < arr.mSize; i++) {
        cout << "Name:" << arr[i].mName << " Age:" << arr[i].mAge << endl;
    }
}

void test02() {
    MyArray<Person> myarray(20);
    for (int i = 0; i < 20; i++) {
        Person myperson("aaa", i + 20);
        myarray.Push_Back(myperson);
    }
    PrintMyArrayPerson(myarray);
}

int main() {
    test01();

    test02();
    return 0;
}