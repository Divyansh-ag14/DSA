#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void inorder_util(node *root, vector<node*>&v){

    if(root==NULL) return;

    inorder_util(root->left, v);

    v.push_back(root);

    inorder_util(root->right, v);
}

node *convert_util(int l, int r, vector<node*>&v){

    if(l>r) return NULL;

    int m = (l+r)/2;

    node *root =  v[m];

    root->left = convert_util(l, m-1, v);
    root->right = convert_util(m+1, r, v);

    return root;

}

node *convert(node *root){

    vector<node*>v;

    inorder_util(root, v);

    return convert_util(0, v.size()-1, v);

}

void inorder(node *root){

    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(void){

    node *root= new node(7);
    root->left = new node(6);
    root->left->left = new node(5);
    root->left->left->left = new node(4);
    root->left->left->left->left = new node(3);
    root->left->left->left->left->left = new node(2);
    root->left->left->left->left->left->left = new node(1);

    inorder(root);
    root = convert(root);
    cout<<endl;
    inorder(root);


}
