# Lecture notes

## table of contents
1. Solution to in class assignments
2. Hash table
3. Maps
4. Class Assignments


## Solution to in class assignments
Implement your own class for a queue(do not use the standard template library(stl)) [solution](./class_assignment_solutions/queue.cpp)


## Hash table 
A hash table is a data structure that maps keys to values for efficient lookup. It uses a hashing function to convert keys into indices (or hash codes) within an array, where the values are stored.
Hash tables are widely used for their average-case time complexity of $O(1)$ for lookup, insertion, and deletion.

### Key Concepts of Hash Tables
* Hash Function:
  * A function that takes a key and computes an integer value (hash code), which is used as the index in the hash table.
  * A good hash function minimizes collisions (different keys mapping to the same index).
    Example: For a hash table of size 10:
    ```cpp
    hashCode = key % 10;
    ```

* Buckets:
  * Each index in the hash table array is called a bucket.
  * A bucket may store one or more key-value pairs if collisions occur.

* Collisions:
  * Occurs when multiple keys produce the same hash code.
  * Collision resolution techniques are required to handle these.

* Load Factor:
  * Ratio of the number of elements in the hash table to its size.
  * When the load factor exceeds a threshold, the table is resized (rehashed).

### Operations in a Hash Table
1. **Insertion**
   * Apply the hash function to compute the index for the key.
   * Store the key-value pair at the computed index.
2. **Search**
   * Use the hash function to compute the index.
   * Check the bucket for the key.
3. **Deletion**
   * Compute the index using the hash function.
   * Locate and remove the key-value pair from the bucket.


### Collision Resolution Techniques
#### Chaining
* Each bucket stores a list (or chain) of key-value pairs.
* When a collision occurs, the new pair is appended to the list at that index.

Example:
```css
Bucket 0 -> [key1: value1] -> [key2: value2]
```

#### Open Addressing
* Instead of chaining, the hash table searches for the next available bucket.
* Common methods:
  * Linear Probing: Check the next index sequentially.
  * Quadratic Probing: Check indices using a quadratic formula.
  * Double Hashing: Use a secondary hash function to find an alternate bucket.

### Applications of Hash Tables
* **Databases:** Indexing for fast query results.
* **Caching:** Efficient storage and retrieval of frequently accessed data.
* **Symbol Tables:** Compilers and interpreters use hash tables to store identifiers and their attributes.
* **Sets:** Implementing data structures like sets.

### Advantages of Hash Tables
* **Fast Access:** Average-case time complexity for lookup, insertion, and deletion is $O(1)$.
* **Simple Implementation:** Easier to implement than other associative data structures like trees.

### Disadvantages of Hash Tables
* **Worst-Case Performance:** If many collisions occur, performance can degrade to $O(n)$.
* **Memory Overhead:** Requires extra memory for hash codes and potential chaining.
* **Hash Function Dependency:** Poor hash functions can lead to more collisions.

[EXAMPLE IMPLEMENTATION](./hash_table/hash_table.cpp)


## Maps
In C++, std::unordered_map is a container from the Standard Template Library (STL) that stores key-value pairs in an unordered manner. Unlike std::map, which maintains elements in a sorted order, std::unordered_map uses a hash table to achieve faster lookups.

### Key Features
* **Unordered Storage:** Elements are not stored in any specific order.
* **Fast Operations:** Lookup, insertion, and deletion have average-case time complexity of $O(1)$. However, in the worst case (hash collisions), the complexity can degrade to $O(n)$.
* **Unique Keys:** Each key must be unique. If you attempt to insert a duplicate key, it will overwrite the existing value.

### Syntax and Declaration
```cpp
#include <unordered_map>
std::unordered_map<KeyType, ValueType> mapName;
```
* **KeyType:** The type of the key.
* **ValueType:** The type of the value.

Example:
```cpp
std::unordered_map<std::string, int> myUnorderedMap;
```

### Inserting Elements
```cpp
std::unordered_map<std::string, int> myUnorderedMap;

// Using insert() with pair
myUnorderedMap.insert(std::make_pair("Apple", 10));

// Using the subscript operator
myUnorderedMap["Banana"] = 20;
myUnorderedMap["Cherry"] = 30;
```

### Accessing Elements
```cpp
std::cout << myUnorderedMap["Banana"];  // Output: 20
```
Note: Accessing a non-existent key with ```[]``` will insert it with a default value for the value type.

### Checking Existence
```cpp
if (myUnorderedMap.find("Apple") != myUnorderedMap.end()) {
    std::cout << "Apple exists!\n";
} else {
    std::cout << "Apple does not exist.\n";
}
```

### Iterating Through the Map
```cpp
for (const auto &pair : myUnorderedMap) {
    std::cout << pair.first << ": " << pair.second << "\n";
}
```

### Erasing Elements
```cpp
myUnorderedMap.erase("Banana");  // Removes the key "Banana"
```

### Size and Empty Check
```cpp
std::cout << "Size: " << myUnorderedMap.size() << "\n";
std::cout << "Is Empty: " << (myUnorderedMap.empty() ? "Yes" : "No") << "\n";
```

Example Code
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myUnorderedMap;

    // Insert elements
    myUnorderedMap["Apple"] = 10;
    myUnorderedMap["Banana"] = 20;
    myUnorderedMap["Cherry"] = 30;

    // Access elements
    std::cout << "Value for Banana: " << myUnorderedMap["Banana"] << "\n";

    // Iterate over elements
    for (const auto &pair : myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // Check existence
    if (myUnorderedMap.find("Apple") != myUnorderedMap.end()) {
        std::cout << "Apple is in the map.\n";
    } else {
        std::cout << "Apple is not in the map.\n";
    }

    // Erase an element
    myUnorderedMap.erase("Banana");
    std::cout << "Size after erase: " << myUnorderedMap.size() << "\n";

    return 0;
}
```

### Key Differences Between ```std::map``` and ```std::unordered_map```
| Feature              | std::map           | std::unordered_map   |
|----------------------|--------------------|----------------------|
| Ordering             | Sorted by key      | Unordered            |
| Implementation       | Balanced BST       | Hash Table           |
| Lookup Complexity    | $O(logn)$          | $O(1)$(average case) |
| Insertion Complexity | $O(logn)$          | $O(1)$(average case) |
| Key Requirements     | Requires operator< | Requires std::hash   |

### When to Use std::unordered_map
* **Fast Lookup:** Use when you need fast access and don't care about the order of elements.
* **Memory Usage:** It may use more memory than ```std::map``` because of the hash table.
* **Custom Hash Functions:** You can define a custom hash function for complex key types.


## Class assignments
1. Use a map to solve the following problem: Given an integer array ```nums```, return true if any value appears more than once in the array, otherwise return false.
