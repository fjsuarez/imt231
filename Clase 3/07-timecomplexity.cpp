#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void constantTime(int n[]) {
    cout << "This is a constant time operation" << endl; // O(1)
    int x = 5; // O(1)
    int y = x * 2; // O(1)
} // O(3) = O(1) tiempo constante

void linearTime(int n[], int size) {
    cout << "This is a linear time operation" << endl; // O(1)
    for (int i = 0; i < size; i++) { // O(n) * O(1) = O(n)
        cout << n[i] << " "; // O(1)
    }
    cout << endl; // O(1)
} // O(1) + O(n) + O(1) = O(2) + O(n) = O(n) tiempo lineal

void quadraticTime(int n[], int size) {
    cout << "This is a quadratic time operation" << endl; // O(1)
    for (int i = 0; i < size; i++) { // O(n)
        for (int j = 0; j < size; j++) { // O(n) * O(1) = O(n)
            cout << n[i] << " "; // O(1)
        }
        cout << endl; // O(1)
    }
} // O(1) + O(n) * (O(1) + O(n) + O(1)) = O(1) + O(n) * O(n) = O(1) + O(n^2) = O(n^2) tiempo cuadrático

bool mysteryFunction(int n[], int size, int target) { // Busqueda binaria
    int low = 0; // O(1)
    int high = size - 1; // O(1)
    while (low <= high) { // O(log n)
        int mid = low + (high - low) / 2; // O(1) (2*low + high - low)/2 = (high + low)/2
        if (n[mid] == target) { // O(1)
            return true; // O(1)
        } else if (n[mid] < target) { // O(1)
            low = mid + 1; // O(1)
        } else {
            high = mid - 1; // O(1)
        }
    }
    return false; // O(1)
}

void mystery1(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) { // O(n)
        for (int j = i; j < n; ++j) { // O(n) + O(n-1) + O(n-2) + ... + O(1) = O(n(n+1)/2) = O(n^2)
            std::cout << arr[j] << " "; // Some operation (e.g., printing)
        }
        std::cout << std::endl;
    }
}

int mystery2(const std::vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i += 2) { // O(n/2) = O(n)
        sum += arr[i];
    }
    return sum;
}

  int mystery3(int n) { // O(2^n)
    if (n <= 1) {
        return 1;
    } else {
        return mystery3(n - 1) + mystery3(n - 2);
    }
}

bool mystery4(std::vector<int> arr) { // O(n log n)
    std::sort(arr.begin(), arr.end()); // Sort the array O(n log n)
    for (size_t i = 0; i < arr.size() - 1; ++i) { // O(n)
      if (arr[i] == arr[i+1]) {
        return true; // Found duplicates
      }
    }
    return false; // No duplicates found
  }


int main() {
    
    return 0;
}