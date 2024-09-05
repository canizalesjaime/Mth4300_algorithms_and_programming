#include<iostream>
#include<string>
#include <cmath>


using namespace std;

int foo(float x); //function decalaration for foo
string string_operator_plus();
void test_conditional();

int main()
{
    // one line comment
    
    /* this is a 
    multiline comment*/

    int y=foo(3.14);
    cout<<y<<endl;
    return 0;
}


int foo(float x) // function defintion for foo
{
    return floor(x);
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