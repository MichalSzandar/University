#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

bool showLogs = false;

int keyComparisons = 0;
int keySwaps = 0;

int size = 0;

std::random_device rd;
std::mt19937 gen(rd());

bool compare(int a, int b) {
    keyComparisons++;
    return a > b;
}

void swap(int *a, int *b) {
    keySwaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cerr << arr[i] << " ";
    }
    std::cerr << std::endl;
}

int partition(int arr[], int low, int high) {
    std::uniform_int_distribution<int> dis(low, high);
    int pivotIndex = dis(gen);
    int pivot = arr[pivotIndex];

    if(arr[pivotIndex] != arr[high]) {
        swap(&arr[pivotIndex], &arr[high]);
    }
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(pivot, arr[j])) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    if(showLogs)
        printArr(arr, size);
    return i + 1;
}

int select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int partitionIndex = partition(arr, low, high);
    if (k == partitionIndex + 1) {
        return arr[partitionIndex];
    } else if (partitionIndex + 1 > k) {
        return select(arr, low, partitionIndex - 1, k);
    } else {
        return select(arr, partitionIndex + 1, high, k);
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    int n, k;
    ss >> n;
    std::string arrStr = ss.str();
    size = n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        ss >> arr[i];
    }

    ss >> k;

    if (n < 40) {
        showLogs = true;
        printArr(arr, n);
    }

    int res = select(arr, 0, n - 1, k);

    if (showLogs) {
        std::cerr << "ending state of array: ";
        printArr(arr, n);
        std::cerr << std::endl << "Initial array: " << arrStr << std::endl;
        std::cerr << "k: " << k << std::endl;
        std::cerr << "Result: " << res << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now(); // End timing
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << "Random select execution time: " << duration.count() << " microseconds" << std::endl;
    std::cout << keyComparisons << " " << keySwaps << " " << duration.count() <<std::endl;
    std::sort(arr, arr + n);
    if (showLogs) {
        std::cerr << "Sorted array: ";
        printArr(arr, n);
    }

    return 0;
}