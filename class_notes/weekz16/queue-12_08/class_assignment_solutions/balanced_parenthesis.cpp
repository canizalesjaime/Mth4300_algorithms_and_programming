#include<iostream>
#include<string>
#include<stack>


bool isBalanced(std::string str)
{
    std::stack<char> s;
    for(auto& c:str)
    {
        if(c=='(') s.push('(');
        else if(c=='[') s.push('[');
        else if(c=='{') s.push('{');
        else if(!s.empty())
        {
            if(c==')' && s.top()=='(') s.pop();
            else if(c==']' && s.top()=='[') s.pop();
            else if(c=='}' && s.top()=='{') s.pop();
        }
        
        else return false;
    }
    return s.empty()?true:false;
    
}

int main()
{
    std::string s1 ="([{}])()";
    std::string s2 ="([{}]))";
    std::cout<<isBalanced(s1)<<" "<<isBalanced(s2)<<std::endl; 
    return 0;
}