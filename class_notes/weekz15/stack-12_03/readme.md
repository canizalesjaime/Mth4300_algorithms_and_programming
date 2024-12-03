# Lecture notes

## table of contents
1. Solution to in class assignments
2. Stacks
3. Class Assignments


## Solution to in class assignments
1. Add a function to the BST data structure to return the height of the BST. [Solution](./class_assignment_solutions/main.cpp)

## Stacks
A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle, meaning the last element added to the stack is the first one to be removed. It can be visualized as a collection of items stacked on top of each other, where only the topmost item can be accessed or removed.

### Key Operations of a Stack:
* **Push:** Adds an element to the top of the stack.
* **Pop:** Removes the element from the top of the stack.
* **Peek (or Top):** Retrieves the top element without removing it.
* **isEmpty:** Checks if the stack is empty.

### Stack Implementation in C++
A stack can be implemented in C++ using:

1. The STL ```stack``` class (preferred for simplicity and efficiency).
2. Manual implementation using arrays or linked lists.

### Using STL stack:
The C++ Standard Template Library (STL) provides a ready-made stack class.
Example:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Display the top element
    cout << "Top element: " << s.top() << endl;  // Output: 30

    // Pop an element
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // Output: 20

    // Check if the stack is empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
```

### Manual Implementation Using Arrays:
Here’s how to manually implement a stack using arrays:
Example:

```cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;  // Output: 30

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;  // Output: 20

    s.pop();
    s.pop();
    s.pop();  // Stack underflow!

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
```

### Manual Implementation Using Linked Lists:
This approach uses dynamic memory allocation and is more flexible than arrays.

Example:
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;  // Output: 30

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;  // Output: 20

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
```

### Advantages of a Stack:
* Simplicity: Ideal for solving problems like reversing a string or validating parentheses.
* Efficient: Push and pop operations are O(1).
* Useful in algorithms like depth-first search, function call stacks, etc.

### Applications of a Stack:
* **Expression Evaluation:** Parsing and evaluating expressions (e.g., postfix evaluation).
* **Undo Mechanism:** Used in text editors for undo operations.
* **Recursion:** Call stack in programming.
* **Depth-First Search (DFS):** Used in graph and tree traversal algorithms.

## Class assignments
1. Write a program to implement a stack in C++ that checks if a given string of parentheses is balanced. A string is considered balanced if:
   * Every opening parenthesis ```(,{,[``` has a corresponding and correctly placed closing parenthesis ```), \}, \]```.
   * Closing parentheses match the most recently opened parentheses.

   You need to:
   * Implement the stack manually using arrays or STL stack.
   * Write a function bool isBalanced(string str) to check if a string is balanced.
   * Test the function with sample inputs.
2. Solve the for the nth fibonacci number using a stack instead of recursion.