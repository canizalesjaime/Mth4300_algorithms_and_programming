#include<iostream>

using namespace std;

void func(int n);

int main()
{
    func(10);
    return 0;
}



void func(int n)
{
    if(n==0)
    {
        cout<<endl;
        return;
    }
         
    cout<<"#";
    func(n-1);
    cout<<"%";
}