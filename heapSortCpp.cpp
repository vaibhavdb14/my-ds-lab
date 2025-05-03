#include <iostream>
using namespace std;

class Heap {
private:
    int* heapArray;
    int size;

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heapArray[left] > heapArray[largest]) {
            largest = left;
        }

        if (right < size && heapArray[right] > heapArray[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            heapify(largest);
        }
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

public:
    Heap(int arr[], int n) {
        heapArray = arr;
        size = n;
        buildMaxHeap();
    }

    void sort() {
        for (int i = size - 1; i > 0; i--) {
            swap(heapArray[0], heapArray[i]);
            size--;
            heapify(0);
        }
    }

    void printSortedArray(int n) {
        for (int i = 0; i < n; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {9, 4, 3, 8, 10, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Heap heap(arr, n);
    heap.sort();

    cout << "Sorted Array:\n";
    heap.printSortedArray(n);

    return 0;
}
