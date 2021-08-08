#include<iostream>
#include<limits.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

bool isDeadUtil(node *root, int min, int max){

    if(root==NULL) return 0;

    if(min==max) return 1;

    return isDeadUtil(root->left, min, root->data-1) || isDeadUtil(root->right, root->data+1, max);
}

bool isDead(node *root){
    return isDeadUtil(root, 1, INT_MAX);
}


int main(void){

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);


    /*
        1
      /   \
    2     3
  /
 4
 */

    cout<<isDead(root);
}