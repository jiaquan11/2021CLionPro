//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * sprintf格式化的使用
 * */
void test(){
    //1. 格式化字符串
    char buf[1024] = { 0 };
    memset(buf, 0, 1024);

    int num = 200;
    sprintf(buf, "%d", num);
    printf("buf:%s\n", buf);

    //设置宽度 右对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%8d", num);
    printf("buf:%s\n", buf);

    //设置宽度 左对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%-8d", num);
    printf("buf:%s\n", buf);
}

int main() {
    test();
    return 0;
}