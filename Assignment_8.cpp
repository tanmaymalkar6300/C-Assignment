Assignment 8 


CODE


#include <iostream>

using namespace std;


struct Node {

    int data;

    Node* next;

    Node* prev;

};


Node* head3 = nullptr;


void createNode(Node*& head, int data) {

    Node* newNode = new Node;

    newNode->data = data;

    newNode->next = nullptr;

    newNode->prev = nullptr;


    if (head == nullptr) {

        head = newNode;

    } else {

        Node* curr = head;

        while (curr->next != nullptr) {

            curr = curr->next;

        }

        curr->next = newNode;

        newNode->prev = curr;

    }

}


void displayList(Node* head) {

    cout << "Binary number: ";

    while (head != nullptr) {

        cout << head->data;

        head = head->next;

    }

    cout << endl;

}


void onesComplement(Node*& head) {

    Node* curr = head;

    while (curr != nullptr) {

        curr->data = 1 - curr->data;

        curr = curr->next;

    }

}


void twosComplement(Node*& head) {

    onesComplement(head);

    Node* curr = head;

    int carry = 1;

    while (curr->next != NULL) {

        curr = curr->next;

    }

    while (carry && curr != nullptr) {

        int sum = curr->data + carry;

        carry = sum / 2;

        curr->data = sum % 2;

        curr = curr->prev;

    }

}


void addBinaryNumbers(Node*& head1, Node*& head2) {

    Node* h1 = head1;

    Node* h2 = head2;

    Node* prev = nullptr;

    int carry = 0;


    while (h1->next != NULL) {

        h1 = h1->next;

    }


    while (h2->next != NULL) {

        h2 = h2->next;

    }


    while (h1 != nullptr || h2 != nullptr) {

        int sum = carry + (h1 != nullptr ? h1->data : 0) + (h2 != nullptr ? h2->data : 0);

        carry = sum / 2;


        Node* newNode = new Node;

        newNode->data = sum % 2;

        newNode->next = nullptr;

        newNode->prev = nullptr;


        if (head3 == nullptr) {

            head3 = newNode;

        } else {

            newNode->next = prev;

        }


        prev = newNode;

        h1 = h1 != nullptr ? h1->prev : nullptr;

        h2 = h2 != nullptr ? h2->prev : nullptr;

    }


    if (carry > 0) {

        Node* newNode = new Node;

        newNode->data = carry;

        newNode->next = prev;

        newNode->prev = nullptr;

        head3 = newNode;

    }

}


int main() {

    Node* head1 = nullptr;

    createNode(head1, 1);

    createNode(head1, 0);

    createNode(head1, 0);


    Node* head2 = nullptr;

    createNode(head2, 1);

    createNode(head2, 1);

    createNode(head2, 1);


    cout << "Binary number 1: ";

    displayList(head1);


    cout << "Binary number 2: ";

    displayList(head2);


    cout << "1's complement of binary number 1: ";

    onesComplement(head1);

    displayList(head1);


    cout << "2's complement of binary number 1: ";

    twosComplement(head1);

    displayList(head1);


    addBinaryNumbers(head1, head2);

    cout << "Sum of binary numbers: ";

    displayList(head3);


    return 0;

}


