#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};


int maxSum(node *root, int &mx){

    if(root==NULL) return 0;

    int l = maxSum(root->left, mx);
    int r = maxSum(root->right, mx);

    mx  = max(mx, l+r+root->data);

    return l+r+root->data;

}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->right->left= new node(5);
    root->right->right= new node(6);
    root->right->left->left= new node(7);

    /*
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
    */

   int mx=0;
   cout<<maxSum(root, mx);
}