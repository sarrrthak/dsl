
#include<iostream>
using namespace std;

#define MAX 10 // Maximum size of the deque

class Deque {
private:
    int arr[MAX]; // Array to store deque elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int size;     // Current size of the deque

public:
    // Constructor
    Deque() : front(-1), rear(0), size(0) {}

    // Function to check if deque is full
    bool isFull() {
        return size == MAX;
    }

    // Function to check if deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to insert an element at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at the front." << endl;
            return;
        }
        if (front == -1) { // First element
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1; // Wrap around to the end of the array
        } else {
            front--;
        }
        arr[front] = value;
        size++;
    }

    // Function to insert an element at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at the rear." << endl;
            return;
        }
        if (front == -1) { // First element
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0; // Wrap around to the beginning of the array
        } else {
            rear++;
        }
        arr[rear] = value;
        size++;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from the front." << endl;
            return;
        }
        cout << "Deleted " << arr[front] << " from the front." << endl;
        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }
        size--;
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from the rear." << endl;
            return;
        }
        cout << "Deleted " << arr[rear] << " from the rear." << endl;
        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1; // Wrap around
        } else {
            rear--;
        }
        size--;
    }

    // Function to display the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX; // Wrap around
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        // Menu
        cout << "\n--- Double-Ended Queue (Deque) ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            dq.insertFront(value);
            break;
        case 2:
            cout << "Enter value to insert at rear: ";
            cin >> value;
            dq.insertRear(value);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


