// Your Name
// Make sure to test all functions
// Only one main function !!
#include<iostream>  

using namespace std;

int recursive_sum(int arr[], int size_of_arr);
bool check_rotation(int arr1[],int arr2[],int size_of_arr1,int size_of_arr2);

int main()
{
    // Question 1
    // Write all the code for question 1 here in main(it'll be easier I promise)
    // FILL IN CODE HERE
    

    // Question 2
    // only an example, I should be able to change arrays and function still works
    int arr1[5]={1,2,3,4,5}; 
    int sum1=recursive_sum(arr1, 5);
    cout<<"sum: "<<sum1<<endl;

    int arr2[5]={10,12,35,41,-51}; 
    int sum2=recursive_sum(arr2,5);
    cout<<"sum: "<<sum2<<endl;
    
    // Question 3
    int arr3[4]={10,20,30,40};
    int arr4[4]={30,40,10,20};
    cout<<check_rotation(arr3,arr4,4,4)<<endl;

    return 0;
}


int recursive_sum(int arr[], int size_of_arr1)
{
    //FILL IN CODE HERE
}


bool check_rotation(int arr1[],int arr2[],int size_of_arr1,int size_of_arr2)
{
    //FILL IN CODE HERE
}