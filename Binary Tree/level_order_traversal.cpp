#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data; 
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; }
};

void levelorder(node *root){

    if(root==NULL) return;

    queue<node*>q;
    q.push(root);

    while(!q.empty()){

        int size= q.size();

        for(int i=0; i<size; i++){
            node *n= q.front();
            q.pop();
            cout<<n->data<<" ";

            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
    }

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

    levelorder(root);
}