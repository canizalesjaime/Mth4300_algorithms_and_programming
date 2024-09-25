# Lecture Notes

## table of contents
1. Solutions to in class assignments 
2. Dynamic Memory
3. In class assignments


## Solutions to in class assignments 
1. Write a C++ program that does the following:<br>
   * Creates an integer variable and initializes it with a value (e.g., 42).
   * Creates a pointer to that integer variable.
   * Using the pointer, display the value of the integer variable.
   * Modify the value of the integer variable using the pointer, and then display the updated value.
[Solution](./class_assignment_solutions/question1.cpp)


## Dynamic Memory
In C++, dynamic memory refers to memory that is allocated at runtime using pointers, rather than being predefined at compile-time. It allows programs to request memory from the system's heap during execution. This approach offers flexibility, particularly when dealing with data whose size is unknown before the program runs.

### Key Concepts of Dynamic Memory in C++:
1. Heap vs. Stack:
   * **Stack:** Automatically managed memory where local variables and function call data are stored. Memory is allocated and deallocated automatically when functions are called and returned.<br>
   * **Heap:** Dynamically allocated memory that must be managed explicitly by the programmer using pointers. It’s ideal for memory whose size may change or isn’t known at compile time.

2. Pointers:
   * Dynamic memory in C++ is accessed via pointers. A pointer holds the memory address of a value rather than the value itself.

3. Memory Allocation and Deallocation:
   * C++ provides the new and delete operators for dynamic memory management:
     * new: Allocates memory dynamically.
     * delete: Frees dynamically allocated memory.


### Dynamic Memory Allocation Syntax:
Allocating memory using new:

```cpp
int* ptr = new int;  // Allocates memory for an integer
*ptr = 42;           // Assigns the value 42 to the allocated memory
```
This allocates memory for an integer in the heap, and ptr is a pointer that stores the address of that allocated memory.

Deallocating memory using delete:

```cpp
delete ptr;  // Frees the dynamically allocated memory
```
After freeing the memory, ptr still holds the memory address, so it's a good practice to set it to nullptr:

```cpp
ptr = nullptr;
```

Allocating Arrays Dynamically:
To allocate an array dynamically, use new[]:


```cpp
int* arr = new int[5];  // Allocates memory for an array of 5 integers
```

To free memory allocated for an array, use delete[]:

```cpp
delete[] arr;  // Frees the dynamically allocated array memory
```

### Example of Dynamic Memory Allocation in C++:
```cpp
#include <iostream>
using namespace std;

int main() {
    int* p = new int;     // Dynamically allocate memory for an integer
    *p = 10;              // Assign the value 10 to that memory
    cout << "Value: " << *p << endl;  // Output the value

    delete p;             // Deallocate memory
    p = nullptr;          // Avoid dangling pointers by setting it to nullptr

    // Dynamically allocating an array
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    delete[] arr;  // Deallocate the array memory
    arr = nullptr; // Avoid dangling pointer

    return 0;
}
```

### Important Considerations:
1. **Memory Leaks:**
   * If memory allocated with ```new``` is not deallocated using ```delete```, it leads to memory leaks. This means that memory is no longer accessible by the program, but it remains occupied, reducing available system resources.

2. **Dangling Pointers:**
   * A pointer that points to memory that has been deallocated (freed) is called a dangling pointer. Using such pointers can cause undefined behavior. Always ensure that pointers are either properly reallocated or set to nullptr after delete.

3. **Smart Pointers:**
   * Modern C++ (C++11 and later) introduces smart pointers (such as ```std::unique_ptr```, ```std::shared_ptr```, etc.), which automatically manage memory and help avoid manual memory management pitfalls like leaks and dangling pointers.
  
#### Example with Smart Pointers (C++11):
```cpp
#include <memory>  // Include smart pointer library
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);  // Automatically handles memory
    std::cout << "Value: " << *ptr << std::endl;           // No need for manual delete

    // Automatically deallocated when the pointer goes out of scope
    return 0;
}
```
More on this topic later when we cover templates!


### Summary:
Dynamic memory in C++ allows for flexible memory management, particularly useful when the size of data structures is not known at compile time. However, it requires careful management to avoid memory leaks and other issues. With modern C++ standards, smart pointers can help manage dynamic memory more safely and efficiently.


## In class assignments
1. Something else
