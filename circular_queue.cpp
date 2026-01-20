#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " enqueued to queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        }
        return value;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    return 0;
}