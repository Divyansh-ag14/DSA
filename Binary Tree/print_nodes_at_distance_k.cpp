/* 
for a given target node and a distance k
nodes can be present in either subtree or can be its ancestor

1. for subtrees- decrement k and return value when k is 0
2. for ancestors- first calcuate distance of all ancestors from the target node and then search subtrees of all ancestors till k is 0
   (if distance of ancestor is d- then search subtree for (k-d) distance)
   (if target node is in the right subtree of ancestor then search ancestor's left subtree and vica versa)

   (note case 2 is converted into case 1 after we have found the right ancestors)
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* left, *right;
    node(int val) { data=val; left=NULL; right=NULL; }
};

void printSubtreeNodes(node *root, int K){

    if(root==NULL || K<0) return;

    if(K==0){ // means we have found ans node
        cout<<root->data<<" "; // print it
        return; // we do not have to traverse this node anymore
    }

    // serach left and right subtrees for ans
    printSubtreeNodes(root->left, K-1);
    printSubtreeNodes(root->right, K-1);

}

// for ancestors- return a distance d
int printNodes(node *root, node *target, int K){

    if(root==NULL) return -1;

    if(root==target){ // travesre from root and find the target
        printSubtreeNodes(root, K); // now from root find ans nodes at distance k
        return 0;
    }

    // check for target in left subtree 
    int dl= printNodes(root->left, target, K); // k is not decremented as we have not found our target yet
    if(dl!=-1){ // means we have found our target in left subtree

        if(dl+1==K) // dl is Distance of root's left child from target, so we must add 1 with dl
            cout<<root->data<<" "; // if ancestor is at the right distance priint it
        
        else // else go to subtree of ancestor and print the ans nodes
            printSubtreeNodes(root->right, K-dl-2); // dl-2 - as we are calling from ancestor's right

        return dl+1;
    }

    // check for target in right subtree 
    int dr= printNodes(root->right, target, K); // k is not decremented as we have not found our target yet
    if(dr!=-1){ // means we have found our target in left subtree

        if(dr+1==K) // dr is Distance of root's right child from target, so we must add 1 with dr
            cout<<root->data<<" "; // if ancestor is at the right distance priint it
        
        else // else go to subtree of ancestor and print the ans nodes
            printSubtreeNodes(root->left, K-dr-2); // dl-2 - as we are calling from ancestor's left (-1 for anc, and -1 for left)

        return dr+1;
    }

    // if target is neither in right or left subtree return -1
    return -1;

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

   printNodes(root, root->right->left, 2); // target is 5

}