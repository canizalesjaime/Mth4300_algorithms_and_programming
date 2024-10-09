In C++, operator overloading allows you to redefine or overload operators to work with user-defined data types (such as classes). This makes it possible to use operators like +, -, *, =, etc., with objects in a way that is intuitive and similar to their use with primitive data types.

Example: Overloading Operators in a C++ Class
Let's create a class called Complex to represent complex numbers and overload the + operator to add two complex numbers.

cpp
Copy code
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the + operator to add two Complex numbers
    Complex operator+(const Complex &other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the << operator to display a Complex number
    friend ostream &operator<<(ostream &out, const Complex &c);

    // Overload the >> operator to input a Complex number
    friend istream &operator>>(istream &in, Complex &c);
};

// Implementation of << operator overloading
ostream &operator<<(ostream &out, const Complex &c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

// Implementation of >> operator overloading
istream &operator>>(istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex c1, c2, c3;
    
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;
    
    c3 = c1 + c2;  // Using the overloaded + operator

    cout << "The sum of the two complex numbers is: " << c3 << endl;  // Using the overloaded << operator

    return 0;
}
Explanation
Constructor: The constructor initializes the real and imaginary parts of the complex number.

Overloading the + Operator:

The method Complex operator+(const Complex &other) allows you to add two Complex objects.
It creates and returns a new Complex object whose real and imaginary parts are the sums of the respective parts of the two objects.
Overloading the << Operator:

This allows you to use the << operator to output the object in a readable format.
It is defined as a friend function because it needs to access the private data members of the class.
Overloading the >> Operator:

This enables you to use the >> operator to input data into a Complex object.
It is also defined as a friend function.
Output Example
yaml
Copy code
Enter first complex number:
Enter real part: 3
Enter imaginary part: 4
Enter second complex number:
Enter real part: 1
Enter imaginary part: 2
The sum of the two complex numbers is: 4 + 6i
Important Points to Remember
Operator overloading does not change the precedence or associativity of operators.
Only existing operators can be overloaded; you cannot create new operators.
Certain operators like ::, .:, .*, sizeof, and ?: cannot be overloaded.
This approach makes the class more intuitive to use by enabling operations directly with the object instances.