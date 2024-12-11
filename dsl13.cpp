#include <iostream>
using namespace std;

const int MAX = 5;  // Maximum size of the pizza parlour queue

class PizzaParlour {
private:
    int front, rear;
    int orders[MAX];

public:
    PizzaParlour() {
        front = rear = -1;  // Initialize the queue to empty state
    }

    bool addOrder(int id);  // Function to add an order
    void serveOrder();  // Function to serve an order
    void display();  // Function to display all orders
};

bool PizzaParlour::addOrder(int id) {
    if (front == -1) {  // Queue is empty
        front = rear = 0;  // Set front and rear to 0
        orders[rear] = id;  // Place the order at the rear
        return true;
    } else {
        int pos = (rear + 1) % MAX;  // Circular increment
        if (pos == front) {  // Queue is full
            cout << "\nCafe is Full. Please wait.\n";
            return false;
        } else {
            rear = pos;  // Update the rear index
            orders[rear] = id;  // Add the order at the new rear
            return true;
        }
    }
}

void PizzaParlour::serveOrder() {
    if (front == -1) {  // Queue is empty
        cout << "\nNo Orders in Cafe. [Cafe is Empty]\n";
        return;
    } else {
        cout << "\nOrder No. " << orders[front] << " is processed.\n";
        if (front == rear) {  // Only one order left
            front = rear = -1;  // Reset queue to empty
        } else {
            front = (front + 1) % MAX;  // Move front to next position
        }
    }
}

void PizzaParlour::display() {
    if (front == -1) {  // Queue is empty
        cout << "\nCafe is Empty. No orders.\n";
        return;
    } else {
        cout << "Order Id's: \n";
        for (int i = front; i != rear; i = (i + 1) % MAX) {  // Traverse the circular queue
            cout << orders[i] << " ";
        }
        cout << orders[rear] << "\n";  // Display the last order
    }
}

void intro() {
    const char name[] = "\n Pizza Cafe \n";
    cout << name;  // Directly output the cafe name
}

int main() {
    int ch, id = 0;
    PizzaParlour q;

    do {
        cout << "\n-----------------";
        intro();
        cout << "-----------------";
        cout << "\n****Menu*****\n";
        cout << "1. Accept order\n";
        cout << "2. Serve order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:  // Accept a new order
                id++;
                if (q.addOrder(id)) {
                    cout << "Thank you for the order. Order id is: " << id << "\n";
                } else {
                    id--;  // Decrease id if the order cannot be added due to overflow
                }
                break;
            case 2:  // Serve an order
                q.serveOrder();
                break;
            case 3:  // Display all orders
                q.display();
                break;
            case 4:  // Exit
                cout << "\nThank You. Keep Visiting.\n";
                break;
            default:  // Invalid choice
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 4);

    return 0;
}
