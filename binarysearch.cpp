#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int key) {
    if (start > end) {
        return -1; // Key not found
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
        return mid; // Key found
    }
    if (arr[mid] > key) {
        return binarySearch(arr, start, mid - 1, key); // Search in the left half
    }
    return binarySearch(arr, mid + 1, end, key); // Search in the right half
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        cout << "Key not found\n";
    } else {
        cout << "Key found at index " << result << endl;
    }
    return 0;
}