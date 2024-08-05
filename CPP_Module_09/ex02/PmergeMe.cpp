#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& data) : dataVector(data), dataDeque(data.begin(), data.end()) {}

PmergeMe::PmergeMe(PmergeMe &copy)
{
    *this = copy;
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(PmergeMe &copy)
{
    if (this == &copy)
        return *this;
    return *this;
}

// Vector
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Ford-Johnson sort for std::vector
void PmergeMe::fordJohnsonSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    fordJohnsonSort(arr, left, mid);
    fordJohnsonSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Deque
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PmergeMe::merge(std::deque<int>& deq, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::deque<int> leftDeq(leftSize);
    std::deque<int> rightDeq(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftDeq[i] = deq[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightDeq[i] = deq[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftDeq[i] <= rightDeq[j]) {
            deq[k] = leftDeq[i];
            i++;
        } else {
            deq[k] = rightDeq[j];
            j++;
        }
        k++;
    }


    while (i < leftSize) {
        deq[k] = leftDeq[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        deq[k] = rightDeq[j];
        j++;
        k++;
    }
    // for (int o = 0; o < (int)deq.size(); o++) {
    // std::cout << deq[o] << std::endl;
    // }
    // std::cout << std::endl;
}

// Ford-Johnson sort for std::deque
void PmergeMe::fordJohnsonSort(std::deque<int>& deq, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    fordJohnsonSort(deq, left, mid);
    fordJohnsonSort(deq, mid + 1, right);
    merge(deq, left, mid, right);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void PmergeMe::displayBefore() const {
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = dataVector.begin(); it != dataVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void PmergeMe::displayAfter() const {
    std::cout << "After: ";
    for (std::deque<int>::const_iterator it = dataDeque.begin(); it != dataDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}


void PmergeMe::sort() {
    displayBefore();

    clock_t start1 = clock();
    fordJohnsonSort(dataVector, 0, dataVector.size() - 1);
    clock_t end1 = clock();
    timeVector = static_cast<double>(end1 - start1) / 1000;

    clock_t start2 = clock();
    fordJohnsonSort(dataDeque, 0, dataDeque.size() - 1);
    clock_t end2 = clock();
    timeDeque = static_cast<double>(end2 - start2) / 1000;

    displayAfter();

    std::cout << "Time to process a range of " << dataVector.size() << " elements with std::vector: " << timeVector << " us\n";
    std::cout << "Time to process a range of " << dataDeque.size() << " elements with std::deque: " << timeDeque << " us\n";
}
