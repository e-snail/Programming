
#include "CoinsValue.h"

/**
 * 如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？
 */

#include <vector>
#include <iostream>

using namespace std;

CoinsValue::CoinsValue() {
}

void CoinsValue::calculate() {

    cout <<"如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？" <<endl;
    cout <<"\t计算结果如下：" <<endl;

    int coins[3] = {1, 3, 5};
    int total = 11;
    int d[12] = {0};  //存放

    for (int i=1; i<12; i++) {
        int values[3] = {-1};
        d[i] = 1000000;
        for (int j=0; j<3; j++) {
            int v = coins[j];
            if (v <= i) {
                values[j] = d[i - v] + 1;
                if (d[i] > values[j]) {
                    d[i] = values[j];
                }
            }
        }
        cout <<"\td[" <<i << "]=" <<"\t" << d[i] <<endl;
    }
}
