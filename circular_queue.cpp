#include <iostream>
#define SIZE 5  // Size of the circular queue

using namespace std;

class CircularQueue {
   private:
    int items[SIZE];
    int front, rear;

   public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue an element
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        } else if (isEmpty()) {  // First element to be enqueued
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;  // Move rear in circular manner
        }
        items[rear] = element;
        cout << "Inserted " << element << endl;
    }

    // Dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int element = items[front];
        if (front == rear) {  // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Move front in circular manner
        }
        return element;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front -> " << front << "\nItems -> ";
        int i = front;
        while (i != rear) {
            cout << items[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << items[i] << "\nRear -> " << rear << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Queue should now be full
    q.enqueue(6);  // This will fail

    q.display();  // Display the queue

    cout << "Dequeued: " << q.dequeue() << endl;  // Dequeue an element
    q.display();  // Display the queue after dequeuing

    q.enqueue(6);  // Now this should succeed
    q.display();   // Display the queue

    return 0;
}
