#include<iostream>
#include<string>
#include <cmath>

using namespace std;

string string_operator_plus();
void test_conditional();

int main()
{

    return 0;
}


string string_operator_plus()
{
    string one ="app";
    string two = "le";
    string three = one+two+"s";
    cout<<three; 
    return three;
}


void test_conditional()
{
    int num;
    cout<<"enter a num: ";
    cin>>num;
    cout<<endl;

    if(num % 2 ==0 && num %3==0)
    {
        cout<<"number is divisible by 2 and 3";
    }

    else if (num % 2)
    {
        cout<<"number is divisible by 2 only";
    }

    else if (num % 3)
    {
        cout<<"number is divisible by 3 only";
    }

    else
    {
        cout<<"number is not divisble by 2 or 3";
    }
    
}