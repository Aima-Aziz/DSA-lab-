#include <iostream>
#include <string>
using namespace std;

// Define the structure for a Node (Book)
class Node {
public:
    string title;
    float price;
    int edition;
    int pages;
    Node* next; // pointer to next node

    // Constructor
    Node(string t, float p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
        next = NULL;
    }
};

// Stack class
class BookStack {
private:
    Node* top; // points to top of stack

public:
    BookStack() {
        top = NULL;
    }

    // Push function
    void push(string t, float p, int e, int pg) {
        Node* newNode = new Node(t, p, e, pg);
        newNode->next = top;
        top = newNode;
        cout << "Book pushed: " << t << endl;
    }

    // Pop function
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        cout << "Book popped: " << top->title << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek function (to show top element)
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nTop Book Details:\n";
        cout << "Title: " << top->title << endl;
        cout << "Price: " << top->price << endl;
        cout << "Edition: " << top->edition << endl;
        cout << "Pages: " << top->pages << endl;
    }

    // Display all books in the stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\nBooks in Stack:\n";
        Node* temp = top;
        while (temp != NULL) {
            cout << "-----------------------------\n";
            cout << "Title: " << temp->title << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Edition: " << temp->edition << endl;
            cout << "Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

// Main function
int main() {
    BookStack stack;

    // 1. Push 5 books
    stack.push("C++ Programming", 899.50, 3, 550);
    stack.push("Data Structures", 750.00, 2, 420);
    stack.push("Operating Systems", 1200.75, 4, 680);
    stack.push("Database Systems", 950.25, 5, 610);
    stack.push("Software Engineering", 1050.90, 3, 500);

    // 2. Find the top element
    stack.peek();

    // 3. Pop 2 books
    stack.pop();
    stack.pop();

    // 4. Display remaining books
    stack.display();

    return 0;
}
