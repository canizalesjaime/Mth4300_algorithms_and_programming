# Lecture Notes

## table of contents
1. Classes 
2. Structs
3. In class assignments

## Classes
In C++, a class is a user-defined data type that serves as a blueprint for creating objects. It groups both data (attributes) and functions (methods) into a single unit. Classes are central to the concept of Object-Oriented Programming (OOP), which focuses on creating reusable, modular code that models real-world entities.

### Key Concepts of Classes:
* Attributes (Data Members): These are variables that store the state or characteristics of an object.
* Methods (Member Functions): These are functions that define the behavior of the object.
* Objects: Instances of a class created at runtime.
* Encapsulation: Restricting access to certain details of an object while exposing only the essential parts.
* Constructors/Destructors: Special methods for initializing and cleaning up objects.


### Basic Syntax of a Class
```cpp
#include <iostream>
using namespace std;

// Define a class
class Car {
public:
    string brand;
    string model;
    int year;

    // Constructor to initialize the object
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Member function to display car information
    void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
    // Create an object of the Car class
    Car car1("Toyota", "Camry", 2020);
    
    // Call the member function
    car1.displayInfo();  // Output: Brand: Toyota, Model: Camry, Year: 2020

    return 0;
}
```

### Key Features of Classes
1. **Access Specifiers**
Access specifiers define the visibility of the members (attributes and methods) of a class. The three main types of access specifiers in C++ are:

   * public: Members are accessible from outside the class.
   * private: Members are only accessible from within the class. This is the default access level in classes.
   * protected: Members are accessible within the class and its derived classes (used in inheritance).

#### Example of Access Specifiers:
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Public method to retrieve the balance
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(1000);  // Create an object with initial balance of 1000

    account.deposit(500);       // Deposit 500
    cout << "Current balance: " << account.getBalance() << endl;  // Output: Current balance: 1500

    return 0;
}
```

2. **Constructors and Destructors**
   * Constructor: A special function that is called automatically when an object is created. It is used to initialize the object. The constructor has the same name as the class and has no return type.

   * Destructor: A special function that is called when an object is destroyed (usually at the end of the program or when an object goes out of scope). It has the same name as the class, prefixed with a tilde (~), and also has no return type.

#### Example of Constructor and Destructor:
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;

    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
        cout << "Car created: " << brand << " " << model << " " << year << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car destroyed: " << brand << " " << model << " " << year << endl;
    }
};

int main() {
    Car car1("Honda", "Civic", 2021);  // Car created: Honda Civic 2021
    return 0;  // Destructor will be called when the object goes out of scope
}
```

3. **Encapsulation**
Encapsulation is a concept of restricting direct access to some of the object's components and only exposing what is necessary through public methods. This protects the integrity of the data.

In the following example, the private data (balance) can only be accessed and modified via public methods (deposit() and getBalance()):

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(500);
    account.deposit(250);  // Add money to the balance
    cout << "Current balance: " << account.getBalance() << endl;  // Output: Current balance: 750
    return 0;
}
```

### Summary of Key Concepts in C++ Classes:
* Attributes and Methods: Classes define data members (attributes) and member functions (methods).
* Encapsulation: Restrict access to internal data using access specifiers.
Constructors/Destructors: Automatically manage object creation and destruction.

Classes are central to the object-oriented paradigm in C++ and help in designing more modular, reusable, and maintainable code.

## Structs
Do all the same thing as classes, minus the encapsulation(private, public, protected). Use a struct when you are dealing with simple data structures that don’t need strict encapsulation or private members(but you can also use classes and just not include the private keyword).

## In class assignments
1. Something else
