#include <iostream>
#include <sstream>
#include <chrono>

int comparisons = 0;

bool binary_search(int arr[], int low, int high, int target) {
    if (low > high) return false;
    comparisons++;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return true;
    else if (arr[mid] > target) return binary_search(arr, low, mid - 1, target);
    else return binary_search(arr, mid + 1, high, target);
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    int n, k;
    ss >> n;
    std::string arrStr = ss.str();

    int arr[n];
    for (int i = 0; i < n; i++) {
        ss >> arr[i];
    }

    auto start = std::chrono::high_resolution_clock::now(); // Start timing
    ss >> k;
    bool res = binary_search(arr, 0, n - 1, k);
    auto end = std::chrono::high_resolution_clock::now(); // End timing
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << res << std::endl;
    std::cout << comparisons << " " << duration.count() << std::endl;
    return 0;
}