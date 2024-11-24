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

    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;
    
    bst.deleteNode(bst.getRoot(),70);
    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;

    bst.insert(bst.getRoot(),30);
    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;
    

    bst.~BinarySearchTree();
    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;
    int key=40;
    if (bst.search(key)) 
        std::cout << "Value " << key << " found in the tree." << std::endl;
    
    else std::cout << "Value " << key << " not found in the tree." << std::endl;

    return 0;
}