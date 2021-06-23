#include<iostream>
using namespace std;

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

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

int main(void){

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);

    node * root2= new node(1);
    root2->left=new node(2);
    root2->right= new node(3);

    /*
       1
      / \
     2   3 
    */

   root->left->left= new Node(4);
   root->left->right= new Node(5);

   /*
       1
      / \
     2   3 
    / \
   4   5
    */


}
