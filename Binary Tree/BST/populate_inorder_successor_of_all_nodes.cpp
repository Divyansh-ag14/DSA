// Given a Binary Tree, write a function to populate next pointer for all nodes. 
// The next pointer for every node should be set to point to inorder successor.

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right, *next;
    node(int val) { data=val; left=right=next=NULL; }
};

void util(node *root, node *&prev){

    if(root==NULL) return;

    util(root->left, prev);

    if(prev==NULL)
        prev=root;

    else{

        prev->next = root;
        prev = prev->next;
    }

    util(root->right, prev);
}

void populateNext(node *root){

    node *prev=NULL;
    util(root, prev);

}

void inorder(node *root){

    if(root==NULL) return;

    inorder(root->left);

    cout<<root->data<<"->";
    root->next ? cout<<root->next->data : cout<<"-1";
    cout<<"  "; 

    inorder(root->right);
}

int main(void){

    node *root= new node(4);
    root->left= new node(2);
    root->right= new node(5);
    root->left->left= new node(1);
    root->left->right= new node(3);
    root->right->right= new node(6);

    /* 
        4            
       / \          
      2   5        
     / \   \      
    1   3   6    
    */


    populateNext(root);
    inorder(root);
}