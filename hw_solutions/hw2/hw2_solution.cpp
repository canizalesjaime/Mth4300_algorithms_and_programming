// Your Name
// Make sure to test all functions
// Only one main function !!
#include<iostream>  

using namespace std;

void dynamic_array(int rows, int cols);
int recursive_sum(int arr[], int size_of_arr);
bool check_rotation(int arr1[],int arr2[],int size_of_arr1,int size_of_arr2);

int main()
{
    // Question 1
    int rows, cols;
    cout<<"Enter # of rows and columns"<<endl;
    cin>>rows>>cols;
    dynamic_array(rows,cols);


    // Question 2
    // only an example, I should be able to change arrays and function still works
    int arr1[5]={1,2,3,4,5}; 
    int sum1=recursive_sum(arr1, sizeof(arr1)/sizeof(arr1[0]));
    cout<<"sum: "<<sum1<<endl;

    
    // Question 3
    int arr2[7]={10,20,30,10,40,50,60};
    int arr3[7]={30,10,40,50,60,10,20};
    cout<<check_rotation(arr2,arr3,sizeof(arr2)/sizeof(arr2[0]),sizeof(arr3)/sizeof(arr3[0]))<<endl;

    return 0;
}


void dynamic_array(int rows, int cols)
{
    if(rows <= 0 || cols <= 0)
    {
        cout<<"Incorrect input"<<endl;
        return;
    }

    int** d_arr = new int*[rows];
    for(int row = 0; row < rows; row++)
        d_arr[row]= new int[cols];

    for(int row = 0; row < rows; row++)
        for(int col = 0; col < cols; col++)
            d_arr[row][col]=row*cols+col;
    
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
            cout<<d_arr[row][col]<<" ";
        cout<<endl;
    }

    for(int row = 0; row < rows; row++)
    {
        delete[] d_arr[row];
        d_arr[row]=nullptr;
    }
    delete[] d_arr;
    d_arr=nullptr;
}


int recursive_sum(int arr[], int size_of_arr1)
{
    if(size_of_arr1 == 0)
        return 0;

    return arr[size_of_arr1-1]+recursive_sum(arr,size_of_arr1-1);
}


bool check_rotation(int arr1[],int arr2[],int size_of_arr1,int size_of_arr2)
{
    if (size_of_arr1 != size_of_arr2)
        return false;
    
    int size = size_of_arr1;
    for(int i=0; i < size; i++)
    {
        if(arr1[0] == arr2[i])
        {
            int count=0;
            for(int j=0; j<size;j++)
            {
                if(arr1[j]==arr2[(i+j)%size])
                    count++;

                else break;
            }

            if(count == size)
                return true;
        }
    }
    
    return false;

}