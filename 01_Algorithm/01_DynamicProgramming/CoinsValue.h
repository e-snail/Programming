
#ifndef _COINSVALUE_H_
#define _COINSVALUE_H_

class CoinsValue {

public:
    CoinsValue();
    void calculate();

private:
    int coins[3] = {1, 3, 5};
    int total = 11;
    int d[12] = {0};  //存放
};

#endif
