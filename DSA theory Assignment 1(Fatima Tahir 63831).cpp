#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Insert node at the end
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display the list
void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete from beginning
void deleteBeginning() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
    cout << "Deleted from beginning\n";
}

// Delete from end
void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    // Only one node
    if (temp->next == nullptr) {
        delete temp;
        head = nullptr;
        cout << "Deleted from end\n";
        return;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
    cout << "Deleted from end\n";
}

// Delete at given position (1-based index)
void deleteAtPosition(int pos) {
    if (head == nullptr || pos <= 0) {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Deleted at position " << pos << "\n";
}

// Main function
int main() {
    // Inserting nodes
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    display(); // 10 20 30 40 50

    deleteBeginning(); // Delete 10
    display();         // 20 30 40 50

    deleteEnd();       // Delete 50
    display();         // 20 30 40

    deleteAtPosition(2); // Delete 30
    display();           // 20 40

    return 0;
}