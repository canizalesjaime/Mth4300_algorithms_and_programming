# Lecture Notes

## table of contents
1. Solutions to in class assignments 
2. Recursion
3. Pointers
4. In class assignments


## Solutions to in class assignments 
1. Write a C++ program, that prompts the user for the number of rows and 
columns in a 2-dimensional array. For each cell in the 2d array, if the column
is even compute row raised to column(r^c) and store in that cell, otherwise 
store 0. For row 0 and col 0(arr[0][0]), you can just store 0(since indeterminate).
Print the computed 2d array. 

**Example:** let the input be 4 for row and 5 for column, then the output will be:<br>
```math
\begin{bmatrix}
 0 & 0 & 0 & 0 & 0 \\
 1 & 0 & 1 & 0 & 1 \\
 1 & 0 & 2 & 0 & 4 \\
 1 & 0 & 3 & 0 & 9 
\end{bmatrix}
```
[Solution](./class_assignment_solutions/question1.cpp)


## Recursion
In C++, recursion is a process in which a function calls itself, either directly or indirectly, to solve a problem. This approach divides a larger problem into smaller sub-problems, solving each one by breaking it down until reaching a base case, which is the simplest form of the problem that can be solved directly.

### Key components of recursion:
* Base Case: The condition that stops the recursive calls to prevent infinite recursion. It directly returns a result without making further recursive calls.
* Recursive Case: The part of the function where the problem is broken down into smaller sub-problems, and the function calls itself with a modified argument.
 

### Example of Recursion in C++
Let's consider a simple example where we calculate the factorial of a number using recursion:

```cpp
#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        // Base case: factorial of 0 is 1
        return 1;
    } else {
        // Recursive case: n * factorial of (n-1)
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 5;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}
```

#### How it works:
* Base Case: if (n == 0) stops the recursion and returns 1.
* Recursive Case: For values greater than 0, the function calls itself with n-1.
In this example:

* factorial(5) calls factorial(4), which calls factorial(3), and so on until factorial(0), which returns 1.
* Then, the calls unwind and the results are multiplied to give the final result.

### Advantages of Recursion:
* Simpler and more intuitive code for problems that can naturally be broken into sub-problems (e.g., factorial, Fibonacci, tree traversal).

### Disadvantages of Recursion:
* Can be inefficient in terms of both time and space due to repeated function calls and stack memory usage.
* Risk of stack overflow if recursion depth becomes too large.
Recursion is a powerful tool but should be used with care, especially for problems that can have a large depth of recursive calls.


## Pointers
In C++, a pointer is a variable that stores the memory address of another variable. Pointers are a powerful feature that allow for direct memory manipulation, efficient array management, and dynamic memory allocation, among other capabilities.

### Key Concepts:
* Pointer Declaration: A pointer is declared by specifying the data type it points to, followed by an asterisk (*) before the pointer name.
```cpp
int *ptr;  // ptr is a pointer to an integer
```

* Pointer Initialization: Pointers hold the memory address of another variable, which is assigned using the address-of operator (&).
```cpp
int a = 10;
int *ptr = &a;  // ptr holds the address of variable a
```

* Dereferencing a Pointer: Dereferencing a pointer means accessing the value stored at the memory address held by the pointer. This is done using the dereference operator (*).
```cpp
int a = 10;
int *ptr = &a;
cout << *ptr;  // Outputs: 10 (value of a)
```

* Null Pointer: A pointer that does not point to any valid memory address is called a null pointer. It is often initialized with nullptr or NULL.
```cpp
int *ptr = nullptr;  // ptr points to nothing
```

* Pointer Arithmetic: Pointers can be incremented or decremented, which advances or rewinds the memory address by the size of the data type it points to. This is commonly used with arrays.

```cpp
int arr[] = {1, 2, 3};
int *ptr = arr;  // ptr points to the first element of the array
ptr++;           // Now ptr points to the second element of the array
```

### Example of Pointers in C++
```cpp
#include <iostream>
using namespace std;

int main() {
    int var = 20;       // Declare an integer variable
    int *ptr = &var;    // Declare a pointer that holds the address of var
    
    cout << "Address of var: " << ptr << endl;     // Prints the memory address
    cout << "Value of var: " << *ptr << endl;      // Dereferences the pointer to get the value of var
    
    return 0;
}
```

#### Output:
```less
Address of var: 0x7ffc2c7f10b8
Value of var: 20
```


#### Common Uses of Pointers:
* Dynamic Memory Allocation: Pointers are used with new and delete to allocate and deallocate memory dynamically.

```cpp
int *p = new int;  // Allocates memory for an integer
*p = 10;
delete p;  // Frees the allocated memory
```
* Arrays and Functions: Pointers are commonly used to pass arrays or large data structures to functions to avoid copying.

```cpp
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
```
* Pointer to Pointer: Pointers can also point to other pointers, enabling multi-level indirection.

```cpp
int a = 5;
int *p = &a;     // Pointer to integer
int **q = &p;    // Pointer to pointer
```

### Advantages of Pointers:
* Efficiency: Pointers allow efficient handling of arrays, strings, and large data structures by passing memory addresses instead of copying data.
* Dynamic Memory Management: They enable dynamic memory allocation, allowing programs to handle memory at runtime.
* Flexibility: Pointers provide direct memory access, which is crucial for system-level programming.

### Disadvantages of Pointers:
* Complexity: Improper use of pointers can lead to hard-to-debug errors like memory leaks, dangling pointers, or crashes.
* Security Risks: Unchecked pointer operations can result in vulnerabilities such as buffer overflow or segmentation faults.

Pointers are a fundamental aspect of C++ that, when used correctly, provide great control and flexibility. However, they require careful management to avoid issues such as memory corruption.


## In class assignments
1. In C++, write a function that computes the nth fibonacci number from the 
fibonacci sequence. Make sure to use recursion in your function.
2. Write a C++ program that does the following:<br>
* Creates an integer variable and initializes it with a value (e.g., 42).
* Creates a pointer to that integer variable.
* Using the pointer, display the value of the integer variable.
* Modify the value of the integer variable using the pointer, and then display the updated value.
  
