#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    string prn;
    Node* next;
    Node(int r, string p) {
        rollNo = r;
        prn = p;
        next = NULL;
    }
};

class PinnacleClub {
public:
    Node* head = NULL;

    void add(int r, string p) {
        Node* newNode = new Node(r, p);
        if (head == NULL) {
            head = newNode;
            return;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteMem(int r) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        Node* prev;
        if (head->rollNo == r) {
            cout << "Member to be deleted is president" << endl;
            head = head->next;
            delete temp;
        } else {
            while (temp != NULL && temp->rollNo != r) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Roll number not found" << endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        while (temp != NULL) {
            cout << "Roll no:- " << temp->rollNo << " PRN : " << temp->prn << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int totalStudents() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Total students are :- " << count << endl;
        return count;
    }

    void Concatenate(PinnacleClub c) {
        Node* h2 = c.head;
        Node* temp = head;
        if (head == NULL) {
            head = h2;
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = h2;
    }

    void displayInRev(Node* head) {
        Node* temp = head;
        if (temp == NULL) {
            return;
        }
        displayInRev(temp->next);
        cout << "Roll no :- " << temp->rollNo << " PRN : " << temp->prn << " --> ";
    }
};

int main() {
    PinnacleClub c1;
    int choice;

    do {
        cout << "\n*** Menu ***" << endl;
        cout << "1. Add member" << endl;
        cout << "2. Delete member" << endl;
        cout << "3. Display members" << endl;
        cout << "4. Display total members" << endl;
        cout << "5. Display members in reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int rollNo;
                string prn;
                cout << "Enter roll number: ";
                cin >> rollNo;
                cout << "Enter PRN: ";
                cin >> prn;
                c1.add(rollNo, prn);
                break;
            }
            case 2: {
                int rollNo;
                cout << "Enter roll number to delete: ";
                cin >> rollNo;
                c1.deleteMem(rollNo);
                break;
            }
            case 3:
                c1.display();
                break;
            case 4:
                c1.totalStudents();
                break;
            case 5:
                cout << "Members in reverse order: " << endl;
                c1.displayInRev(c1.head);
                cout << "NULL" << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
