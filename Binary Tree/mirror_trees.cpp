#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val) { data=val; left=right=NULL; }
};

bool mirror(Node *root1, Node *root2){

    if(!root1 && !root2) return 1;

    if(!root1 || !root2) return 0;

    if(root1->data != root2->data) return 0;


    bool l = mirror(root1->left, root2->right);
    bool r = mirror(root1->right, root2->left);

    return l&&r;

}

int main(void){

    Node *a = new Node(1);
    Node *b = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    a->left->left  = new Node(4);
    a->left->right = new Node(5);
 
    b->left = new Node(3);
    b->right = new Node(2);
    b->right->left = new Node(5);
    //b->right->right = new Node(4);

    cout<<mirror(a, b);
}