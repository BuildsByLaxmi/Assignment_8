#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
private:
    int heap[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert element in heap
    void insert(int value) {
        if (size >= MAX) {
            cout << "Priority Queue Overflow\n";
            return;
        }
        heap[size] = value;  // Insert at end
        int i = size;
        size++;

        // Fix heap property (heapify up)
        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Delete highest priority element (root)
    int deleteMax() {
        if (size <= 0) {
            cout << "Priority Queue Underflow\n";
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap[size - 1]; // Move last to root
        size--;

        heapify(0); // Fix heap property (heapify down)
        return maxVal;
    }

    // Heapify from index i downwards
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // Display priority queue (heap)
    void display() {
        if (size == 0) {
            cout << "Priority Queue is Empty\n";
            return;
        }
        cout << "Priority Queue (heap form): ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n1. Insert (Enqueue)";
        cout << "\n2. Delete Highest Priority (Dequeue)";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;

        case 2:
            value = pq.deleteMax();
            if (value != -1)
                cout << "Deleted highest priority element: " << value << endl;
            break;

        case 3:
            pq.display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
