// Heap Sort implementation with modularity

class Heap {
    private int[] heapArray;
    private int size;

    public Heap(int[] arr) {
        this.heapArray = arr;
        this.size = arr.length;
        buildMaxHeap();
    }

    private void heapify(int i) {
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
            swap(i, largest);
            heapify(largest); 
        }
    }
    
    private void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    private void swap(int i, int j) {
        int temp = heapArray[i];
        heapArray[i] = heapArray[j];
        heapArray[j] = temp;
    }

    public void sort() {
        for (int i = size - 1; i > 0; i--) {
            swap(0, i);
            size--;  
            heapify(0);
        }
    }

    public void printSortedArray() {
        for (int num : heapArray) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}

public class heapSort {
    public static void main(String[] args) {
        int[] arr = {9, 4, 3, 8, 10, 2, 5};
        
        System.out.println("Original Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        Heap heap = new Heap(arr);
        heap.sort();
        
        System.out.println("Sorted Array:");
        heap.printSortedArray();
    }
}
