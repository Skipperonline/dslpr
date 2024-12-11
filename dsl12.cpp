#include <iostream>
using namespace std;

class Deque {
private:
    int* a;
    int size;
    int f;  // Front
    int r;  // Rear

public:
    Deque(int s) : size(s), f(-1), r(-1) {
        a = new int[size];  // Dynamically allocate the array
    }

    void insert_at_end(int i);
    void delete_fr_rear();
    void insert_at_beg(int i);
    void delete_fr_front();
    ~Deque() {
        delete[] a;  // Deallocate the memory
    }
};

// Insert at the end of the deque
void Deque::insert_at_end(int i) {
    if (r >= size - 1) {
        cout << "\nInsertion is not possible, overflow !!!\n";
        return;
    }
    if (f == -1) {  // If deque is empty, initialize both front and rear to 0
        f = 0;
    }
    a[++r] = i;  // Insert element at the rear
}

// Delete from the rear of the deque
void Deque::delete_fr_rear() {
    if (f == -1) {
        cout << "\nDeletion is not possible, deque is empty\n";
        return;
    }
    cout << "The deleted element is: " << a[r--] << endl;
    if (f > r) {  // Reset deque if it's empty
        f = r = -1;
    }
}

// Insert at the beginning of the deque
void Deque::insert_at_beg(int i) {
    if (f == 0 && r == size - 1) {  // Overflow condition when both front and rear are at limits
        cout << "\nInsertion is not possible, overflow !!!\n";
        return;
    }
    if (f == -1) {  // If deque is empty, initialize both front and rear to 0
        f = r = 0;
    } else if (f == 0) {  // Wrap around when front is at the beginning
        f = size - 1;
    } else {
        --f;  // Decrease the front pointer
    }
    a[f] = i;  // Insert element at the front
}

// Delete from the front of the deque
void Deque::delete_fr_front() {
    if (f == -1) {
        cout << "\nDeletion is not possible, deque is empty\n";
        return;
    }
    cout << "The deleted element is: " << a[f++] << endl;
    if (f > r) {  // Reset deque if it's empty
        f = r = -1;
    }
}

int main() {
    int n;
    cout << "Enter the size of the deque: ";
    cin >> n;

    Deque dq(n);
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at end: ";
                cin >> value;
                dq.insert_at_end(value);
                break;

            case 2:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                dq.insert_at_beg(value);
                break;

            case 3:
                dq.delete_fr_front();
                break;

            case 4:
                dq.delete_fr_rear();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
