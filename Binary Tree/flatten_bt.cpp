/*
 given a bt, flatten it into a linked list
 after flattening - left of each node must point to null and right must point to the next node in (preorder sequence)
 (use of another data structure is not allowed)
 
steps: 

1. flatten left and right subtrees recursively
2. store left and right tails (last element) of flattened subtrees
3. store the right subtree in temp and make the left subtree as right subtree
4. join right subtree (temp) with left tail
5. return right tail
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=NULL; right=NULL; }
};

void flatten(node *root){

    if(root==NULL || root->left==NULL && root->right==NULL) return;

    if(root->left!=NULL){ //in any tree, first we deal with left subtree and if it exists we flatten it by recursive calls 
        
        flatten(root->left); // flatten left subtree
        
        node *temp= root->right; // store right subtree
        root->right=root->left; // left subtree becomes right subtree
        root->left=NULL;        // left of every node becomes NULL

        node *tail= root->right; // find tail of right subtree (initially it is root->left as root->right was modified)
        while(tail->right!=NULL)
            tail=tail->right;

        tail->right= temp; // attach temp(right subtree at tail)
    }

    flatten(root->right); //flatten right subtree
}

void preorder(node *root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(void){

    node *root = new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->right= new node(6);

    /* 
        1
       / \
      2   3
     / \   \
    4   5   6
    */

   // after flattening inorder becomes preoder

   preorder(root);
   flatten(root);
   cout<<endl;
   inorder(root);
}
