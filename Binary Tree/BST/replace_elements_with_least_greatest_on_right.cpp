#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

node* insert(node *root, int key, node *&successor){

    if(root==NULL)
        return new node(key);

    if(key < root->data){
        successor=root;
        root->left = insert(root->left, key, successor);

    }

    if(key>root->data){
        root->right = insert(root->right, key, successor);
    }

    return root;
}

void replace(int arr[], int n){

    node *root=NULL;

    for(int i=n-1; i>=0; i--){

        node *successor = NULL;
        root = insert(root, arr[i], successor);

        if(successor)
            arr[i] = successor->data;

        else arr[i] = -1; // if no successor is found 

    }
}

int main(void){
}