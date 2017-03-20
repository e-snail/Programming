//
// Created by WuYongbo on 17/3/19.
//

#include "RBTNode.h"
#include <iostream>

using namespace std;

void RBTNode::nodeInfo() {
    cout <<(color == Black ? "BLACK" : "RED") << "  " << to_string(key) <<endl
         << " \t left " <<(left != NULL ? to_string(left->key) : "NULL") <<endl
         << " \t right " <<(right != NULL ? to_string(right->key) : "NULL")
         <<endl;
}
