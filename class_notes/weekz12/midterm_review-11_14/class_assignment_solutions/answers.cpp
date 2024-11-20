#include<iostream>
#include<list>
#include<fstream>

int main()
{
    // question 1 and 2
    // time complexity: O(n), space complexity: O(1)
    std::list<int> l = {1,2,3,4,5,6,7,8};
    l.reverse();

    for(auto it:l) std::cout<<it<<" -> ";
    std::cout<<std::endl;
    

    //question 3
    std::ifstream in_file("link_list.txt");
    if(!in_file.is_open())
    {
        std::cout<<"File did not open\n";
        return 0;
    }

    std::list<double> l2;
    double val;
    while(in_file>>val) l2.push_back(val);

    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);

    l2.sort();

    std::ofstream out_file("modified_link_list.txt");
    if(!out_file.is_open())
    {
        std::cout<<"File did not open\n";
        return 0;
    }

    for(auto it:l2) out_file<<it<<" ";
    return 0;
}