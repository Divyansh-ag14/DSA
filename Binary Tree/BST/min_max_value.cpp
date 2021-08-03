#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void minMax(node *root){
    
    node *temp=root;

    int mn=root->data;
    int mx=root->data;

    while(temp!=NULL && temp->left!=NULL){
        temp=temp->left;
        mn = temp->data;
    }

    while(root!=NULL && root->right!=NULL){
        root=root->right;
        mx = root->data;
    }

    cout<<"min value: "<<mn<<endl<<"max value: "<<mx;
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

    minMax(root);
    
}