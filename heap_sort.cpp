#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> heapSort(vector<int> unsorted_arr){
    priority_queue<int> max_heap(unsorted_arr.begin(), unsorted_arr.end());
    vector<int> sorted_arr;
    while (!max_heap.empty()){
        sorted_arr.push_back(max_heap.top());
        max_heap.pop();
    }
    reverse(sorted_arr.begin(), sorted_arr.end());
    return sorted_arr;
}


int main(){
    vector<int> arr = {324, 25, 324, -3, 37, 536, 64, 2434, -32, 23, 26};
    vector<int> sorted_arr = heapSort(arr);
    for (int i = 0; i < sorted_arr.size(); i++){
        cout << sorted_arr[i] << " ";
    }
    cout << endl;

}