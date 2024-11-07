# Lecture notes

## table of contents
1. Solution to in class assignments
2. File Streams
3. STL List and Iterators
4. Class Assignments


## Solutions to in class assignments
1. Modify insertion and deletion to delete by position instead of value. [solution](./class_assignment_solutions/linked_list.cpp) 
2. Write a function that takes in a class ```LinkedList(singly linked list)```, and returns another linked list in the reverse order. Example: l1= 5->3->7->1 then the output should be l1_r= 1->7->3->5 [solution](./class_assignment_solutions/linked_list.cpp)
3. Separate the interface from implementation for the ```LinkedList``` class given. [solution](./class_assignment_solutions/linked_list.h)
4. Check out the stl for lists [List Documentation](https://cplusplus.com/reference/list/list/)


## File Streams
In C++, inputting and outputting files is handled using file streams from the ```<fstream>``` library. This library provides three key classes for file operations:

* ifstream: For reading from files (input file stream).
* ofstream: For writing to files (output file stream).
* fstream: For both reading and writing (input-output file stream).

### Including the ```<fstream>``` Library
Before working with files, you need to include the header:
```cpp
#include <fstream>
```

### Opening and Closing Files
To perform file operations, you need to open a file. Streams can be opened either in the constructor or using the .open() method.

* Opening a file: When you open a file for reading or writing, the file stream is associated with a file on your disk.
* Closing a file: It's good practice to close the file after operations to free up system resources.


#### Reading from Files (ifstream)
To read from a file, use the ifstream class.
##### Example:
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("example.txt"); // Open file for reading
    if (!inputFile.is_open()) {             // Check if the file was successfully opened
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) { // Read file line by line
        std::cout << line << std::endl;     // Output each line to the console
    }

    inputFile.close();                      // Close the file
    return 0;
}
```

##### Explanation:
* std::ifstream inputFile("example.txt");: Opens the file example.txt for reading.
* std::getline(inputFile, line);: Reads one line from the file at a time into the line variable.
* inputFile.close();: Closes the file after reading.

#### Writing to Files (ofstream)
To write to a file, use the ofstream class. If the file doesn't exist, it will be created. If it exists, by default, it will be overwritten unless a specific mode is used.

##### Example:
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("output.txt"); // Open file for writing
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    outputFile << "This is a line of text.\n"; // Write a line of text
    outputFile << "Another line of text.\n";   // Write another line

    outputFile.close(); // Close the file
    return 0;
}
```
##### Explanation:
* std::ofstream outputFile("output.txt");: Opens output.txt for writing. If the file doesn't exist, it is created.
* outputFile << "text";: Writes text to the file.
* outputFile.close();: Closes the file after writing.


#### Reading and Writing Files (fstream)
To both read from and write to a file, use the fstream class. You need to specify the mode explicitly using flags such as std::ios::in (for reading) and std::ios::out (for writing).

##### Example:
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app); // Open for reading and writing, append mode
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Write to file
    file << "Adding some new data.\n";

    // Move the file pointer to the beginning for reading
    file.seekg(0, std::ios::beg);

    // Read from file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close(); // Close the file
    return 0;
}
```
##### Explanation:
* std::fstream file("data.txt", std::ios::in | std::ios::out);: Opens data.txt for both reading and writing.
* file << "text";: Writes to the file.
* file.seekg(0, std::ios::beg);: Moves the file pointer back to the start to read from the file.
* std::getline(file, line);: Reads lines from the file.


### File Open Modes
When opening files, you can use different modes to control how the file is accessed:
* std::ios::in: Open for reading.
* std::ios::out: Open for writing (default behavior is to overwrite the file).
* std::ios::app: Append to the file without erasing its content.
* std::ios::binary: Open the file in binary mode (useful for non-text data).


### Example of specifying modes:
```cpp
std::ofstream file("data.txt", std::ios::out | std::ios::app);  // Open for writing and append mode
```

### Checking for File Errors
You can check if a file was successfully opened using the .is_open() method. Additionally, file streams support several flags to detect errors:

* fail(): Checks if a failure occurred (e.g., trying to read past the end of the file).
* eof(): Checks if the end of file has been reached.
* bad(): Checks for non-recoverable errors like hardware failure.
* good(): Returns true if no errors occurred.


#### Example:
```cpp
std::ifstream inputFile("data.txt");
if (!inputFile) {
    std::cerr << "Failed to open the file!" << std::endl;
}
```

### Example Summary: Copying File Contents
Here's a full example of how to read from one file and write its content into another:

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");  // Open input file for reading
    std::ofstream outputFile("output.txt"); // Open output file for writing

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) { // Read each line from input
        outputFile << line << std::endl;    // Write each line to output
    }

    inputFile.close();  // Close input file
    outputFile.close(); // Close output file
    return 0;
}
```

### Conclusion
Use ifstream for reading, ofstream for writing, and fstream for both reading and writing.
Always check if the file was opened successfully.
Remember to close the file after operations to release resources.
Use appropriate file open modes depending on whether you want to overwrite, append, or open in binary mode.


## STL List and Iterators
In C++, the Standard Template Library (STL) ```std::list``` is a doubly linked list. It allows fast insertion and deletion at any position (constant time for these operations), but it does not support random access like ```std::vector```. Instead, elements must be accessed sequentially.

### Key Features:
* Dynamic size (automatically resizes).
* Bi-directional traversal using iterators.
* Efficient insertion/removal from both ends and in the middle (compared to vectors).


### Iterators:
```std::list``` provides bi-directional iterators, which can move forward (++) and backward (--).
Iterators are similar to pointers and can be used to traverse, insert, or delete elements.

### Basic usage:
```cpp
std::list<int> lst = {1, 2, 3, 4};
std::list<int>::iterator it = lst.begin();  // Points to the first element
++it;  // Move to the next element
lst.insert(it, 10);  // Insert 10 before the current position
```
Iterators become invalid after modifying the list structure at their position.


## Class Assignments
1. Use stl list and solve the problem from last time for reversing a linked list
2. What is the time complexity (big O notation) for reversed linked list?
3. Read the [link list](./link_list.txt) from the file and store it in a stl list. Insert three nodes with the values 1,2 and 3 into the stl list. Sort the list by referencing [stl list documentation](https://cplusplus.com/reference/list/list/), then write the sorted list with the inserted values into a new file and name it ```modified_link_list.txt```. Reference the documentation and note the runtime and spacetime complexity for insert and sort.  