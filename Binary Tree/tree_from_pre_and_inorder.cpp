/* ALGORITHM:

1. pick element from preoder and create a node
2. increment preorder idx
3. search for picked element's pos in inorder
4. build left subtree from inorder's 0 to pos-1
5. build right subtree from inorder's pos+1 to n
6. return the node

*/

#include<iostream>
using namespace std;
int idx=0;

class node{
    public:
    int data;
    node *left, *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


int findPos(int inorder[], int start, int end, int curr){

    for(int i=start; i<=end; i++){
        if(inorder[i]==curr)
            return i;
    }

}

node * buildTree(int preorder[], int inorder[], int start, int end){

    // base condition
    if(start>end) return NULL;

    //static int idx=0;
    int curr= preorder[idx];
    idx++;

    node *n= new node(curr);

    //if(start==end) return n;

    int pos= findPos(inorder, start, end, curr);

    n->left= buildTree(preorder, inorder, start, pos-1);
    n->right= buildTree(preorder, inorder, pos+1, end);

    return n;
}

// to validate
void printInorder(node *root){

    if(root==NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(void){

    int preorder[]= {1,2,4,3,5};
    int inorder[]= {4,2,1,5,3};

    node *root= buildTree(preorder, inorder, 0, 4);

    printInorder(root);


}