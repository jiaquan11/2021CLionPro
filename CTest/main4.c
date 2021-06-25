//
// Created by jiaquanxia on 2021/6/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *指针做函数参数，具备输入和输出特性：
 * 输入：主调函数分配内存
 * 输出：被调用函数分配内存
 */

//输入特性
void fun01(char *p /* in */) {
    //给p指向的内存区域拷贝内容
    strcpy(p, "abcddsgsd");
}

void test01(void) {
    //输入，主调函数分配内存
    char buf[100] = {0};
    fun01(buf);
    printf("buf  = %s\n", buf);
}

//输出特性
void fun02(char **p /* out */, int *len) {
    char *tmp = (char *) malloc(100);
    if (tmp == NULL) {
        return;
    }
    strcpy(tmp, "adlsgjldsk");

    //间接赋值
    *p = tmp;
    *len = strlen(tmp);
}

void test02(void) {
    //输出，被调用函数分配内存，地址传递
    char *p = NULL;
    int len = 0;
    fun02(&p, &len);
    if (p != NULL) {
        printf("p = %s, len = %d\n", p, len);
    }
}

int main() {
    test01();

    test02();
    return 0;
}