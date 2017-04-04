//
// Created by WuYongbo on 17/3/25.
//

#ifndef INC_01_GREEDYALGORITHM_KNAPSACKPROBLEM_H
#define INC_01_GREEDYALGORITHM_KNAPSACKPROBLEM_H

#include <vector>

using namespace std;

#define TOTAL_OBJECTS 7

//0 未选中  1 选中  2 已经不可选中
enum STATUS {
    available = 0,
    unavailable,
    invalid
};

//物品
//status 不可选中的意思是物品的重量超过当前背包的剩余重量
typedef struct tagObject {
    int weight; //重量
    int price;  //价值
    STATUS status;
} OBJECT;

class Knapsack_Problem {

public:
    Knapsack_Problem();
    ~Knapsack_Problem();

private:
    vector<OBJECT> objs;
    vector<OBJECT> selectedObjs;

    int totalWeight;

private:
    int select_strategy(vector<OBJECT> &objects, int strategy);

public:
    void startSelecting();
    void showResult();
};


#endif //INC_01_GREEDYALGORITHM_KNAPSACKPROBLEM_H
