#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

/*
    1. if both roots are null - return true
    2. if they are structurally different return false
    3. else for given nodes, check-
      a. roo1->data==root2->data
      b. left subtree of root1==left subtree of root2
      c. right subtree of root1== right subtree of root2

      return a && b && c
*/
bool isIdentical(node *root1, node *root2){

    if(root1==NULL && root2==NULL)
        return 1;

    else if(root1==NULL || root2==NULL)
        return 0;

    else{

        bool cond1= root1->data==root2->data;

        bool cond2= isIdentical(root1->left, root2->left);

        bool cond3= isIdentical(root1->right, root2->right);

        return cond1&&cond2&&cond3;
    }
}

int main(void){

    node *root1= new node(4);
    root1->left= new node(2);
    root1->right= new node(5);
    root1->left->left= new node(1);
    root1->left->right= new node(3);
    root1->right->right= new node(6);

    node *root2= new node(4);
    root2->left= new node(2);
    root2->right= new node(5);
    root2->left->left= new node(1);
    root2->left->right= new node(3);
    root2->right->right= new node(6);

    node *root3= new node(4);
    root3->left= new node(2);
    root3->right= new node(5);
    root3->left->left= new node(1);
    root3->left->right= new node(3);
    root3->right->right= new node(7);

    /* root1        root2      root3
        4            4           4
       / \          / \         / \
      2   5        2   5       2   5
     / \   \      / \   \     / \   \
    1   3   6    1   3   6   1   3   7
    */

    if(isIdentical(root1, root2))
        cout<<"identical"<<endl;
    else cout<<"not identical"<<endl;

    if(isIdentical(root1, root3))
        cout<<"identical"<<endl;
    else cout<<"not identical"<<endl;


}