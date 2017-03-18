//
// Created by WuYongbo on 17/3/11.
//

#include <iostream>

#include "BTNode.h"
#include <stack>
#include <queue>

using namespace std;

//int inputs[] = {5, 3, 8, 2, 4, 7, 9, 1, 6};
int inputs[] = {7, 3, 8, 2, 4, 5, 9, 1, 6};

/**
 * 根据输入顺序构建任意二叉树
 *
 * @param values
 * @return
 */
BTNode *buildBinaryTree_1(int values[]) {

    int length = sizeof(inputs) / sizeof(int);

    cout <<"buildBinaryTree_1 with input size " << length <<endl;

    if (length <= 0) {
        return NULL;
    }

    BTNode *root = new BTNode(values[0]);

    for (int i=1; i<length; i++) {

        int value = values[i];
        BTNode *node = new BTNode(value);

        BTNode *p = root;

        while (p->leftChild || p->rightChild) {
            if (p->value > value && p->leftChild) {
                p = p->leftChild;
            } else if (p->value < value && p->rightChild) {
                p = p->rightChild;
            } else {
                break;
            }
        }

        if (p->value > value) {
            p->leftChild = node;
        } else if (p->value < value) {
            p->rightChild = node;
        } else {
            delete(node);
        }
   }

    return root;
}

/**
 * 构建平衡二叉树
 *
 * @param values
 * @return
 */
BTNode * buildBinaryTree_2(int values[]) {

    /*
    BTNode *root = new BTNode(values[0]);
    BTNode *left = new BTNode(values[1]);
    BTNode *right = new BTNode(values[2]);

    root->leftChild = left;
    root->rightChild = right;
     */
    BTNode *node0 = new BTNode(5);
    BTNode *node1 = new BTNode(3);
    BTNode *node2 = new BTNode(8);
    BTNode *node3 = new BTNode(2);
    BTNode *node4 = new BTNode(4);
    BTNode *node5 = new BTNode(7);
    BTNode *node6 = new BTNode(9);
    BTNode *node7 = new BTNode(1);
    BTNode *node8 = new BTNode(6);

    node0->leftChild = node1;
    node0->rightChild = node2;

    node1->leftChild = node3;
    node1->rightChild = node4;

    node2->leftChild = node5;
    node2->rightChild = node6;

    node3->leftChild = node7;
    node5->leftChild = node8;


    return node0;
}

/* 存放二叉树节点的栈和队列 */
stack<BTNode*> btnStack;
queue<BTNode*> btnQueue;


/**
 * 递归 中序遍历 二叉树
 *
 * @param root 二叉树根节点
 */
void traverseBinaryTree_1(BTNode *root) {
    if (root == NULL) {
        return;
    }

    //1 根节点入栈
    btnStack.push(root);

    //2 左子树不为空，则入栈
    if (root->leftChild != NULL) {
        traverseBinaryTree_1(root->leftChild);
    }

    //3 打印当前节点value
    cout << root->value <<"  ";

    //4 当前节点出栈
    btnStack.pop();

    //5 右子树入栈
    if (root->rightChild != NULL) {
        traverseBinaryTree_1(root->rightChild);
    }
}

void traverseBT(BTNode *root) {

}

/**
 * 非递归 中序遍历 二叉树
 * 使用一个栈和一个队列，按照中序遍历顺序存入队列中
 *
 * @param root 二叉树根节点
 */
void traverseBinaryTree_2(BTNode *root) {

    if (root == NULL) {
        return;
    }

    btnStack.empty();
    BTNode *node = root->leftChild;

    /* 对根节点的左子节点，操作如下： */

    //1 将所有左子节点放入栈中
    while (node != NULL) {
        btnStack.push(node);
        node = node->leftChild;
    }

    //2 将栈内所有元素依次取出，放入一个队列中，如果节点有右子节点，也一起入队列
    while (btnStack.size() > 0) {
        BTNode *tmpNode = btnStack.top();
        btnQueue.push(tmpNode);
        if (tmpNode->rightChild != NULL) {
            btnQueue.push(tmpNode->rightChild);
        }
        btnStack.pop();
    }

    //3 根节点入队列
    btnQueue.push(root);

    btnStack.empty();
    node = root->rightChild;

    /* 对根节点的右子节点，采用跟左子节点一样的操作 */

    while (node != NULL) {
        btnStack.push(node);
        node = node->leftChild;
    }

    while (btnStack.size() > 0) {
        BTNode *tmpNode = btnStack.top();
        btnQueue.push(tmpNode);
        if (tmpNode->rightChild != NULL) {
            btnQueue.push(tmpNode->rightChild);
        }
        btnStack.pop();
    }

    while (btnQueue.size() > 0) {
        node = btnQueue.front();
        cout <<node->value << "  ";
        btnQueue.pop();
    }
}

/**
 * 非递归 中序遍历 二叉树
 * 只用一个栈，比上一个方法要好一点
 *
 * @param root 二叉树根节点
 */
void traverseBinaryTree_3(BTNode *root) {

    if (root == NULL) {
        return;
    }

    stack<BTNode *> stackBTN;

    BTNode *p = root;

    while (p || stackBTN.size() > 0) {

        if (p) {
            stackBTN.push(p);
            p = p->leftChild;
        } else {
            BTNode *node = stackBTN.top();
            stackBTN.pop();
            cout <<node->value <<"  ";

            p = node->rightChild;
        }
    }

    cout <<endl;
}


int main(int argc, char **argv) {

    /*
    BTNode *node1 = new BTNode(100);
    delete(node1);

    BTNode node2(200);
    */

    /* 触发拷贝构造函数 */
    /*
    BTNode node3 = node2;

    node3.displayValue();

    */

    BTNode *root = buildBinaryTree_1(inputs);

    /* -------------------------------------------------------- */

    cout <<"递归遍历二叉树 开始..." <<endl;

    btnStack.empty();
    traverseBinaryTree_1(root);

    cout <<endl <<"递归遍历二叉树 结束" <<endl;

    /* -------------------------------------------------------- */

    cout <<"非递归遍历二叉树 开始..." <<endl;

    //btnQueue.empty();
    //btnStack.empty();
    //traverseBinaryTree_2(root);

    traverseBinaryTree_3(root);

    cout <<"非递归遍历二叉树 结束" <<endl;

    return 0;
}

