#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};


bool compare(node *root1, node *root2){

    return root1->data < root2->data;
}

void inorder_util(node *root, vector<node*>&v){

    if(root==NULL) return;

    inorder_util(root->left, v);

    v.push_back(root);

    inorder_util(root->right, v);
}

node *merge_util(int l, int r, vector<node*>&v){

    if(l>r) return NULL;

    int m = (l+r)/2;

    node *root =  v[m];

    root->left = merge_util(l, m-1, v);
    root->right = merge_util(m+1, r, v);

    return root;

}

node *merge(node *root1, node*root2){

    vector<node*>v;

    inorder_util(root1, v);
    inorder_util(root2, v);

    sort(v.begin(), v.end(), compare);

    return merge_util(0, v.size()-1, v);

}

void inorder(node *root){

    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(void){

    node *root1= new node(4);
    root1->left= new node(2);
    root1->right= new node(5);
    root1->left->left= new node(1);
    root1->left->right= new node(3);
    root1->right->right= new node(6);

    node *root2= new node(10);
    root2->left= new node(8);
    root2->right= new node(11);
    root2->left->left= new node(7);
    root2->left->right= new node(9);
    root2->right->right= new node(12);

    /* root1        root2      
        4            10           
       / \          / \         
      2   5        8   11       
     / \   \      / \   \     
    1   3   6    7   9   12   
    */

    cout<<"root1: "; inorder(root1);
    cout<<endl<<"root2: "; inorder(root2);

    node *root = merge(root1, root2);
    cout<<endl;
    inorder(root);


}
