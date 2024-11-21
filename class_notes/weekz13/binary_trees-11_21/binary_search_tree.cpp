#include<iostream>
#include"binary_search_tree.h"


BinarySearchTree::BinarySearchTree():root(nullptr){}


BinarySearchTree::~BinarySearchTree(){destroy(root);}


void BinarySearchTree::destroy(Node* curr_del)
{
    if(!curr_del) return;

    destroy(curr_del->left);
    destroy(curr_del->right);

    delete curr_del;
    curr_del=nullptr;
}


Node* BinarySearchTree::getRoot()
{
    return root;
}


void BinarySearchTree::insert(int value)
{
    if (!root) 
    {
        root= new Node(value);
        return;
    }
    
    Node* curr= root;
    
    while(curr)
    {
        if(value < curr->data)
        {
            if(!curr->left)
            {
                curr->left=new Node(value);
                return;
            }
            else curr=curr->left;
        }

        else if (value > curr->data)
        {
            if(!curr->right)
            {
                curr->right=new Node(value);
                return;
            }
            else curr=curr->right;
        }

        else return; //dont insert duplicates
    }
}


void BinarySearchTree::inOrder(Node* start)
{
    if (!start) return;

    inOrder(start->left);
    std::cout<<start->data<<" -> ";
    inOrder(start->right);
}


Node* BinarySearchTree::search(int val)
{
    Node* curr=root;
    while (curr)
    {
        if(val < curr->data) curr=curr->left;

        else if (val > curr->data) curr=curr->right;

        else return curr; // val==curr->data, so we found node
    }

    return nullptr;
}


Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;

    else if(val < start->data) start->left=deleteNode(start->left,val);

    else if(val > start->data) start->right=deleteNode(start->right,val); 
    
    else
    {
        //two children
        if(start->left && start->right)
        {
            Node* temp_ptr = findMin( start->right );
            start->data = temp_ptr->data;
            deleteNode( start->right, start->data );
        }


       else //at most one children
       {
            Node* old_node =start;
            if (start->left) start=start->left;

            else start=start->right;

            delete old_node;
       } 

    }

    return start;//no node to delete
}


Node* BinarySearchTree::findMin(Node* start)
{
    if(!start) return nullptr;
    
    while(start->left) start=start->left;

    return start;
}
