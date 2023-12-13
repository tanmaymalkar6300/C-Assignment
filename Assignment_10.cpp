Assignment 10


CODE


#include <iostream>

#include <stack>


using namespace std;


int getOperatorPrecedence(char op) {

    switch (op) {

    case '+':

    case '-':

        return 1;

    case '*':

    case '/':

        return 2;

    default:

        return 0;

    }

}

string infixToPostfix(string exp) {

    stack<char> st;

    string postfixExp;


    for (char ch : exp) {

        if (isalnum(ch)) {

            postfixExp += ch;

        } else if (ch == '(') {

            st.push(ch);

        } else if (ch == ')') {

            while (!st.empty() && st.top() != '(') {

                postfixExp += st.top();

                st.pop();

            }

            if (st.empty()) {

                cout << "Invalid expression" << endl;

                return "";

            }

            st.pop();

        } else {

            while (!st.empty() && getOperatorPrecedence(st.top()) >= getOperatorPrecedence(ch)) {

                postfixExp += st.top();

                st.pop();

            }

            st.push(ch);

        }

    }


    while (!st.empty()) {

        postfixExp += st.top();

        st.pop();

    }


    return postfixExp;

}


int evaluatePostfix(string exp) {

    stack<int> st;


    for (char ch : exp) {

        if (isdigit(ch)) {

            int operand = ch - '0';

            st.push(operand);

        } else {

            int operand2 = st.top();

            st.pop();

            int operand1 = st.top();

            st.pop();


            int result;


            switch (ch) {

            case '+':

                result = operand1 + operand2;

                break;

            case '-':

                result = operand1 - operand2;  // Swap operand1 and operand2 for subtraction

                break;

            case '*':

                result = operand1 * operand2;

                break;

            case '/':

                result = operand1 / operand2;  // Swap operand1 and operand2 for division

                break;

            }


            st.push(result);

        }

    }


    return st.top();

}


int main() {

    string infixExp = "11+4*2";

    string postfixExp = infixToPostfix(infixExp);

    cout << "Postfix expression: " << postfixExp << endl;


    int result = evaluatePostfix(postfixExp);

    cout << "Result: " << result << endl;


    return 0;

}


