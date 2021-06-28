//
// Created by jiaquanxia on 2021/6/28.
//

#include <iostream>
#include <fstream>
using namespace std;

/**
 * C++对ASCII文件的读写操作
 */
int main(){
    char* sourceFileName = "./source.txt";
    char* targetFileName = "./target.txt";
    //创建文件输入流对象
    ifstream ism(sourceFileName, ios::in);
    //创建文件输出流对象
    ofstream osm(targetFileName,ios::out);

    if (!ism){
        cout << "文件打开失败!" << endl;
    }

    while (!ism.eof()){
        char buf[1024] = { 0 };
        ism.getline(buf,1024);
        cout << buf << endl;
        osm << buf << endl;
    }

    //关闭文件流对象
    ism.close();
    osm.close();
    return 0;
}