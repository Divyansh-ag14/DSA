#include<iostream>
using namespace std;

struct node
{
    int data;
    node *right, *left;
    node(int val){ data=val; left=NULL; right=NULL; }
};

bool searchNode(node *root, int val){

    if(root==NULL) return 0;

    if(root->data==val) return 1;

    bool left= searchNode(root->left, val);

    if(left) 
        return 1; 

    bool right= searchNode(root->right, val);
    return right;

    return 0;
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

   cout<<searchNode(root, 5);
}