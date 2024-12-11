#include<iostream>
using namespace std;

class node {
public:
    int bit;
    node *next;
    node *prev;
};

// CREATING DOUBLY LINKED LIST
class dll {
public:
    node *head;
    node *tail;
    dll() {
        head = NULL;
        tail = NULL;
    }
    node *create_bn();  // Create binary number
    void display();      // Display binary number
    node *ones_comp();  // Calculate one's complement
    void twos_comp();    // Calculate two's complement
    void addition();     // Addition of two binary numbers
};

// CREATING BINARY NUMBER
node *dll::create_bn() {
    int n, i;
    cout << "\nEnter number of bits: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        node *p = new node;
        cout << "\nEnter bit (0 or 1): ";
        cin >> p->bit;
        if (p->bit != 0 && p->bit != 1) {
            cout << "Invalid bit. Enter 0 or 1.\n";
            i--;
            delete p;
            continue;
        }
        p->prev = NULL;
        p->next = NULL;
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
    cout << "\nEntered binary number is: ";
    display();
    return head;
}

// DISPLAYING LINKED LIST
void dll::display() {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->bit << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ONE'S COMPLEMENT
node *dll::ones_comp() {
    node *temp = head;
    cout << "\nOne's complement is: ";
    while (temp != NULL) {
        if (temp->bit == 1)
            cout << 0 << " ";
        else
            cout << 1 << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

// TWO'S COMPLEMENT
void dll::twos_comp() {
    node *temp = head;
    cout << "\nTwo's complement is: ";
    int flag = 0;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        if (flag == 0) {
            if (temp->bit == 1)
                flag = 1;
        } else {
            if (temp->bit == 0)
                temp->bit = 1;
            else
                temp->bit = 0;
        }
        temp = temp->prev;
    }
    display();
}

// ADDITION OF TWO BINARY NUMBERS
void dll::addition() {
    node *l1, *l2;
    node *head1, *head2;
    int cy = 0;
    int a[20] = {0};
    int count = 0;
    int i;
    
    cout << "\nEnter 1st binary number: ";
    head1 = create_bn();
    l1 = tail;
    
    cout << "\nEnter 2nd binary number: ";
    head2 = create_bn();
    l2 = tail;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->bit == l2->bit && l1->bit == 0) {
            a[count] = 0 + cy;
            cy = 0;
        } else if (l1->bit == l2->bit && l1->bit == 1) {
            a[count] = 0 + cy;
            cy = 1;
        } else {
            if (cy == 1) {
                a[count] = 0;
                cy = 1;
            } else {
                a[count] = 1;
                cy = 0;
            }
        }
        count++;
        l1 = l1->prev;
        l2 = l2->prev;
    }

    while (l1 != NULL) {
        if (l1->bit == 0) {
            if (cy == 0)
                a[count] = 0;
            else {
                a[count] = 1;
                cy = 0;
            }
        } else {
            if (cy == 0)
                a[count] = 1;
            else {
                a[count] = 0;
                cy = 1;
            }
        }
        count++;
        l1 = l1->prev;
    }

    while (l2 != NULL) {
        if (l2->bit == 0) {
            if (cy == 0)
                a[count] = 0;
            else {
                a[count] = 1;
                cy = 0;
            }
        } else {
            if (cy == 0)
                a[count] = 1;
            else {
                a[count] = 0;
                cy = 1;
            }
        }
        count++;
        l2 = l2->prev;
    }

    cout << "\nAddition of two binary numbers is: ";
    if (cy == 1)
        cout << "\nCARRY IS: " << cy << " ";
    for (i = count - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    dll d1;
    int choice;
    do {
        cout << "\nMENU\n1. CREATE BINARY NUMBER\n2. ONE'S COMPLEMENT\n3. TWO'S COMPLEMENT\n4. ADDITION\n5. EXIT";
        cout << "\nENTER CHOICE= ";
        cin >> choice;
        switch (choice) {
        case 1:
            d1.create_bn();
            break;
        case 2:
            d1.ones_comp();
            break;
        case 3:
            d1.twos_comp();
            break;
        case 4:
            d1.addition();
            break;
        case 5:
            cout << "EXIT" << endl;
            return 0;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice <= 5);
    return 0;
}
