//
// Created by WuYongbo on 17/3/14.
//

#include <iostream>
#include "MyClass.h"

using namespace std;

void getArrayLength(int array[]) {
    int length = sizeof(array) / sizeof(int);
    cout <<"getArrayLength " << length <<endl;
}

int main(int argc, char** argv) {

    /**
     * Oppos 1
     *
     * 数组降阶问题，当数组作为参数传递时，会退化为指针
     * 参考 http://blog.csdn.net/jiangxinyu/article/details/7767065
     */
    cout <<"OPPS 1!" <<endl;

    int array[] = {1, 2, 3, 4};
    int length = sizeof(array) / sizeof(int);

    cout <<"array length " << length <<endl;

    getArrayLength(array);

    cout <<endl;

    /**
     * Opps 2
     *
     * 理解函数调用的实质，不要被表面上的语法所迷惑
     * http://blog.csdn.net/primeprime/article/details/50726918
     */
    cout <<"OPPS 2!" <<endl;

    MyClass *myClass = NULL;

    myClass->Test_Fun1();  //won't crash
    myClass->Test_Fun2();  //won't crash
    //myClass->Test_Fun3();  //crash !
    //myClass->Test_Fun4();  //crash !

    cout <<endl;

    return 0;
}