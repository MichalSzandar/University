#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>

bool showLogs = false;

int keyComparisons = 0;
int keySwaps = 0;

int size = 0;

bool compare(int a, int b) {
    keyComparisons++;
    return a < b;
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

// Sortowanie przez wstawianie (dla małych grup)
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && !compare(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int select(int arr[], int left, int right, int k);
int medianOfMedians(int arr[], int left, int right);

// Podział względem pivota
int partition(int arr[], int left, int right, int pivot) {
    int i;
    for (i = left; i <= right; ++i) {
        if (arr[i] == pivot)
            break;
    }
    swap(&arr[i], &arr[right]);

    i = left;
    for (int j = left; j < right; ++j) {
        if (compare(arr[j], pivot)) {
            swap(&arr[i], &arr[j]);
            ++i;
        }
    }
    swap(&arr[i], &arr[right]);

    if (showLogs)   
        printArr(arr, size);
    
    return i;
}

// Median of Medians
int medianOfMedians(int arr[], int left, int right) {
    int n = right - left + 1;
    int numMedians = (n + 4) / 5;
    int* medians = new int[numMedians];

    for (int i = 0; i < numMedians; ++i) {
        int subLeft = left + i * 5;
        int subRight = std::min(subLeft + 4, right);
        insertionSort(arr, subLeft, subRight);
        medians[i] = arr[subLeft + (subRight - subLeft) / 2];
    }

    int median = select(medians, 0, numMedians - 1, (numMedians + 1) / 2);
    delete[] medians;
    return median;
}

// Główna funkcja SELECT
int select(int arr[], int left, int right, int k) {
    if (left == right)
        return arr[left];

    int pivot = medianOfMedians(arr, left, right);
    int pivotIndex = partition(arr, left, right, pivot);
    int rank = pivotIndex - left + 1;

    if (k == rank)
        return arr[pivotIndex];
    else if (k < rank)
        return select(arr, left, pivotIndex - 1, k);
    else
        return select(arr, pivotIndex + 1, right, k - rank);
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
    std::cerr << "Select execution time: " << duration.count() << " microseconds" << std::endl;
    std::cout << keyComparisons << " " << keySwaps << " " << duration.count() <<std::endl;
    std::sort(arr, arr + n);
    if (showLogs) {
        std::cerr << "Sorted array: ";
        printArr(arr, n);
    }

    return 0;
}