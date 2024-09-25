#include<iostream>

using namespace std;

int main()
{
    int num = 7;

    int* ptr = &num;

    cout<<"address of num: "<<ptr<<", content of num: "<<*ptr<<endl;

    num = 9;

    cout<<"address of num: "<<ptr<<", content of num: "<<*ptr<<endl;
    return 0;
}