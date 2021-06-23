#include<iostream>
using namespace std;

struct node
{
    int data;
    node *right, *left;
    node(int val){ data=val; left=NULL; right=NULL; }
};

int countNodes(node *root){
// sum of (left subtree count  + right subtree count + 1 (for current node))

    if(root==NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;

}

int sumNodes(node *root){
// sum of (left subtree sum + right subtree sum + current node value)

    if(root==NULL)
        return 0;

    return sumNodes(root->left) + sumNodes(root->right) + root->data;
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

   cout<<countNodes(root)<<endl;
   cout<<sumNodes(root);
}
