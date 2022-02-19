/*

Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

int rangeSumBST(node *root, int low, int high){

    if(root==NULL) return 0;

    if(root->data>=low && root->data<=high)
        return root->data + rangeSumBST(root->left, low, high)
        + rangeSumBST(root->right, low, high);

    if(root->data > high) return rangeSumBST(root->left, low, high);

    else return rangeSumBST(root->right, low, high);

}

int main(void){
}