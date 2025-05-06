#include <iostream>
#include <sstream>
#include <chrono>

long long key_swaps = 0;
long long key_comparisons = 0;

bool showLogs = false;
int size = 0;

bool compare(int a, int b) {
    key_comparisons++;
    return a < b;
}

void swap(int* a, int* b) {
    key_swaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool checkIfSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
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

    if(showLogs)   
        printArr(arr, size);
    
    return i;
}

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

// Dual Pivot Quicksort
void dualPivotQuicksort(int arr[], int low, int high) {
    if (low < high) {
        int len = high - low + 1;

        int p = select(arr, low, high, len / 3 + 1);
        int q = select(arr, low, high, 2 * len / 3 + 1);
        if (!compare(p, q))
            swap(&p, &q);

        int i;
        for (i = low; i <= high; ++i)
            if (arr[i] == p) break;
        swap(&arr[low], &arr[i]);

        for (i = high; i >= low; --i)
            if (arr[i] == q) break;
        swap(&arr[high], &arr[i]);

        int lt = low + 1;
        int gt = high - 1;
        int i2 = lt;

        while (i2 <= gt) {
            if (compare(arr[i2], p)) {
                swap(&arr[i2], &arr[lt]);
                lt++;
            } else if (!compare(arr[i2], q) && arr[i2] != q) {
                swap(&arr[i2], &arr[gt]);
                gt--;
                i2--;
            }
            i2++;
        }

        lt--; gt++;
        swap(&arr[low], &arr[lt]);
        swap(&arr[high], &arr[gt]);

        dualPivotQuicksort(arr, low, lt - 1);
        dualPivotQuicksort(arr, lt + 1, gt - 1);
        dualPivotQuicksort(arr, gt + 1, high);
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    int n;
    ss >> n;
    std::string arrStr = ss.str();
    size = n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        ss >> arr[i];
    }

    if (n < 40) {
        showLogs = true;
        printArr(arr, n);
    }

    dualPivotQuicksort(arr, 0, n - 1);

    if (showLogs) {
        std::cerr << "Sorted array: ";
        printArr(arr, n);
        std::cerr << std::endl << "Initial array: " << arrStr << std::endl;
    }

    std::cout << key_comparisons << " " << key_swaps << std::endl;

    auto end = std::chrono::high_resolution_clock::now(); // End timing
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << "Dual pivot QuickSort execution time: " << duration.count() << " microseconds" << std::endl;

    return checkIfSorted(arr, n) ? 0 : 1;
}