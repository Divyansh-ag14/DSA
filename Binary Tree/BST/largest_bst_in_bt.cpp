#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};




// for every node store - Bst(bool), size, min, max in a vector
// for very node check max of left child and min of right child

vector<int> largestUtil(node *root){

    if(root==NULL) return {1, 0, INT_MAX, INT_MIN}; // if root is null bst is true, size is 0
                                                    // min is max and max is min (this helps when either left or right child is NULL)


    // leaf node
    if(root->left==NULL && root->right==NULL) return {1, 1, root->data, root->data};

    vector<int> l = largestUtil(root->left);
    vector<int> r = largestUtil(root->right);

    // if both l and r are bst
    if(l[0] && r[0]){

        if(root->data > l[3] && root->data < r[2]){ // check if root is bigger then left's biggest value and smaller then right's smallest

            int min = l[2];
            int max = r[3];

            if(min==INT_MAX) min =root->data;
            if(max=INT_MIN) max=root->data;

            // size becomes l + r + 1
            return {1, l[1]+r[1]+1, min, max};

        }
    }

    // else 
    return {0, max(l[1], r[1]), 0, 0};           
}

int largestBst(node *root){

    vector<int>ans = largestUtil(root);

    return ans[1]; // size is stored at 1st index
}

int main(void){
}