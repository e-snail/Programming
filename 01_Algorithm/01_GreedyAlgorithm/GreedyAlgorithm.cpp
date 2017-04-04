
#include <iostream>
#include "KnapsackProblem.h"

using namespace std;

int main(int argc, char**argv) {
    cout<<"贪心算法" <<endl;

    Knapsack_Problem *knapsack_problem = new Knapsack_Problem();
    knapsack_problem->startSelecting();
    knapsack_problem->showResult();

    return 0;
}