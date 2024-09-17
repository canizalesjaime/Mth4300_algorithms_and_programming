# Lecture Notes

## table of contents
1. .gitignore adn developing in this repo without git conflicts
1. While Loops
2. Arrays
3. In class assignments


## .gitignore adn developing in this repo without git conflicts
When using git, sometimes you may want to code your own stuff in this repo, but you will notice that if you add your own code, then try to ```git pull``` changes you get a git conflict error. In order to solve this problem we use the **.gitignore** file. The **.gitignore** file is a special file in git, that allows us to ignore files and directories(aka repos and folders) from causing changes to the git repo. Check out the .gitignore file [here](../../../.gitignore), in the .gitignore file, you can see that we added a line ***hidden/**, this line allows us to create a folder named **hidden** anywhere, and it will not conflict with anything in the git repo.


## While Loops
In C++, loops are used to execute a block of code repeatedly. The two common types of loops are `for` loops and `while` loops. Here's a brief overview of While loops:


### `while` Loop
A while loop is used when you do not know in advance how many times you need to execute a statement or a block of statements. The loop continues as long as a specified condition is true.

**Syntax:**

``` cpp
while (condition) {
    // Code to be executed
}
```

#### Example:

``` cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i < 5) {
        cout << i << " ";
        i++;
    }
    return 0;
}
```
In this example, the loop continues as long as i is less than 5. It prints numbers from 0 to 4, just like the for loop example.

#### Key Differences
**Initialization and Update:** In a for loop, initialization and update happen in the loop statement, while in a while loop, they must be handled inside the loop body.
**Condition Checking:** Both loops check their conditions before executing the loop body, but for loops are generally used when the number of iterations is known ahead of time.

## Arrays
In C++, an array is a data structure that can hold a fixed-size sequence of elements of the same type. Arrays are useful for storing multiple values in a single variable and can be accessed using an index.

### Declaration and Initialization

**Declaration**:
To declare an array, you specify the type of its elements and the number of elements it will hold.

**Syntax:**

```cpp
type arrayName[arraySize];
```

#### Example:

```cpp
int numbers[5];
This declares an array named numbers that can hold 5 integers.
```

**Initialization:** You can initialize an array at the time of declaration by providing a list of values enclosed in curly braces.

**Syntax:**

```cpp
type arrayName[arraySize] = {value1, value2, value3, ..., valueN};
```

#### Example:

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
```

### Accessing Elements
You access elements in an array using an index, with the first element at index 0.

**Syntax:**

```cpp
arrayName[index]
```

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    cout << numbers[0]; // Outputs 1
    cout << numbers[4]; // Outputs 5
    return 0;
}
```


## In class assignments
1. Create a program that reads 10 real numbers from the standard input and calculates theie sum. After the user enters the 10 numbers the program should print all the numbers entered by the user, and also print the sum of the numbers. 
2. Create a program that reads real numbers of type double from the user input until it reads a negative number or zero. The negative number (or zero) means that the input is over. You are allowed to assume that the input from the user will contain at least one positive element. The program should calculate the maximum of the numbers provided by the user.