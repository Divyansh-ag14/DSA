/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, 
the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) { val=x; left=right=NULL; }
};

int util(TreeNode *root, unordered_map<TreeNode*, int> &m){

    // if no node is peresent: retur 0
    if(root==NULL) return 0;

    // if map already has some value: return it
    if(m[root] != 0) return m[root];

    // we have 2 options: (take root and its non adjecent nodes) or (take adjecent nodes)
    // find some of both options and return max

    int sum_of_non_adj_nodes = 0;

    if(root->left)
        sum_of_non_adj_nodes += util(root->left->left, m) + util(root->left->right, m);

    if(root->right)
        sum_of_non_adj_nodes += util(root->right->left, m) + util(root->right->right, m);

    int sum_of_adj_nodes = util(root->left, m) + util(root->right, m);

    m[root] = max(sum_of_non_adj_nodes+root->val, sum_of_adj_nodes);

    return m[root];
}

int rob(TreeNode *root){

    // dp map: by default int is 0
    unordered_map<TreeNode*, int>m;

    return(util(root, m));
}

int main(void){


}