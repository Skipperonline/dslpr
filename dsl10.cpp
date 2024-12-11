#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#define MAX 100
using namespace std;

class Stack {
    char stk[MAX];
    int top;
public:
    Stack() : top(-1) {}

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX - 1; }

    char peek() {
        if (!isEmpty()) {
            return stk[top];
        }
        return '\0';
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return stk[top--];
    }

    void push(char ch) {
        if (!isFull()) {
            stk[++top] = ch;
        }
    }
};

class ExpressionEvaluator {
    Stack stack;
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int precedence(char ch) {
        switch (ch) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return -1;
        }
    }

    bool isLeftAssociative(char op) {
        return op != '^';
    }

    void convertToPostfix(char *expression, char *postfix) {
        int j = 0;
        for (int i = 0; expression[i]; ++i) {
            if (isDigit(expression[i])) {
                postfix[j++] = expression[i];
            } else if (expression[i] == '(') {
                stack.push(expression[i]);
            } else if (expression[i] == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix[j++] = stack.pop();
                }
                stack.pop();
            } else {
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(expression[i]) && isLeftAssociative(expression[i])) {
                    postfix[j++] = stack.pop();
                }
                stack.push(expression[i]);
            }
        }

        while (!stack.isEmpty()) {
            postfix[j++] = stack.pop();
        }
        postfix[j] = '\0';
    }

    int evalPostfix(char *expression) {
        int numStack[MAX];
        int numTop = -1;

        for (int i = 0; expression[i]; ++i) {
            if (isDigit(expression[i])) {
                numStack[++numTop] = expression[i] - '0';
            } else {
                int op2 = numStack[numTop--];
                int op1 = numStack[numTop--];
                switch (expression[i]) {
                    case '+':
                        numStack[++numTop] = op1 + op2;
                        break;
                    case '-':
                        numStack[++numTop] = op1 - op2;
                        break;
                    case '*':
                        numStack[++numTop] = op1 * op2;
                        break;
                    case '/':
                        numStack[++numTop] = op1 / op2;
                        break;
                    case '^':
                        numStack[++numTop] = (int)pow(op1, op2);
                        break;
                }
            }
        }

        return numStack[numTop];
    }
};

int main() {
    char expression[MAX];
    char postfix[MAX];
    ExpressionEvaluator evaluator;

    cout << "Enter an infix expression: ";
    cin.getline(expression, MAX);
    cout << "Original Expression: " << expression << "\n";

    evaluator.convertToPostfix(expression, postfix);
    cout << "Postfix Expression: " << postfix << "\n";

    int result = evaluator.evalPostfix(postfix);
    cout << "Evaluation of postfix expression: " << result << "\n";

    return 0;
}

