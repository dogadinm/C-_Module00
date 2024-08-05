#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const std::vector<int>& data);
    PmergeMe(PmergeMe &copy);
    ~PmergeMe();

    PmergeMe &operator=(PmergeMe &copy);
    void sort();

private:
    std::vector<int> dataVector;
    std::deque<int> dataDeque;
    double timeVector;
    double timeDeque;

    // vector
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void fordJohnsonSort(std::vector<int>& arr, int left, int right);
    // deque
    void merge(std::deque<int>& deq, int left, int mid, int right);
    void fordJohnsonSort(std::deque<int>& deq, int left, int right);
    
    void displayBefore() const ;
    void displayAfter() const;


};
