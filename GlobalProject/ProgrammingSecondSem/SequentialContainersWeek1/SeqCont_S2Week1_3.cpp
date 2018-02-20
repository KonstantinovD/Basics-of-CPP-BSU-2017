#include "../../include/TackInclude.h"
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

#include <iterator>

template <class ForwardIterator>
static void commonExecute(ForwardIterator first, ForwardIterator last){
    int number;
    std::cout << "input a number: ";
    std::cin >> number;
    int sum = std::accumulate(first, last, 0);
    int size = 0;
    ForwardIterator it;
    for (it = first; it != last; it++){
        size++;
    }
    std::cout << "there are " << std::count(first, last, number) << " occurences of " << number << std::endl;
    std::cout << "there are " << std::count_if(first, last, [number](int a){ return a > number; }) << " numbers which are greater than " << number << std::endl;
    std::cout << "there are " << size << " numbers" << std::endl;
    std::cout << "the sum of them is " << sum << std::endl;
    std::cout << "arithmetic mean is " << ((double)sum / size) << std::endl;
    std::cout << "----------------------------------" << std::endl;
}


void seqCont_S2Week1_3(std::ifstream &FIN){
    FIN.open("resources/seqCont_S2Week1_3.txt");
    std::list<int> ls;
    std::deque<int> deq;
    std::vector<int> vect;

    int inputNumber;
    while (!FIN.eof()){
        FIN >> inputNumber;
        vect.push_back(inputNumber);
    }//input from file
    ls = std::list<int>(vect.begin(), vect.end());
    deq = std::deque<int>(vect.begin(), vect.end());

    std::cout << "IN VECTOR:" << std::endl;
    commonExecute<std::vector<int>::iterator>(vect.begin(), vect.end());
    std::cout << "IN LIST:" << std::endl;
    commonExecute<std::list<int>::iterator>(ls.begin(), ls.end());
    std::cout << "IN DEQUE:" << std::endl;
    commonExecute<std::deque<int>::iterator>(deq.begin(), deq.end());
    
}