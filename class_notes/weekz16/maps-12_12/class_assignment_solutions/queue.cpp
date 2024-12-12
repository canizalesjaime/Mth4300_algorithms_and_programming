#include<iostream>

using namespace std;

template <typename T>
class Queue
{
 private:
    T* data_;          // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the vector
    size_t capacity_;  // Capacity of the vector (how many elements it can hold)

public:
    // Constructor
    Queue() : size_(0), capacity_(1)
    {
        data_ = new T[capacity_];  // Allocate memory for 1 element
    }

    // Destructor
    ~Queue()
    {
        delete[] data_;  // Free dynamically allocated memory
    }

    // Method to add an element to the back of queue
    void push(const T& value)
    {
        if (size_ == capacity_) resize();  // Resize if capacity is reached

        data_[size_] = value;
        size_++;
    }

    // Method to remove an element from the front of queue
    T pop()
    {
        if (size_ == 0) throw std::out_of_range("Nothing to pop");
        T popped = data_[0];
        for(int i=1;i<size_;i++) data_[i-1]=data_[i];
        size_--;
        return popped;
    }

    // Method to access elements
    T& operator[](size_t index) 
    {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    //return first element
    T front()
    {
        if (size_ == 0) throw std::out_of_range("Empty queue");
        else return data_[0];
    }


    //return last element
    T back()
    {
        if (size_ == 0) throw std::out_of_range("Empty queue");
        else return data_[size_-1];
    }

    // check is queue is empty 
    bool isEmpty()
    {
        if(size_==0)return true;
        else return false;
    }

    // Method to get the size of the vector
    size_t getSize() const { return size_; }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() {
        capacity_ *= 2;  // Double the capacity
        T* newData = new T[capacity_];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size_; i++)
            newData[i] = data_[i];

        delete[] data_;  // Delete old array
        data_ = newData;  // Point to new array
    }

};

int main()
{
    Queue<int> q;

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
    std::cout << "Size: " << q.getSize() << std::endl; // 2

    // Check if queue is empty
    if (q.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }

    return 0;
}