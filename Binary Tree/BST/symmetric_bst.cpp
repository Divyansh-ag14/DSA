// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

bool util(node *a, node *b){

    if(!a && !b) return 1; // if both are null: return 1
    if(!a || !b) return 0; // if either is null: return 0

    if(a->data != b->data) return 0; // if val is not equal: return 0

    // check if both subtrees are symmetrical
    return util(a->left, b->right) && util(a->right, b->left);
}

bool isSymeetric(node *root){

    if(root==NULL) return 1; // if there are no elements return 1

    return util(root->left, root->right);
}

int main(void){
}