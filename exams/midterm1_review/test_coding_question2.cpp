#include<iostream>

using namespace std; 

int odd_sum(int arr[], int pos);

int main()
{
    cout<<"Enter # of elements: "<<endl;
    int elems;
    cin>>elems;
    int* ptr = new int[elems];

    for(int i =0;i<elems;i++) ptr[i]=i+1;
    for(int i =0;i<elems;i++) cout<<ptr[i]<<" ";
    cout<<endl;
    
    int sum=odd_sum(ptr, elems-1);
    cout<<sum<<endl;

    delete[] ptr;
    ptr=nullptr;
    return 0;
}

int odd_sum(int arr[], int pos)
{
    // base cases
    if(pos == 0) return 0;
    else if(pos == 1) return arr[pos];
    // rescursive cases
    else if (pos%2==1) return arr[pos]+odd_sum(arr,pos-2);
    else return odd_sum(arr,pos-1); 
}