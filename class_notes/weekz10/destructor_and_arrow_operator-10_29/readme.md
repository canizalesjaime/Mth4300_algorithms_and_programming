# Lecture notes

## table of contents
1. Destructors
2. Arrow Operator for Pointers


## Destructors
In C++, destructors are special member functions that are automatically invoked when an object goes out of scope or is explicitly deleted. Their main purpose is to release resources acquired by the object during its lifetime, such as memory, file handles, or network connections. Destructors are crucial for preventing resource leaks, which could otherwise lead to performance issues or application crashes.

### Key points about destructors:
#### Name and syntax:
A destructor has the same name as the class, but with a tilde (~) prefix.
Destructors do not take parameters and do not return anything.
```cpp
class MyClass {
public:
    ~MyClass() {
        // Destructor logic
    }
};
```

#### Automatic invocation:
Destructors are called automatically when an object goes out of scope or is explicitly deleted using the delete keyword for dynamic objects.

##### For example:
* Automatic object: When a local object goes out of scope (end of function or block), its destructor is called automatically.
* Dynamic object: When you delete a dynamically allocated object, its destructor is called.
```cpp
void func() {
    MyClass obj;  // Constructor called here
    // Destructor called automatically when the function exits
}

MyClass* obj = new MyClass();
delete obj;  // Destructor called explicitly with delete
```

Destructors cannot be overloaded. A class can have only one destructor, which has no parameters and no return type.


### Resource Management:
Destructors are often used in conjunction with RAII (Resource Acquisition Is Initialization) to manage resources like memory or file handles.
For example, if a class dynamically allocates memory in its constructor, the destructor should release that memory:
```cpp
class MyClass {
    int* data;
public:
    MyClass() { data = new int[10]; }  // Allocate memory
    ~MyClass() { delete[] data; }      // Release memory
};
```
In summary, destructors play a vital role in managing the lifecycle of objects in C++ and ensuring proper cleanup of resources. Always consider using a virtual destructor in polymorphic base classes and ensure that dynamically allocated resources are properly released.

## Arrow Operator for Pointers
The arrow operator (->) in C++ is used to access members (methods or variables) of an object through a pointer. It is essentially a shorthand for dereferencing the pointer and then accessing the member.

### Syntax:
```cpp
pointer->member
```
This is equivalent to:

```cpp
(*pointer).member
```

### Here’s how it works:
* Dereferencing (*pointer):
When you have a pointer to an object, *pointer dereferences the pointer to give you access to the actual object.
* Member access (.):
Once you have the actual object, you can use the dot operator (.) to access its members (variables or functions).
The arrow operator (->) combines these two steps into one.

### Example:
Let's say you have the following class:

```cpp
class MyClass {
public:
    int value;
    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};
```

Now, if you create a pointer to an object of this class:

```cpp
MyClass obj;
MyClass* ptr = &obj;
```

You can use the arrow operator to access the members of the object through the pointer:

```cpp
ptr->value = 42;       // Equivalent to (*ptr).value = 42;
ptr->display();        // Equivalent to (*ptr).display();
```

Without the arrow operator, you'd have to dereference the pointer first and then access the member like this:

```cpp
(*ptr).value = 42;    // Dereferencing the pointer first, then accessing the member
(*ptr).display();     // Same thing for a member function
```

### Why Use the Arrow Operator?
The arrow operator simplifies the syntax, making the code cleaner and easier to read when working with pointers. Instead of having to type (*ptr).member every time, you can simply use ptr->member.

### Key Points:
* -> is only used when dealing with pointers to objects.
* If you're not using a pointer but a regular object, you should use the dot operator (.) instead.
* The arrow operator is equivalent to dereferencing the pointer and then using the dot operator (.).


### Example with dynamic memory:
If you dynamically allocate an object using new, you access its members through the arrow operator:

```cpp
MyClass* dynamicObj = new MyClass();
dynamicObj->value = 10;  // Use the arrow operator for pointer
dynamicObj->display();
delete dynamicObj;       // Don't forget to free dynamically allocated memory
```


### In a Class with Operator Overloading:
The arrow operator can also be overloaded in user-defined classes. This is rare but can be useful in some advanced cases (e.g., smart pointers).

Here's an example of how you might overload the arrow operator for a class:

```cpp
class Wrapper {
    MyClass obj;
public:
    MyClass* operator->() {
        return &obj;  // Return a pointer to the contained object
    }
};

int main() {
    Wrapper w;
    w->value = 5;    // Uses the overloaded arrow operator
    w->display();    // Access members of MyClass through the wrapper
}
```


In this case, Wrapper overloads the -> operator to return a pointer to an internal object of type MyClass. This allows the user to directly access MyClass members as if they were using a pointer to MyClass.

### Summary:
The arrow operator (->) simplifies accessing members of an object through a pointer.
It is equivalent to dereferencing the pointer and then accessing the member.
It is often used when working with dynamically allocated objects or class instances managed through pointers.