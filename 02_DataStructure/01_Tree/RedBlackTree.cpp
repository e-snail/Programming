//
// Created by WuYongbo on 17/3/19.
//

#include <iostream>

#include "RBTNode.h"
#include "RBTBuilder.h"

using namespace std;

int main(int argc, char **argv) {
    /* -------------------------------------------------------- */

    cout << "构建红黑二叉树" << endl;

    RBTNode *root= buildRBTree();
    if (root) {
        root->nodeInfo();
    } else {
        cout <<"NULL ROOT RedBlackTree" <<endl;
    }

    return 0;
}

