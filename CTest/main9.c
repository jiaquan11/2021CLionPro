//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>

#pragma pack(4)

typedef struct _STUDENT {
    int a;
    char b;
    double c;
    float d;
} Student;

typedef struct _STUDENT2 {
    char a;
    Student b;
    double c;
} Student2;

void test01() {
    //Student
    //a从偏移量0位置开始存储
    //b从4位置开始存储
    //c从8位置开始存储
    //d从12位置开存储
    //所以Student内部对齐之后的大小为20 ，整体对齐，整体为最大类型的整数倍 也就是8的整数倍 为24

    printf("sizeof Student:%d\n", sizeof(Student));

    //Student2
    //a从偏移量为0位置开始 8
    //b从偏移量为Student内部最大成员整数倍开始，也就是8开始 24
    //c从8的整数倍地方开始,也就是32开始
    //所以结构体Sutdnet2内部对齐之后的大小为：40 ， 由于结构体中最大成员为8，必须为8的整数倍 所以大小为40
    printf("sizeof Student2:%d\n", sizeof(Student2));
}

int main() {
    test01();
    return 0;
}