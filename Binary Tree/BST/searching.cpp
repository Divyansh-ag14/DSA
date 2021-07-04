#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){ data=val; left=right=NULL; }
};

bool search(node *root, int val){

    if(root==NULL) return 0;

    if(root->data==val) return 1;

    if(val < root->data)
        return search(root->left, val);
    
    if(val > root->data)
        return search(root->right, val);

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

   cout<<search(root, 8)<<endl<<search(root, 6);
}