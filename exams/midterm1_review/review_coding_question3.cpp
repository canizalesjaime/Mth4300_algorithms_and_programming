#include<iostream>

using namespace std;


int main()
{
    int x = 10;
    int* y = &x;
    x=17;
    *y=22;
    cout<<x<<endl;
    return 0;
}
