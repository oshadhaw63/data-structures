#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    // Find the range of input elements
    int maxElement = *max_element(arr.begin(), arr.end());
    int minElement = *min_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;
    
    // Create count array and output array
    vector<int> count(range, 0);
    vector<int> output(arr.size());
    
    // Store count of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minElement]++;
    }
    
    // Change count[i] to contain actual position
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }
    
    // Copy the output array to arr
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    countingSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}