#include<iostream>
using namespace std;

struct node{
    int data; node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; }
};

node *buildBST(int preorder[], int key, int *preIdx, int min, int max, int n){

    // base condition
    if(*preIdx >= n) return NULL;

    node *root= NULL;
    
    if(key>min && key<max){
        
        root= new node(key);
        *preIdx+=1; // index of current element

        if(*preIdx < n)
            root->left= buildBST(preorder, preorder[*preIdx], preIdx, min, key, n); // max value in left subtree = key
    
        if(*preIdx < n)
            root->right= buildBST(preorder, preorder[*preIdx], preIdx, key, max, n); // min value in right subtree = key

    }

    return root;
}

void printPreorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){

    int preorder[]= {10, 2, 1, 13, 11};
    int preIdx=0;
    
    node *root = buildBST(preorder, preorder[0], &preIdx, 0, INT32_MAX, 5);
    printPreorder(root);

}