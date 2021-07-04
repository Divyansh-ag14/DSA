/*
    1. node - is a leaf node: we can directly delete this node
    2. node has one child: replace node with the child and delete the node
    3. node has two children: find the inorder succcessor - replace node with in. succ. - delete the node
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){ data=val; left=right=NULL; }
};

node *inorderSuccessor(node *root){

    //node *curr= root;

    while(root!=NULL && root->left!=NULL) // min value will be in the left subtree
        root=root->left;
    
    return root;
}

//after deletion, this function returns the modified root 
node *delBST(node *root, int val){

    if(root==NULL) return root;

    if(val < root->data)
        root->left= delBST(root->left, val); // if key is found in left subtree then root->left (pointer) is returned 
                                             // highlighting the modifications
        
    else if(val > root->data)
        root->right= delBST(root->right, val);

    else{ // we have found the target node

        // check the 3 cases (leaf, one child, two children)

        // case 1 and 2
        if(root->left==NULL){
            node *temp= root->right; // right can also be null - it is a valid value - hence case 1 is also checked
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp= root->left;
            free(root);
            return temp;
        }

        else{ // case 3- two children - (inroder successor)

            node *temp= inorderSuccessor(root->right); // find successor (it is always in the right subtree)

            // modify root with temp (hence target is deleted)
            root->data= temp->data;

            // now delete the inorder successor as there are 2 same values in tree right now
            root->right= delBST(root->right, temp->data);
        }
    }

    return root;
}

void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(void){

    node *root= new node(4);
    root->left= new node(2);
    root->right= new node(5);
    root->left->left= new node(1);
    root->left->right= new node(3);
    root->right->right= new node(6);

    /*
        4
       / \
      2   5
     / \   \
    1   3   6
    */
 
   inorder(root);
   cout<<endl;
   root= delBST(root, 5);
   inorder(root);
   cout<<endl;
   root= delBST(root, 2);
   inorder(root);
}