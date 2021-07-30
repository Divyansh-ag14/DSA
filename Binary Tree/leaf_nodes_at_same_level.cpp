#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void checkUtil(node *root, int h, int &height, bool &ans){

    if(root==NULL) return;

    if(ans==0) return;

    if(!root->left && !root->right){ // leaf node

        if(height == -1) // we are at first leaf node 
            height = h; // update height

        else{

            if(height != h) // if prev height is not equal to current - ans = 0
                ans=0;
        }
    }

    checkUtil(root->left, h+1, height, ans);
    checkUtil(root->right, h+1, height, ans);
}

bool check(node* root){

    bool ans = 1;
    int height = -1;

    checkUtil(root, 0, height, ans);

    return ans;
}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    //root->right->left= new node(6);
    //root->right->right= new node(7);

    /*
        1 
       /  \
      2    3
     / \   
    4   5  
    */

   cout<<check(root);
}