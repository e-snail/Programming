//
// Created by WuYongbo on 17/3/25.
//

#include "KnapsackProblem.h"
#include <iostream>
#include <float.h>

using namespace std;

Knapsack_Problem::Knapsack_Problem() {

    totalWeight = 150;

    objs.push_back({35, 10, available});
    objs.push_back({30, 40, available});
    objs.push_back({60, 30, available});
    objs.push_back({50, 50, available});
    objs.push_back({40, 35, available});
    objs.push_back({10, 40, available});
    objs.push_back({25, 30, available});
    /*
    objs[1] = {30, 40, available};
    objs[2] = {60, 30, available};
    objs[3] = {50, 50, available};
    objs[4] = {40, 35, available};
    objs[5] = {10, 40, available};
    objs[6] = {25, 30, available};
     */

    selectedObjs.clear();
}

Knapsack_Problem::~Knapsack_Problem() {
   //TODO 销毁对象
}

void Knapsack_Problem::startSelecting() {

    int index = -1;
    int selectedWeight = 0;

    //在这里更换选择策略
    int strategy = 3;
    while ((index = select_strategy(objs, strategy)) != -1) {

        OBJECT &object = objs[index];

        if (object.weight <= (totalWeight - selectedWeight)) {
            selectedObjs.push_back(object);
            selectedWeight += object.weight;
            object.status = unavailable;
        } else {
            object.status = invalid;
        }
    }
}

/**
 * 策略1 选择value最大的物品
 *
 * @param maxWeight
 * @return
 */
int Knapsack_Problem::select_strategy(vector<OBJECT> &objects, int strategy) {

    int index = -1;
    int price = -1;
    int weight = 100000000;
    float pricePerWeight = 0.0f;


    for (int i = 0; i<TOTAL_OBJECTS; i++) {
        OBJECT object = objects[i];
        switch (strategy) {
            case 1:
                if ((object.status == available) && object.price > price) {
                    index = i;
                    price = object.price;
                }
                break;

            case 2:
                if ((object.status == available) && object.weight < weight) {
                    index = i;
                    weight = object.weight;
                }
                break;

            case 3:
                if (object.status == available) {
                    float ppw = static_cast<float >(object.price) / object.weight;
                    //if (static_cast<int>(pricePerWeight * 100000) < static_cast<int>(ppw * 100000)) {
                    if (pricePerWeight < ppw) {
                        index = i;
                        pricePerWeight = ppw;
                    }
                }

                break;
        }
    }

    return index;
}

void Knapsack_Problem::showResult() {

    int totalWeight = 0;
    int totalPrice = 0;

    for (int i=0; i < static_cast<int>(selectedObjs.size()); i++) {
        OBJECT object = selectedObjs[i];
        totalWeight += object.weight;
        totalPrice += object.price;
        cout <<"index " << i << "\t" << object.weight << "\t" <<object.price <<endl;
    }
    cout <<"total\t" << totalWeight <<"\t" <<totalPrice <<endl;

}
