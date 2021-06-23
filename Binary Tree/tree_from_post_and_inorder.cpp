/* ALGORITHM

1. start from the end of postorder and pick element to create a node
2. decrement postorder idx
3. searched for the picked element's pos in inorder
4. build the right subtree from inorder's pos+1 to n
5. build the left subtree from inorder's 0 to pos-1
6. return the node

*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; };

};

int findPos(int inorder[], int start, int end, int curr){

    for(int i=start; i<=end; i++){
        if(inorder[i]==curr)
            return i;
    }
}

node *buildTree(int postorder[], int inorder[], int start, int end){

    // base condition
    if(start > end) return NULL;
    
    static int idx=end;
    int curr= postorder[idx];
    idx--;

    node *n= new node(curr);

    int pos= findPos(inorder, start, end, curr);

    n->right= buildTree(postorder, inorder, pos+1, end);
    n->left= buildTree(postorder, inorder, start, pos-1);

    return n;
    
}

void printInorder(node *root){
    if(root==NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(void){

    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = buildTree(postorder, inorder, 0, 4);
    printInorder(root);
}