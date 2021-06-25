//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(){
    //1. 格式化字符串
    char buf[1024] = { 0 };
    memset(buf, 0, 1024);

    int num = 200;
    sprintf(buf, "%d", num);
    printf("buf:%s\n", buf);
}

int main() {
    test();
    return 0;
}