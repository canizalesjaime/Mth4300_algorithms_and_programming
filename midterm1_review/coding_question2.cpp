#include<iostream>

using namespace std;

int main()
{
    int arr[5][5];
    int row, val;
    cout<<"Enter row number and value:"<<endl;
    cin>>row>>val;

    for(int i =0; i<5;i++)
        for(int j =0; j<5;j++)
        {
            if (i != row)
                arr[i][j]=0;
            
            else arr[i][j]=val+j;
        }
        

    for(int i =0; i<5;i++)
    {
        for(int j =0; j<5;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    } 


    return 0;
}