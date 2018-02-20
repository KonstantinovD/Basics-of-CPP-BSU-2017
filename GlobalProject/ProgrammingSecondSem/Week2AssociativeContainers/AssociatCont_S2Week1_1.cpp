#include "../../include/TackInclude.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

static void initialize(std::ifstream &FIN, std::set<int> st, std::multiset<int> mutl){
    int sizeOfCont = 0,
        inputNumber = 0;
    FIN >> sizeOfCont;
    for (int i = 0; i < sizeOfCont; i++){
        FIN >> inputNumber;
        st.insert(inputNumber);
    }
    FIN >> sizeOfCont;
    for (int i = 0; i < sizeOfCont; i++){
        FIN >> inputNumber;
        st.insert(inputNumber);
    }
}

void associatCont_S2Week1_1(std::ifstream &FIN){


    std::set<int> st;
    std::multiset<int> mult;
    std::multiset<int> mult2;

    

    //includes ���������� true, ���� ���� ����� - ������������ �������
    st = std::set<int>({ 1, 3, 8, 20 });
    mult = std::multiset<int>({ 1, 1, 3, 8, 20, 20, 20 });
    mult2 = std::multiset<int>({ 1, 3, 8, 20, 20, 20 });
    std::cout << "set: 1, 3, 8, 20; multiset1: 1, 1, 3, 8, 20, 20, multiset2: 1, 3, 20, 20, 20" << std::endl;
    std::cout <<"Does multiset1 includes set? "<< std::includes(mult.begin(), mult.end(), st.begin(), st.end())<<std::endl;
    std::cout << "Does set includes multiset1? " << std::includes(st.begin(), st.end(), mult.begin(), mult.end()) << std::endl;
    std::cout << "Does multiset1 includes multiset2? " << std::includes(mult.begin(), mult.end(), mult2.begin(), mult2.end()) << std::endl;
    std::cout << "Does multiset2 includes multiset1? " << std::includes(mult2.begin(), mult2.end(), mult.begin(), mult.end()) << std::endl;
    std::cout << std::endl;
    //��� �������� � ���� ������ ��� ����� � ������ �����, ����� ��� ��� ���� ���������
    //��� ����� �������� � ���� ��������� ������ ���� 1) � ���������� ��� ���������� 2) ��� ��-�� ���������� ���������� � ����
    //��������� ����� �������� � ���� ���(������ ���������), ���� ��� ��-�� ����(������� ����������) ���������� � ����������


    //set_intersection ������� ��-��, ���������� ����������� ���� ������
    std::set<int> intersect;
    
    st = std::set<int>({ 1, 3, 8, 20 });
    mult = std::multiset<int>({ 1, 3, 45, 60, 60 });
    mult2 = std::multiset<int>({ 1, 1, 45, 60, 60});
    std::cout << "set: 1, 3, 8, 20; multiset1: 1, 3, 45, 60, 60, multiset2: 1, 1, 45, 60, 60" << std::endl;
    std::set_intersection(st.begin(), st.end(), mult.begin(), mult.end(), std::inserter(intersect, intersect.begin()));
    std::cout <<"set and multiset1 intersection: ";
    std::for_each(intersect.begin(), intersect.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    intersect.clear();

    std::set_intersection(mult2.begin(), mult2.end(), mult.begin(), mult.end(), std::inserter(intersect, intersect.begin()));
    std::cout << "multiset1 and multiset2 intersection: ";
    std::for_each(intersect.begin(), intersect.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    std::cout << std::endl;
    //����������� �� �������� � ���� ��������� (���� ���� ������������ 2 ���������� � ����������� �����������)

    //set_difference ������� ��-��, ���������� ��� ��-�� ������� ��-��, ������� �� ������ � ������
    std::multiset<int> differ;
    std::set<int> differWithoutDuplicates;

    st = std::set<int>({ 1, 3, 8, 20 });
    mult = std::multiset<int>({ 1, 3, 45, 60, 60 });
    mult2 = std::multiset<int>({ 1, 1, 45, 60, 60, 60 });
    std::cout << "set: 1, 3, 8, 20; multiset1: 1, 3, 45, 60, 60, multiset2: 1, 1, 45, 60, 60, 60" << std::endl;

    std::set_difference(st.begin(), st.end(), mult.begin(), mult.end(), std::inserter(differ, differ.begin()));
    std::cout << "set minus multiset1 is: ";
    std::for_each(differ.begin(), differ.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    differ.clear();

    std::set_difference(mult.begin(), mult.end(), st.begin(), st.end(), std::inserter(differ, differ.begin()));
    std::cout << "multiset1 minus set is: ";
    std::for_each(differ.begin(), differ.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    differ.clear();

    std::set_difference(mult.begin(), mult.end(), st.begin(), st.end(), std::inserter(differWithoutDuplicates, differWithoutDuplicates.begin()));
    std::cout << "(without duplicates): multiset1 minus set is: ";
    std::for_each(differWithoutDuplicates.begin(), differWithoutDuplicates.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    differWithoutDuplicates.clear();

    std::set_difference(mult2.begin(), mult2.end(), mult.begin(), mult.end(), std::inserter(differ, differ.begin()));
    std::cout << "multiset2 minus multiset1 is: ";
    std::for_each(differ.begin(), differ.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    differ.clear();

    std::set_difference(mult.begin(), mult.end(), mult2.begin(), mult2.end(), std::inserter(differ, differ.begin()));
    std::cout << "multiset1 minus multiset2 is: ";
    std::for_each(differ.begin(), differ.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    std::cout << std::endl;
    //����������� set_difference �������� ���������, ������� �������� �� ��-�� �� ������� ��-��, ������� �� ���� �� ������. ���� ��������� ������������ � multiset,
    //�� ��������� �����������(�. �. {12, 35, 35, 35, 80} - {10, 35, 80} = {12, 35, 35}), ���� � set - �� �� �����������({12, 35, 35, 35, 80} - {10, 35, 80} = {12, 35})

    //set_union ������� ��-��, ���������� ��� ��-�� �� ����� ��������
    std::multiset<int> uni;
    std::set<int> uniWithoutDuplicates;

    st = std::set<int>({ 1, 3, 8, 20 });
    mult = std::multiset<int>({ 1, 3, 45, 60, 60 });
    mult2 = std::multiset<int>({ 1, 1, 45, 60, 60, 60 });
    std::cout << "set: 1, 3, 8, 20; multiset1: 1, 3, 45, 60, 60, multiset2: 1, 1, 45, 60, 60, 60" << std::endl;

    std::set_union(st.begin(), st.end(), mult.begin(), mult.end(), std::inserter(uni, uni.begin()));
    std::cout << "union of set and multiset1 is: ";
    std::for_each(uni.begin(), uni.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    uni.clear();

    std::set_union(st.begin(), st.end(), mult.begin(), mult.end(), std::inserter(uniWithoutDuplicates, uniWithoutDuplicates.begin()));
    std::cout << "(without duplicates): union of set and multiset1 is: ";
    std::for_each(uniWithoutDuplicates.begin(), uniWithoutDuplicates.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    uni.clear();

    std::set_union(mult.begin(), mult.end(), mult2.begin(), mult2.end(), std::inserter(uni, uni.begin()));
    std::cout << "union of multiset1 and multiset2 is: ";
    std::for_each(uni.begin(), uni.end(), [](int n){std::cout << n << " "; });
    std::cout << std::endl;
    uni.clear();
    //����������� set_union �������� ���������, ������� �������� ����������� ������� � ������� ���������. ��� � � set_difference,
    //���� ��������� ������������ � multiset, �� ��������� �����������, ���� � set - ���
}