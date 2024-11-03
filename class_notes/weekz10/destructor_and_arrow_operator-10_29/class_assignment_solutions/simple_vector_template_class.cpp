#include <iostream>

//using namespace std;

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


    // deletes last element in vector
    void pop_back() {
        if(size > 0) size--;
    }


    void pop_front() {
        if(size > 0)
        { 
            size--;
            for(size_t i = 0; i < size; i++)
                data[i]=data[i+1];
        }
        

    }


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


template <typename Elem>
void swap(Elem& first, Elem& second)
{
    Elem temp=first;
    first=second;
    second=temp;
}

int main()
{
    MyVector<double> vec;
    for(int i=0;i<10;i++) vec.push_back(2*i);
    
    vec.pop_back();
    vec.pop_back();
    vec.pop_front();
    vec.pop_front();
    
    std::cout<<std::endl;

    for(int i=0;i<vec.getSize();i++) std::cout<<vec[i]<<" ";

    return 0;
}