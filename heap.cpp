#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class MinHeap {
private:
    std::vector<T> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left] < heap[minIndex])
            minIndex = left;
        if (right < heap.size() && heap[right] < heap[minIndex])
            minIndex = right;
        
        if (i != minIndex) {
            std::swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }
    
public:
    void insert(T value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    T extractMin() {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");
        
        T minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return minValue;
    }
    
    T getMin() const {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");
        return heap[0];
    }
    
    bool empty() const { return heap.empty(); }
    int size() const { return heap.size(); }
};

template<typename T>
class MaxHeap {
private:
    std::vector<T> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left] > heap[maxIndex])
            maxIndex = left;
        if (right < heap.size() && heap[right] > heap[maxIndex])
            maxIndex = right;
        
        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
public:
    void insert(T value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    T extractMax() {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");
        
        T maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return maxValue;
    }
    
    T getMax() const {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");
        return heap[0];
    }
    
    bool empty() const { return heap.empty(); }
    int size() const { return heap.size(); }
};

int main() {
    MinHeap<int> minHeap;
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);
    std::cout << "Min: " << minHeap.extractMin() << std::endl;
    
    MaxHeap<int> maxHeap;
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(1);
    std::cout << "Max: " << maxHeap.extractMax() << std::endl;
    
    return 0;
}