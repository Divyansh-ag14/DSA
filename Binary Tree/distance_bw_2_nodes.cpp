/* 
1. find lca- (lowest common ancestor)
2. calculate distance d1 from lca to n1
3. calculate distance d2 from lca to n2;
4. return d1+d2
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; }
};

node* lca(node *root, int n1, int n2){

    if(root==NULL) return NULL;

    if(root->data==n1 || root->data==n2) 
        return root;

    node *left= lca(root->left, n1, n2);
    node *right= lca(root->right, n1, n2);

    if(left!=NULL && right!=NULL)
        return root;

    if(left==NULL && right==NULL)
        return NULL;
    
    if(left!=NULL)
        return left;
    
    else 
        return right;
}


// assumption - all nodes have positive data fields
int findDistance(node *LCA, int n, int dist){

    if(LCA==NULL) return -1;

    if(LCA->data==n) return dist;

    int left= findDistance(LCA->left, n, dist+1);
    if(left!=-1) return left;

    int right= findDistance(LCA->right, n, dist+1);
    return right;

}

int distanceBwNodes(node *root, int n1, int n2){

    node *LCA= lca(root, n1, n2);

    int d1= findDistance(LCA, n1, 0);
    int d2= findDistance(LCA, n2, 0);

    return d1+d2;


}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->right->right= new node(5);

    /*
        1
       / \
      2   3
     /     \
    4       5
    */

   cout<<distanceBwNodes(root, 4, 5);
}