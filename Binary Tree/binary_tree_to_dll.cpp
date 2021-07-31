#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val) { data=val; left=right=NULL; }
};

void convert(Node *root, Node *&head, Node *&prev){ // (inorder - root->left - work - root->right)

    if(root==NULL) return;

    convert(root->left, head, prev);

    if(head==NULL){ // first node of dll

        head=prev=root;
    }

    else{

        prev->right = root; // assing current node on right of prev       2        (head and prev are currently at 1)
        root->left = prev; // prev becomes left of current node          /  \   => prev->right = 2  (1 -> 2)
        prev = prev->right; // update prev                              1    3     left of 2 becomes 1 (1 <=> 2)     
    }                                                                             // prev updated to 2

    convert(root->right, head, prev);                                           // now 3 will be converted
}

Node * bToDLL(Node *root){

    Node *head=NULL, *prev=NULL;

    convert(root, head, prev);

    return head;
}

int main(void){

    Node *root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->right->left= new Node(5);
    root->right->right= new Node(6);
    root->right->left->left= new Node(7);

    /*
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
    */

    Node *head = bToDLL(root);

    cout<<"NULL <=> ";
    while(head!=NULL){
       cout<<head->data<<" <=> ";
       head=head->right;
   }
   cout<<"NULL";

}