Assignment 10

CODE

#include <iostream>
using namespace std;

#define size 20 // Increase the array size to accommodate longer expressions

class stackexp {
    int top;
    char stk[size];

public:
    stackexp() {
        top = -1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x) {
    if (top < size - 1) {
        top = top + 1;
        stk[top] = x;
    } else {
        cout << "\nStack Overflow. Expression is too long.\n";
        exit(1); // Terminate the program
    }
}

char stackexp::pop() {
    if (top >= 0) {
        char s = stk[top];
        top = top - 1;
        return s;
    } else {
        cout << "\nStack Underflow. Trying to pop from an empty stack.\n";
        exit(1); // Terminate the program
    }
}

int stackexp::isfull() {
    return top == size - 1;
}

int stackexp::isempty() {
    return top == -1;
}

int main() {
    stackexp s1;
    char exp[size], ch;
    int i = 0;

    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;

    cout << "\nEnter the expression to check whether it is in well form or not : ";
    cin.getline(exp, size);

    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')) {
        cout << "\nInvalid Expression.....\n";
        return 0;
    } else {
        while (exp[i] != '\0') {
            ch = exp[i];
            switch (ch) {
            case '(':
            case '[':
            case '{':
                s1.push(ch);
                break;
            case ')':
                if (s1.isempty() || s1.pop() != '(') {
                    cout << "\nInvalid Expression or not in well parenthesized....\n";
                    return 0;
                }
                break;
            case ']':
                if (s1.isempty() || s1.pop() != '[') {
                    cout << "\nInvalid Expression or not in well parenthesized....\n";
                    return 0;
                }
                break;
            case '}':
                if (s1.isempty() || s1.pop() != '{') {
                    cout << "\nInvalid Expression or not in well parenthesized....\n";
                    return 0;
                }
                break;
            }
            i = i + 1;
        }
    }

    if (s1.isempty()) {
        cout << "\nExpression is well parenthesized...\n";
    } else {
        cout << "\nInvalid Expression or not in well parenthesized....\n";
    }

    return 0;
}
