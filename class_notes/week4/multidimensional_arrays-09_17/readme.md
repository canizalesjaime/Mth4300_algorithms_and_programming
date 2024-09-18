# Lecture Notes

## table of contents
1. Solutions to in class assignments 
2. Arrays Continued
3. In class assignments


## Solutions to in class assignments 
1. Create a program that reads 10 real numbers from the standard input and calculates their sum. After the user enters the 10 numbers the program should print all the numbers entered by the user, and also print the sum of the numbers. [Solution](./class_assignment_solutions/question1.cpp)
2. Create a program that reads real numbers of type double from the user input until it reads a negative number or zero. The negative number (or zero) means that the input is over. You are allowed to assume that the input from the user will contain at least one positive element. The program should calculate the maximum of the numbers provided by the user.[Solution](./class_assignment_solutions/question2.cpp)


## Arrays Continued
In C++, an array is a data structure that can hold a fixed-size sequence of elements of the same type. Arrays are useful for storing multiple values in a single variable and can be accessed using an index.


#### Array Size
The size of an array is fixed when it is declared. However, you can use the sizeof operator to determine the number of elements in an array:

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array size: " << size; // Outputs 5
    return 0;
}
```

### Multidimensional Arrays
C++ also supports multidimensional arrays, such as 2D arrays, which can be visualized as tables.

**Syntax:**

```cpp
type arrayName[rows][columns];
```

#### Example:

```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```
You can access elements in a 2D array using two indices:

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << matrix[0][0]; // Outputs 1
    cout << matrix[1][2]; // Outputs 6
    return 0;
}
```
### Key Points
* Arrays have a fixed size, which must be known at compile time.
* The size of the array can be determined using sizeof(array) / sizeof(array[0]).
* Elements are accessed using zero-based indexing.


## In class assignments
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