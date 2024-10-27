# Lecture notes

## table of contents
1. Links
2. Vector Template Class
3. Class Assignments

## Links 
1. [https://cplusplus.com/reference/vector/vector/](https://cplusplus.com/reference/vector/vector/)


## Vector Template Class
A ```C++``` ```vector``` is a dynamic array that can grow or shrink in size. It is part of the Standard Template Library (STL) and is implemented as a template class to allow storage of any data type. Let's break down how a ```vector``` works as a template class and what its key components are.

### Template Class Overview
A ```template``` in C++ allows you to create generic classes or functions that can operate with any data type. The ```vector``` class is written as a template so that it can hold elements of any type (e.g., ```int```, ```double```, ```std::string```, or even user-defined types).

Here's a simplified example of a template class for a ```vector```:

```cpp
#include <iostream>

template <typename T>
class MyVector {
private:
    T* data;          // Pointer to dynamically allocated array
    size_t size;      // Number of elements currently in the vector
    size_t capacity;  // Capacity of the vector (how many elements it can hold)

public:
    // Constructor
    MyVector() : size(0), capacity(1) {
        data = new T[capacity];  // Allocate memory for 1 element
    }

    // Destructor
    ~MyVector() {
        delete[] data;  // Free dynamically allocated memory
    }

    // Method to add an element
    void push_back(const T& value) {
        if (size == capacity) {
            resize();  // Resize if capacity is reached
        }
        data[size] = value;
        size++;
    }

    // Method to access elements
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Method to get the size of the vector
    size_t getSize() const { return size; }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() {
        capacity *= 2;  // Double the capacity
        T* newData = new T[capacity];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        delete[] data;  // Delete old array
        data = newData;  // Point to new array
    }
};
```

#### Key Components of the Vector Template
* Data Member (```T* data```):
  * The vector stores a pointer to a dynamically allocated array where the elements are stored. The type ```T``` is determined when an object of ```MyVector``` is instantiated (for example, ```MyVector<int>``` would use an array of integers).

* Size and Capacity:
  * The ```size``` keeps track of the number of elements that have been added to the vector, while ```capacity``` represents the amount of allocated memory. If more elements are added than the current capacity, the array is resized (usually doubled).

* Constructor and Destructor:
  * The constructor initializes the vector with a default capacity of 1. The destructor releases the memory when the object goes out of scope to prevent memory leaks.

* push_back():
  * This function adds an element to the vector. If the vector is full (i.e., ```size == capacity```), it calls ```resize()``` to allocate a larger array and copy the existing elements to the new array.

* operator[]:
  * Overloading the ```[]``` operator allows access to elements by their index, just like an array. It also checks for out-of-bounds access.

* resize():
  * This is a helper function that reallocates memory for the vector when the current capacity is reached, ensuring that the vector can continue to grow dynamically.


### Real-world Vector Example in STL
The ```std::vector``` class in the STL works similarly, but with many more features and optimizations (e.g., iterators, range-based access, etc.). Here's how you'd use ```std::vector```:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }

    return 0;
}
```

In this case, the ```std::vector<int>``` stores integers, dynamically grows, and manages its memory efficiently without the need for manual memory management.

### Why Use a Template for Vectors?
Using templates allows you to write generic code that works with any data type. This avoids code duplication and makes the ```vector``` class versatile, enabling you to store objects of any type:

```std::vector<int>``` for integers
```std::vector<std::string>``` for strings
```std::vector<MyClass>``` for user-defined types like ```MyClass```

### Conclusion
The ```vector``` template class in C++ is a powerful and flexible way to handle dynamic arrays. By using templates, the ```vector``` class can store elements of any type, and with functions like ```push_back()``` and dynamic resizing, it efficiently manages memory and grows as needed. The STL ```std::vector``` is a well-optimized implementation of this idea.

## Class Assignments
1. In the code for the simplified vector class, add a method and name it pop_back(). pop_back() should delete the last element in your vector. 
2. Add another method call pop_front(), pop_front() should delete the first element of the vector.
3. for the Point3D class from last lecture, create a vector from the stl, and add four random points to the vector. Do this in the main function.