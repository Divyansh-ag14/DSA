#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

node *LCA(node *root, int n1, int n2){

    if(root==NULL) return NULL;

    if(n1<root->data && n2<root->data)
        return LCA(root->left, n1, n2);

    else if(n1>root->data && n2>root->data)
        return LCA(root->right, n1, n2);

    else return root;
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

   node *lca = LCA(root, 5, 6);
   cout<<lca->data;
}