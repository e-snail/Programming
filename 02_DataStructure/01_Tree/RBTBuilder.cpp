//
// Created by WuYongbo on 17/3/19.
//

#include "RBTNode.h"
#include "RBTBuilder.h"

#include <iostream>

using namespace std;

//插入节点
RBTNode* insert(RBTNode *root, int key);
//删除节点
bool remove(RBTNode *root, int key);

int inputs[] = {2, 1, 3};

/**
 * 构建红黑二叉树
 *
 * @return
 */
RBTNode * buildRBTree() {

    int length = sizeof(inputs) / sizeof(int);

    cout <<"buildRBTree with inputs length " << length <<endl;

    if (length < 1) {
        return NULL;
    }

    cout <<"---->building start..." <<endl;

    RBTNode *root = NULL;

    for (int i=0; i<length; i++) {
        //Step 1: 插入节点
        root = insert(root, inputs[i]);
        //cout <<"\t insert " <<to_string(inputs[i]) << "  " << (root != NULL ? "success!" : "failed!") <<endl;

        //Step2: 检查是否符合红黑二叉树的规则

        //Step3: 调整节点
    }

    cout <<"---->building end" <<endl;

    return root;
}

/**
 *
 * @param root
 * @param key
 * @return 返回根节点
 */
RBTNode* insert(RBTNode *root, int key) {

    //Step 1: 插入子节点，把红黑二叉树当搜索二叉树对待
    RBTNode *z = new RBTNode(key);

    RBTNode *p = root;
    RBTNode *last = p;

    while (p != NULL) {
        last = p;
        //暂不考虑key值想等的情况
        if (p->key > key)
            p = p->left;
        else
            p = p->right;
    }

    if (!last) {
        root = z;
    } else {
        if (last->key > key) {
            last->left = z;
        } else {
            last->right = z;
        }
        z->parent = last;
    }

    //Step 2: 将新节点设成红色
    z->color = Red;

    /** 重要思考：
     * 1 z置为红色，则其父节点必然不能是红色，如果父节点是黑色，就仍然符合红黑二叉树的五个特性
     * 2 z指向的节点也是在变化的，为什么仍然要求z的父节点是红色呢？？？
     * */

    //Step 3: 重新着色，并旋转
    while (z->parent->color == Red) {

        if (z->parent == z->parent->parent->left) {    //因为z->parent是红节点，所以z->parent必然有父节点
            //z的父节点是祖节点的左子树
            RBTNode *y = z->parent->parent->right;  //y是z的叔节点

            if (y->color == Red) {
                //case 1: 插入节点的叔节点是红色
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;

                z = z->parent->parent;
            } else if (y->color == Black) {
                //case 2: z的叔节点是黑色，且z是有节点
                if (z == z->parent->right) {
                    z = z->parent;

                    //TODO 左旋
                }
            }
            z->parent->color = Black;
            z->parent->parent->color = Red;
            //到此为止，z节点（插入位置）的父、叔节点都是黑色，祖节点是红色

            //TODO 右旋
        } else {
            //z的父节点是祖节点的右子树
            //????
        }

    }

    root->color = Black;

    return root;
}

bool remove(RBTNode *root, int key) {

    return false;
}
