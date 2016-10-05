#include "SortedTree.h"
#include <iostream>

SortedTree::SortedTree()
{
    root = NULL;
}
SortedTree::~SortedTree(){
    destroy(root);
}
void SortedTree::destroy(Node* root){
    if(root != NULL){
        destroy(root->r_next);
        destroy(root->l_next);
        delete root;
    }
}
void SortedTree::insert(int d)
{
    if(this->root != NULL){
        insert(d,this->root);
    }
    else{
        this->root = new Node;
        this->root->data = d;
        this->root->r_next = NULL;
        this->root->l_next = NULL;
    }
}

void SortedTree::insert(int d,Node* root){
    if(d < root->data)
    {
    if(root->l_next!=NULL)
        insert(d, root->l_next);
    else
    {
        root->l_next=new Node;
        root->l_next->data=d;
        root->l_next->l_next=NULL;    //Sets the left child of the child Node to null
        root->l_next->r_next=NULL;   //Sets the right child of the child Node to null
    }
    }
    else if(d > root->data)
    {
    if(root->r_next!=NULL)
        insert(d, root->r_next);
    else
    {
        root->r_next=new Node;
        root->r_next->data=d;
        root->r_next->l_next=NULL;  //Sets the left child of the child Node to null
        root->r_next->r_next=NULL; //Sets the right child of the child Node to null
    }
  }
}

void SortedTree::print(){
    print(this->root);
}

void SortedTree::print(Node* root){
    if(root != NULL){
        print(root->l_next);
        std::cout << root->data << " ";
        print(root->r_next);

    }
}
