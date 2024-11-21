#include<iostream>
#include"binary_search_tree.h"


int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.inOrder(bst.getRoot());
    std::cout<<bst.deleteNode(bst.getRoot(),70);
    bst.inOrder(bst.getRoot());
    // bst.~BinarySearchTree();
    //bst.inOrder(bst.getRoot());

    // int key = 40;
    // if (search(root, key)) 
    //     std::cout << "Value " << key << " found in the tree." << std::endl;
    
    // else std::cout << "Value " << key << " not found in the tree." << std::endl;

    return 0;
}