/*
    1. make middle element root
    2. recursively form subtrees
      a. start to mid-1 (left subtree)
      b. mid+1 to end (right subtree)
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

node *buildBST(int arr[], int start, int end){

    if(start>end) return NULL;

    int m= (start+end) / 2;
    node *root= new node(arr[m]);
    
    root->left= buildBST(arr, start, m-1);
    root->right= buildBST(arr, m+1, end);

    return root;
}

void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(void){

    node *root;
    int arr[10] = { 1, 10, 13, 15, 25, 30, 45, 60, 70, 90};
    root= buildBST(arr, 0, 9);
    inorder(root);
    cout<<endl;
    preorder(root);
}
