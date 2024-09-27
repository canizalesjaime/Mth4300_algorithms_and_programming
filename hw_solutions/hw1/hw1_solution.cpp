#include<iostream>

using namespace std;

double question1(double a, double b);
bool question2(double x);
void question3(int x);

int main()
{
    // Question 1
    cout<< "Enter values a and b: "<<endl;
    double a,b;
    cin>>a>>b;
    double m = question1(a,b);
    cout<<m<<endl;

    // Question 2
    cout<< "Enter real number x: "<<endl;
    double x;
    cin>>x;
    bool check=question2(x);
    if(check)
        cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    // Question 3
    cout<< "Enter integer x: "<<endl;
    int x1;
    cin>>x1;
    question3(x1);

    return 0;
}

double question1(double a, double b)
{
    if(a > b)
        return a;
    
    else return b;
}


bool question2(double x)
{
    return (x > 5 && x < 15) || (x>95 && x<202);
}


void question3(int x)
{
    if(x > 100)
    {
        cout<<"Congratulations! You know about big numbers!"<<endl;
    }

    else
    {
        cout<<"Good enough. Try with a bigger number next time."<<endl;
    }
}