//
// Created by WuYongbo on 17/3/11.
//

#ifndef CLIONPROJECTS_BTNODE_H
#define CLIONPROJECTS_BTNODE_H

/**
 * 二叉树
 */
class BTNode {

public:
    int value;

    //BTNode *parent;         //父节点
    BTNode *leftChild;      //左孩子节点
    BTNode *rightChild;     //右孩子节点

public:

    /* 构造函数 */
    BTNode(int value);

    /* 拷贝构造函数 */
    BTNode(const BTNode &node);

    void displayValue();

    /* 析构函数函数 */
    virtual ~ BTNode();

};


#endif //CLIONPROJECTS_BTNODE_H
