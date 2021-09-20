/*

Given a binary tree with a value associated with each node, 
we need to choose a subset of these nodes such that sum of chosen nodes is maximum 
under a constraint that no two chosen node in subset should be directly connected that is, 
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Ex:
        1
      /   \
     2     3
    /     /  \
   4     5    6
ans = 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val) { data=val; left=right=NULL; }
};

int util(Node *root, unordered_map<Node*, int> &m){

    if(root==NULL) return 0; // no root no value

    if(m[root] != 0) return m[root]; // if map has some value: return it

    // at every point we have 2 options: take adj nodes or take root and non adj nodes

    // find sum of non adj nodes
    int sum_of_non_adj_nodes = 0;

    if(root->left)
        sum_of_non_adj_nodes += util(root->left->left, m) +
                                util(root->left->right, m);

    if(root->right)
        sum_of_non_adj_nodes += util(root->right->left, m) + 
                                util(root->right->right, m);

    // find some of adj nodes
    int sum_of_adj_nodes = util(root->left, m) + util(root->right, m);

    // store the max value bw adj nodes and non adj nodes + root
    return m[root] = max(sum_of_non_adj_nodes + root->data, sum_of_adj_nodes);

}

int getMaxSum(Node *root){

    // map to store node and its value at every point
    // unordered map for better time complexity
    unordered_map<Node*, int>m;

    return util(root, m);
}

int main(void){
}