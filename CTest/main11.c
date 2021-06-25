//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *函数指针作为函数参数
 */
//函数指针是指向函数的指针；
//指针函数是返回类型为指针的函数；

//加法计算器
int plus(int a,int b){
    return a + b;
}

//减法计算器
int minus(int a,int b){
    return a - b;
}

//计算器
#if 0
int caculator(int a,int b,int(*func)(int,int)){
	return func(a, b);
}
#else
typedef int(*FUNC_POINTER)(int, int);
int caculator(int a, int b, FUNC_POINTER func){
    return func(a, b);
}
#endif

int main() {
    FUNC_POINTER p = plus;

    int ret = caculator(10, 20, p);
    printf("ret is %d\n", ret);
    return 0;
}