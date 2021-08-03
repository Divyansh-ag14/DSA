#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void findPre(node *root, node *&pre){
    
    pre = root;
    while(pre!=NULL && pre->right!=NULL)
        pre=pre->right;

}

void findSuc(node *root, node *&suc){

    suc = root;
    while(suc!=NULL && suc->left!=NULL)
        suc=suc->left;

}

void findPreSuc(node* root, node*& pre, node*& suc, int key){

    if(root==NULL) return;

    if(key < root->data){
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
        
    else if(key > root->data){
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
        
    else{
        
        if(root->left) findPre(root->left, pre);
        if(root->right) findSuc(root->right, suc);
    }

}

int main(void){
}