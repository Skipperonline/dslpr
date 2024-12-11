#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class STACK {
private:
    char a[50];
    int top;

public:
    STACK() {
        top = -1;
    }
    void push(char);
    void reverse();
    void convert(char[]);
    void palindrome(const char[]);
};

void STACK::push(char c) {
    if (top < 49) {
        a[++top] = c;
        cout << endl << c << " is pushed on stack...";
    } else {
        cout << "Stack overflow! Cannot push " << c << endl;
    }
}

void STACK::reverse() {
    cout << "\n\nReverse string is: ";
    for (int i = top; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

void STACK::convert(char str[]) {
    int j, k, len = strlen(str);
    for (j = 0, k = 0; j < len; j++) {
        if (isalpha(str[j])) {
            if (isupper(str[j])) {
                str[k] = tolower(str[j]);
            } else {
                str[k] = str[j];
            }
            k++;
        }
    }
    str[k] = '\0';
    cout << endl << "Converted string: " << str << "\n";
}

void STACK::palindrome(const char original[]) {
    char str[50];
    int i, j;

    for (i = top, j = 0; i >= 0; i--, j++) {
        str[j] = a[i];
    }
    str[j] = '\0';

    if (strcmp(str, original) == 0)
        cout << "\n\nString is a palindrome...";
    else
        cout << "\n\nString is not a palindrome...";
}

int main() {
    STACK stack;
    char str[50], originalStr[50];
    int i = 0;

    cout << "\nEnter string to be reversed and check if it is a palindrome or not: \n\n";
    cin.getline(str, 50);

    strcpy(originalStr, str);

    stack.convert(str);

    while (str[i] != '\0') {
        stack.push(str[i]);
        i++;
    }

    stack.palindrome(originalStr);

    stack.reverse();

    return 0;
}

