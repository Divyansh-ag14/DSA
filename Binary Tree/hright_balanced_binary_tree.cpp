// (FOR EACH NODE) abs( Hieght of LEFT SUBTREE - Height of RIGHT SUBTREE ) <=1

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; }
};

int findHeight(node *root){

    if(root==NULL) return 0;
    return max(findHeight(root->left), findHeight(root->right)) + 1;

}


bool isBalanced(node *root){
// for every node 
// check if left subtree is balanced
// then check if right subtree is balanced
// if yes return true else return false

    if(root==NULL) return true;

    // if any node in left or right subtree is unbalanced then diretly return false
    if(isBalanced(root->left)==false) return false;
    if(isBalanced(root->right)==false) return false;

    int lh= findHeight(root->left);
    int rh= findHeight(root->right);

    if(abs(lh-rh)<=1) return true;
    else return false;

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

   cout<<isBalanced(root);


}

