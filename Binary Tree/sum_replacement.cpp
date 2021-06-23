//sum replacement- replace the value of each node with the sum of all subtree nodes and itself

#include<iostream>
using namespace std;

struct node{
    int data; 
    node  *left, *right;
    node(int val) { data=val; left=NULL; right=NULL; }
};

void replaceSum(node *root){ // O(n);

    if(root==NULL) return;

    replaceSum(root->left);
    replaceSum(root->right);

    if(root->left)
        root->data+=root->left->data;
    if(root->right)
        root->data+=root->right->data;
}   

void preorder(node *root){

    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);

    /*
        1 
       /  \
      2    3
     / \  / \
    4   5 6  7
    */

   replaceSum(root);
   preorder(root);

}
