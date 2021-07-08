/* (node > maxL && node < minR) 
   maxL= max of left subtree
   maxR= max of right subtree
*/

// optimization- in above approach, tree is traversed for eevry node to get maxL and maxR
// so we can use two vars - min_allowed and max_allowed
// for left subtree - min_allowed= min   max_allowed= node (min, node)
// for right subtree - min_allowed= node  max_allowed= max (node, max)

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){ data=val; left=right=NULL; }
};

// O(N) - a node is only traversed once as root node
bool checkBST(node *root, node *min, node *max){  // min and max are of type node - so we can pass the node instead of int value

    // base condition
    if(root==NULL) return 1;

    // first check if root>l and root<r (l and r are left and right child)
    if(min!=NULL && root->data <= min->data)
        return 0;
    
    if(max!=NULL && root->data >= max->data)
        return 0;

    bool leftValid= checkBST(root->left, min, root);
    bool rightValid= checkBST(root->right, root, max);

    return leftValid && rightValid;
    
}

int main(){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);

    node *root2= new node(2);
    root2->left= new node(1);
    root2->right= new node(3);

    cout<<checkBST(root,NULL, NULL)<<endl;
    cout<<checkBST(root2, NULL, NULL);
}