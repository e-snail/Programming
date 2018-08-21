//
// Created by WuYongbo on 17/3/14.
//

#include <iostream>
#include "MyClass.h"

using namespace std;

void getArrayLength(int array[]) {
	/**
	 * 在下式中array作为指针
	 */
    int length = sizeof(array) / sizeof(array[0]);
    cout <<"getArrayLength " << length <<endl;
}

int main(int argc, char** argv) {

    /**
     * Oppos 1
     *
     * 数组降阶问题，当数组作为参数传递时，会退化为指针
     * 参考 http://blog.csdn.net/jiangxinyu/article/details/7767065
     */
    cout <<"OOPS 1!" <<endl;

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
    cout <<"OOPS 2!" <<endl;

    MyClass *myClass = NULL;

    myClass->Test_Fun1();  //won't crash
    myClass->Test_Fun2();  //won't crash
    //myClass->Test_Fun3();  //crash !
    //myClass->Test_Fun4();  //crash !

    cout <<endl;

    /**
     * Opps 3 
     *
     * 理解sizeof 和 strlen
     */
    cout <<"OOPS 3!" <<endl;

    	/**
	 * 以下输出值为1 : ISO C++标准规定, ’a’叫做字符字面量(character literal)，被看成是char型，所以占1字节。
	 * 如果在C语言中, sizeof('a') == 4
	 * 	C99标准的规定，’a’叫做整型字符常量(integer character constant)，被看成是int型，所以在32位机器上占4字节。
	 */
    cout << "sizeof \'a\'=" <<sizeof('a') <<endl;

    	/**
	 * 指针变量占的位数 总是等于 地址总线的长度, 也就是CPU位数
	 * 而sizeof (int) 始终不变
	 */
    cout <<"sizeof (int *) = " <<sizeof(int*) <<endl; 
    cout <<"sizeof (int) = " <<sizeof(int) <<endl; 

    cout <<endl;

    return 0;
}
