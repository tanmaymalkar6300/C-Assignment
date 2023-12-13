Assignment 9 


CODE


#include <iostream>

#include <stack>

using namespace std;


// Function to print the original string and its reversed form using a stack

void printOriginalAndReverse(string str) {

    stack<char> s;


    // Push characters of the original string into the stack

    for (char ch : str) {

        s.push(ch);

    }


    // Initialize an empty string to store the reversed characters

    string reversedString = "";


    // Pop characters from the stack and append them to the reversed string

    while (!s.empty()) {

        reversedString = reversedString + s.top();  // Append at the beginning

        s.pop();

    }


    // Print the original string and its reversed form

    cout << "Original String: " << str << endl;

    cout << "Reversed String: " << reversedString << endl;

}


// Function to check if the given string is a palindrome or not

bool isPalindrome(string str) {

    int n = str.length();


    // Compare characters from both ends of the string

    for (int i = 0; i < n / 2; ++i) {

        if (str[i] != str[n - 1 - i]) {

            return false;

        }

    }


    // If all characters match, the string is a palindrome

    return true;

}


int main() {

    string str = "madam";


    // Print the original string and its reversed form

    printOriginalAndReverse(str);


    // Check if the string is a palindrome

    if (isPalindrome(str)) {

        cout << "The given string is a palindrome" << endl;

    } else {

        cout << "The given string is not a palindrome" << endl;

    }


    return 0;

}


