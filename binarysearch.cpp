#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> sorted_arr, int num){
    int middle = sorted_arr.size() / 2;
    if (!sorted_arr.empty()){
        if (sorted_arr[middle] == num){
            return true;
        }else if (sorted_arr[middle] < num){
            return binarySearch(vector<int>(sorted_arr.begin() + middle + 1, sorted_arr.end()), num);
        }else {
            return binarySearch(vector<int>(sorted_arr.begin(), sorted_arr.begin() + middle), num);
        }
    }
    
    
}


int main(){
    vector<int> vec = {24, 36, 25, 49, 1, -1, 6, -4, -21, 34, 26, 322, -6, 2, 21};
    sort(vec.begin(), vec.end());
    cout << binarySearch(vec, 26) << endl;
    cout << binarySearch(vec, 56) << endl;
    cout << binarySearch(vec, 426) << endl;
    cout << binarySearch(vec, -6) << endl;
}