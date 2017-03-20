//
// Created by WuYongbo on 17/3/19.
//

#ifndef INC_02_DATASTRUCTURE_TREE_RBTNODE_H
#define INC_02_DATASTRUCTURE_TREE_RBTNODE_H

#define NULL 0

enum Color {
    Black,
    Red
};

/**
 * 红黑二叉树节点
 */
class RBTNode {

public:
    RBTNode(int key) :
            key(key), color(Red), left(NULL), right(NULL), parent(NULL)
    {

    };

    void nodeInfo();

public:
    Color color;
    int key;
    RBTNode * left;
    RBTNode * right;
    RBTNode * parent;

};


#endif //INC_02_DATASTRUCTURE_TREE_RBTNODE_H
