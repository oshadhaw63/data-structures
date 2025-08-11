#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(24);
    pq.push(14);
    pq.push(84);
    pq.push(64);
    pq.push(41);

    cout << "Highest Priority: " << pq.top() << endl;
    pq.pop();
    cout << "Highest Priority: " << pq.top() << endl;

    cout << "Is highest priority queue empty? " << pq.empty() << endl;

    cout << "Size of the priority queue: " << pq.size() << endl;

    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}