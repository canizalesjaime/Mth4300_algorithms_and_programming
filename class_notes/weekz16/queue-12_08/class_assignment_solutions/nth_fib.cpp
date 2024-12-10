#include<iostream>
#include<stack>

int nth_fib(int n)
{
    std::stack<int> s;
    s.push(0);
    s.push(1);

    for(int i; i<n-2;i++)
    {
        int f_1 = s.top();
        s.pop();
        int f_2 = s.top();
        s.pop();

        s.push(f_1);
        s.push(f_1+f_2);
    }
    return s.top();
}

int main()
{
    std::cout<<nth_fib(5)<<" "<<nth_fib(8)<<std::endl;
    return 0;
}