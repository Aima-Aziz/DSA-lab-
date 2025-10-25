#include <iostream>
using namespace std;

// -----------------------------
// Inventory Class
// -----------------------------
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    // Constructors
    Inventory() {
        serialNum = 0;
        manufactYear = 0;
        lotNum = 0;
    }

    Inventory(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Set data
    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Display data
    void display() const {
        cout << "Serial Number : " << serialNum << endl;
        cout << "Manufact Year : " << manufactYear << endl;
        cout << "Lot Number    : " << lotNum << endl;
    }
};

// -----------------------------
// Node Class for Linked List
// -----------------------------
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory inv) {
        data = inv;
        next = NULL;
    }
};

// -----------------------------
// Stack Class (using Linked List)
// -----------------------------
class Stack {
private:
    Node* top; // pointer to the top of stack

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(Inventory inv) {
        Node* newNode = new Node(inv);
        newNode->next = top;
        top = newNode;
        cout << "Part added to inventory.\n";
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Inventory is empty! No part to remove.\n";
            return;
        }

        cout << "\nRemoved Part Details:\n";
        top->data.display();

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek top element (optional helper)
    void peek() {
        if (isEmpty()) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "\nTop Part Details:\n";
        top->data.display();
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display all items
    void displayAll() {
        if (isEmpty()) {
            cout << "No parts left in inventory.\n";
            return;
        }

        cout << "\nRemaining Parts in Inventory:\n";
        Node* temp = top;
        while (temp != NULL) {
            cout << "-------------------------\n";
            temp->data.display();
            temp = temp->next;
        }
    }
};

// -----------------------------
// Main Function
// -----------------------------
int main() {
    Stack inventoryStack;
    int choice;

    cout << "===== INVENTORY MANAGEMENT SYSTEM =====\n";

    do {
        cout << "\n1. Add part to inventory";
        cout << "\n2. Remove part from inventory";
        cout << "\n3. View top part";
        cout << "\n4. Exit and display all parts";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int serial, year, lot;
            cout << "\nEnter Serial Number: ";
            cin >> serial;
            cout << "Enter Manufacture Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory newPart(serial, year, lot);
            inventoryStack.push(newPart);
        }
        else if (choice == 2) {
            inventoryStack.pop();
        }
        else if (choice == 3) {
            inventoryStack.peek();
        }
        else if (choice == 4) {
            cout << "\nExiting program...\n";
            inventoryStack.displayAll();
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
