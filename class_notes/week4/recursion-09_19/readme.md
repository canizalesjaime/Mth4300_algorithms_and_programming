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
 1 & 0 & 4 & 0 & 16 \\
 1 & 0 & 9 & 0 & 81 
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


## In class assignments
1. In C++, write a function that computes the nth fibonacci number from the 
fibonacci sequence. Make sure to use recursion in your function.
