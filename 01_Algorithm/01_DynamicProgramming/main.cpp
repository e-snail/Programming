

#include "CoinsValue.h"

int main(int argc, char**argv) {

    CoinsValue *coinsValue = new CoinsValue();
    coinsValue->calculate();
    delete  coinsValue;

    return 0;
}