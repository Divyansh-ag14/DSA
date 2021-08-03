/* store the inorder in vector
    sort the vector
    perform inorder travesral again and replace root with element in vector
    be happy
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void inorder_util(node *root, vector<int>&v){

    if(root==NULL) return;

    inorder_util(root->left, v);

    v.push_back(root->data);

    inorder_util(root->right, v);
}

void util(node *root, vector<int>&v){

    if(root==NULL) return;

    util(root->left, v);

    root->data = v[0];
    v.erase(v.begin());

    util(root->right, v);
}

node *binaryTreeToBST (node *root){
        
    vector<int>v;
        
    inorder_util(root, v);
        
    sort(v.begin(), v.end());
        
    util(root, v);
        
    return root;

}

void inorder(node *root){

    if(root==NULL) return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
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

    cout<<"before: "; inorder(root);
    root = binaryTreeToBST(root);
    cout<<endl;
    cout<<"after: "; inorder(root);
}