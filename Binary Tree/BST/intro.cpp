/*
    1. The left subtree of a node contains only nodes with keys lesser then the node's keys.
    2. The right subtree of a node contains only nodes with keys greater then the node's keys.
    3. The left and right subtrees each must also be a binary tree. There must be no duplicate nodes.
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *right, *left;
    node(int val){ data=val; left=NULL; right=NULL; }
};

node *insertBST(node *root, int val){

    if(root==NULL) return new node(val); // if current node is empty - create and return a new node with given val

    if(val < root->data) // if val is smaller then current node then add it to root's left subtree
        root->left= insertBST(root->left, val);

    else 
        root->right= insertBST(root->right, val);

    return root;

}

void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(void){

    // build BST from an array
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    node *root=NULL;

    // create starting node with the first element of array 
    root= insertBST(root, arr[0]);

    for(int i=1; i<n; i++)
        insertBST(root, arr[i]);

    // inroder of BST gives a sroted output
    inorder(root);
}

