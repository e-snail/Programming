//
// Created by WuYongbo on 17/3/11.
//

#include "BTNode.h"

#include <iostream>

using namespace std;

BTNode::BTNode(int value) {

    this->value = value;
    this->leftChild = NULL;
    this->rightChild = NULL;

    //cout <<"BTNode Constructor" <<endl;
}

BTNode::BTNode(const BTNode &node) {
    //cout <<"BTNode copy Constructor" <<endl;

    this->value = node.value;
}

void BTNode::displayValue() {
    cout <<"displayValue " <<this->value <<endl;
}

BTNode::~BTNode() {
    //cout <<"BTNode Des constructor" <<endl;
}
