//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 字符串反转模型
 * */
void reverse_string(char *str) {
    if (str == NULL) {
        return;
    }

    int begin = 0;
    int end = strlen(str) - 1;

    while (begin < end) {
        //交换两个字符元素
        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;

        begin++;
        end--;
    }
}

void test() {
    char str[] = "abcdefghijklmn";
    printf("str:%s\n", str);
    reverse_string(str);
    printf("str:%s\n", str);
}

int main() {
    test();
    return 0;
}