//
// Created by WuYongbo on 17/3/17.
//

#ifndef OPPS_MYCLASS_H
#define OPPS_MYCLASS_H

#include <iostream>

using namespace std;

class MyClass {

public:

    static void Test_Fun1(){ cout<<"Test_Fun1"<<endl; }

    void Test_Fun2(){ cout<<"Test_Fun2"<<endl; }

    void Test_Fun3(){ cout<<m_num<<endl; }

    virtual void Test_Fun4(){ cout<<"Test_Fun4"<<endl; }

public:
    int m_num;

};


#endif //OPPS_MYCLASS_H
