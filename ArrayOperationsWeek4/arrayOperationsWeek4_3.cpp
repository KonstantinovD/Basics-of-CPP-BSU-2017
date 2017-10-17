#include "../include/TackInclude.h"

#include <iostream>
#include <fstream>
#include <vector>

static void turnArray(std::vector<int> & arr)
{
    int tempForSwap = 0;
    for (int i = 0; i <= (arr.size() / 2 - 1); i++)//Go to the pre-midle element(if size%2 == 1) or to the left middle element(because if size%2 == 0 array hasn't middle element, but we can say about left-middle and right-middle)
    {
        tempForSwap = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = tempForSwap;
    }
}

static void createRezultExpression(std::vector<int> & expr1, std::vector<int> & expr2, std::vector<int> & rez)
{
    for (int i = expr1.size() - 1; i >= 0; i--)
    {
        for (int j = expr2.size() - 1; j >= 0; j--)
        {
            rez[i + j] = rez[i + j] + (expr1[i] * expr2[j]);
        }
    }
}

void arrayOperationsWeek4_3(std::ifstream& FIN)
{
    FIN.open("resources/arrayOperationsWeek4_3.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {

        int sizeArrFirst = 0,
            sizeArrSecond = 0;

        FIN >> sizeArrFirst >> sizeArrSecond;

        std::vector<int> expression1(sizeArrFirst);
        std::vector<int> expression2(sizeArrSecond);
        std::vector<int> resultExpression(sizeArrFirst + sizeArrSecond - 1);//all initialized by "0"

        for (int i = 0; i < expression1.size(); i++) FIN >> expression1[i];
        for (int i = 0; i < expression2.size(); i++) FIN >> expression2[i];

        turnArray(expression1);
        turnArray(expression2);

        createRezultExpression(expression1, expression2, resultExpression);

        for (int i = resultExpression.size() - 1; i >= 0; i--)
        {
            std::cout << resultExpression[i] << "(X^" << i << ")";
            if (i>0) std::cout << "+";
        }
        std::cout << std::endl;
    }

}