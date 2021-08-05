#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};


void flatten_util(node *&head, node *&prev, node *root){

    if(root==NULL) return;

    flatten_util(head, prev, root->left);

    if(head==NULL){

        head=prev=root;

    }

    else{

        prev->right = root;
        root->left = NULL;
        prev=prev->right;
    }

    flatten_util(head, prev, root->right);

}

node *flatten(node *root){

    if(root==NULL) return NULL; 

    node *head=NULL, *prev=NULL;

    flatten_util(head, prev, root);

    return head;
}

void inorder(node *root){

    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
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

    inorder(root);

    root = flatten(root);

    cout<<endl;
    inorder(root);
   
}