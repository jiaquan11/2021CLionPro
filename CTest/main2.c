//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * sscanf的使用
 */
//1. 跳过数据
void test01(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //匹配第一个字符是否是数字，如果是，则跳过
    //如果不是则停止匹配
    sscanf("123456aaaa", "%*d%s", buf);
    printf("buf:%s\n",buf);
}

//2. 读取指定宽度数据
void test02(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    sscanf("123456aaaa", "%7s", buf);
    printf("buf:%s\n", buf);
}

//3. 匹配a-z中任意字符
void test03(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符，判断字符是否是a-z中的字符，如果是匹配
    //如果不是停止匹配
    sscanf("abcdefg123456", "%[a-z]", buf);
    printf("buf:%s\n", buf);
}

//4. 匹配aBc中的任何一个
void test04(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("abcdefg123456", "%[aBc]", buf);
    printf("buf:%s\n", buf);
}

//5. 匹配非a的任意字符
void test05(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("bcdefag123456", "%[^a]", buf);
    printf("buf:%s\n", buf);
}

//6. 匹配非a-z中的任意字符
void test06(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("123456ABCDbcdefag", "%[^a-z]", buf);
    printf("buf:%s\n", buf);
}

int main(){
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    return 0;
}
//    结果输出:
//buf:aaaa
//buf:123456a
//buf:abcdefg
//buf:a
//buf:bcdef
//buf:123456ABCD

