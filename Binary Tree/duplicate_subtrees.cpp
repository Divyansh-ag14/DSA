#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

// (we are checking if duplicate subtree of size >= 2 are present or not)

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

string util(node *root, unordered_map<string,int>&m){

    string s = "";

    if(root==NULL) return "#";

    if(!root->left && !root->right)
        return to_string(root->data);

    s+= to_string(root->data);
    s+= util(root->left, m);
    s+= util(root->right, m);

    m[s]++;

    return s;
}

bool dupSub(node *root){

    unordered_map<string,int>m;

    util(root, m);

    for(auto i: m)
        if(i.second >= 2)
            return 1;

    return 0;

}

int main(void){

    node *root= new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(2);
    root->right->right->left = new node(4);
    //root->right->right->right = new node(5);

    /*
        1
       / \
      2   3
     / \   \
    4   5   2
           / \
          4   5
    */

    cout<<dupSub(root);
}