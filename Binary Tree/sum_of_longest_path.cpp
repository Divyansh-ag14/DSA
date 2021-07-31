#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};


vector<int> sumUtil(node *root){

    if(root==NULL) return {0,0};

    vector<int> a = sumUtil(root->left);
    vector<int> b = sumUtil(root->right);

    if(a[0] > b[0]) return {a[0]+1, a[1]+root->data};
    if(b[0] > a[0]) return {b[0]+1, b[1]+root->data};

    else return {a[0]+1, max(a[1], b[1])+root->data};

}

int sum(node *root){

    vector<int>v = sumUtil(root);

    return v[1];
}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->right->left= new node(1);
    root->right->right= new node(6);

    /*
        1
       / \
      2   3
     /   / \
    4   1   6

    */

   cout<<sum(root);
}