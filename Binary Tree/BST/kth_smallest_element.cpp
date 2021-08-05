#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void findK(node *root, int &idx, int k, int &ans){

    if(root==NULL) return;

    findK(root->left, idx, k, ans);

    if(k==idx){
        ans=root->data;
        return;
    }

    else idx++;

    findK(root->right, idx, k, ans);
}

int kthSmallestElement(node *root, int k){

    int ans = -1, idx=1;

    findK(root, idx, k, ans);

    return ans;
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

    cout<<kthSmallestElement(root, 4);
}