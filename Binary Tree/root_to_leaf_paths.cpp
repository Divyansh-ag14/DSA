#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};


void pathsUtil(node *root, vector<int>arr, vector<vector<int>>&path){

    if(root==NULL) return;

    arr.push_back(root->data); // push value of current node

    if(root->left==NULL && root->right==NULL){ // if we are at leaf node - means we have a complete path

        path.push_back(arr); // push the entire array into vector
        return;
    }

    pathsUtil(root->left, arr, path);
    pathsUtil(root->right, arr, path);
}

vector<vector<int>> paths(node *root){

    vector<vector<int>>path;

    if(root==NULL) return path;

    vector<int>arr;

    pathsUtil(root, arr, path);

    return path;
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

    vector<vector<int>> path = paths(root);

    for(auto it = path.begin(); it!=path.end(); it++){

        for(auto i: *it) cout<<i<<" ";
        cout<<endl;
    }
}