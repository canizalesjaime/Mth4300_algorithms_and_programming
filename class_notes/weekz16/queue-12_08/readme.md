# Lecture notes

## table of contents
1. Solution to in class assignments
2. Queues
3. Breadth First Search on Binary Search Trees
4. Class Assignments


## Solution to in class assignments
1. Write a program to implement a stack in C++ that checks if a given string of parentheses is balanced. A string is considered balanced if:
   * Every opening parenthesis ```(,{,[``` has a corresponding and correctly placed closing parenthesis ```), }, ]```.
   * Closing parentheses match the most recently opened parentheses.

   You need to:
   * Implement the stack manually using arrays or STL stack.
   * Write a function bool isBalanced(string str) to check if a string is balanced.
   * Test the function with sample inputs. [solution](./class_assignment_solutions/balanced_parenthesis.cpp)
2. Solve the for the nth fibonacci number using a stack instead of recursion.[solution](./class_assignment_solutions/nth_fib.cpp)


## Queues
In C++, queues are a type of container adapter provided by the Standard Template Library (STL). They are based on the First In, First Out (FIFO) principle, meaning elements are inserted at the back and removed from the front.

### Key Characteristics of a Queue
* **FIFO Principle:** The first element added to the queue is the first one to be removed.
* **Restricted Access:**
  * Elements can only be added at the back.
  * Elements can only be removed from the front.
* **Underlying Container:**
  * The ```queue``` container adapter is implemented using either a deque or a list as the underlying container.

### Queue Operations
The ```std::queue``` class is defined in the ```<queue>``` header. Below are the primary operations provided:

### Common Methods
| Operation | Description                                  | Example                 |
|-----------|----------------------------------------------|-------------------------|
| push()    | Adds an element to the back of the queue.    | q.push(10);             |
| pop()     | Removes the front element of the queue.      | q.pop();                |
| front()   | Returns a reference to the front element.    | std::cout << q.front(); |
| back()    | Returns a reference to the last element.     | std::cout << q.back();  |
| empty()   | Checks if the queue is empty.                | if(q.empty()) { ... }   |
| size()    | Returns the number of elements in the queue. | std::cout << q.size();  |


### Example: Using std::queue
```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Access front and back elements
    std::cout << "Front: " << q.front() << std::endl; // 10
    std::cout << "Back: " << q.back() << std::endl;   // 30

    // Remove elements
    q.pop();
    std::cout << "Front after pop: " << q.front() << std::endl; // 20

    // Size of the queue
    std::cout << "Size: " << q.size() << std::endl; // 2

    // Check if queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }

    return 0;
}
```

### Real-World Use Cases
* **Task Scheduling:** Managing tasks where the first task added is processed first.
* **Print Queue:** Sending print jobs to a printer in the order they were received.
* **Breadth-First Search (BFS) in Graphs:** To explore nodes level by level.

### Specialized Queues
* **Priority Queue:** A variant where elements are removed based on priority instead of FIFO. Implemented using std::priority_queue.
* **Double-ended Queue (Deque):** Elements can be added/removed from both ends. Use std::deque.

By understanding these operations and their applications, you can effectively manage ordered data in C++.


## Breadth First Search on Binary Search Trees
Breadth-First Search (BFS) for a binary tree is a traversal method where nodes are visited level by level, starting from the root and proceeding to the next level. This approach is also known as level-order traversal. Here's an explanation of how BFS works for a binary tree:

### Steps to Perform BFS
1. **Start at the Root:** Begin with the root node of the binary tree.
2. **Use a Queue:** Use a queue data structure to keep track of nodes to visit. A queue ensures that nodes are visited in the order they are added (FIFO: First In, First Out).
3. **Visit Nodes Level by Level:**
   * Dequeue the node at the front of the queue.
   * Process the node (e.g., print its value).
   * Enqueue the left child of the node (if it exists).
   * Enqueue the right child of the node (if it exists).
4. **Repeat:** Continue this process until the queue is empty.

### Example
#### Given Binary Tree:
```markdown
       1
      / \
     2   3
    / \   \
   4   5   6
```

#### BFS Traversal:
1. Start with the root: ```1```.
2. Enqueue ```1```. Queue: ```[1]```.
3. Dequeue ```1```, process it, and enqueue its children (```2``` and ```3```). Queue: ```[2, 3]```.
4. Dequeue ```2```, process it, and enqueue its children (```4``` and ```5```). Queue: ```[3, 4, 5]```.
5. Dequeue ```3```, process it, and enqueue its right child (```6```). Queue: ```[4, 5, 6]```.
6. Dequeue ```4```, process it (no children to enqueue). Queue: ```[5, 6]```.
7. Dequeue ```5```, process it (no children to enqueue). Queue: ```[6]```.
8. Dequeue ```6```, process it (no children to enqueue). Queue: ```[]```.
**Result:** The BFS traversal is: ```1, 2, 3, 4, 5, 6```.

#### c++ code:
```c++
void BFS(BinarySearchTree& t)
{
    std::queue<Node*> q;

    if(t.getRoot())
    {
        std::cout<<t.getRoot()->data<<std::endl;
        q.push(t.getRoot());
    }
    
    int nodes_per_level = 1;
    while(!q.empty())
    {
        for(int i=0;i<nodes_per_level;i++)
        {
            Node* n = q.front();
            q.pop();
            if(n->left)
            {
                std::cout <<" -> "<< n->left->data;
                q.push(n->left);
            }
            if(n->right)
            {
                std::cout <<" -> "<< n->right->data;
                q.push(n->right);
            }
        }
        std::cout<<std::endl;
        nodes_per_level=q.size();
    }
}
```

### Key Points
* BFS is suitable for exploring all nodes level by level.
* It uses a queue to maintain the order of exploration.
* BFS is different from Depth-First Search (DFS)(used in pre-order,post-order, and in-order), which explores as far as possible along each branch before backtracking.


## Class assignments
1. Implement your own class for a queue(do not use the standard template library(stl))
