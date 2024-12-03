#include<iostream>
#include"binary_search_tree.h"


int main()
{
    BinarySearchTree bst;
    bst.insert(bst.getRoot(),50);
    bst.insert(bst.getRoot(),30);
    bst.insert(bst.getRoot(),70);
    bst.insert(bst.getRoot(),20);
    bst.insert(bst.getRoot(),40);
    bst.insert(bst.getRoot(),60);
    bst.insert(bst.getRoot(),80);

    std::cout<<bst.getHeight(bst.getRoot());
    return 0;
}