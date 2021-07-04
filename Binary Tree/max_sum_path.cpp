/* for every node calculate-
    1. node val
    2. max left tree sum + node 
    3. max right tree sum + node
    4. max left + right tree + node
*/



#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; };

};

// calculates all values for every node and returns the max
int maxSumUtil(node *root, int &ans){

    if(root==NULL) return 0;

    int leftsum= maxSumUtil(root->left, ans);
    int rightsum= maxSumUtil(root->right, ans);

    int nodeMax= max(max(root->data, root->data + leftsum + rightsum),
                     max(root->data + leftsum, root->data + rightsum));
    
    ans= max(ans, nodeMax);

    int singlePathSum= max(root->data, max(root->data + leftsum, root->data +rightsum));
    return singlePathSum;
}

int maxSum(node *root){

    if(root==NULL) return 0;

    int ans= INT_MIN;
   
    maxSumUtil(root, ans);

    return ans;

}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->right->left= new node(5);
    root->right->right= new node(6);
    root->right->left->left= new node(7);

    /*
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
    */

   cout<<maxSum(root);
   
}