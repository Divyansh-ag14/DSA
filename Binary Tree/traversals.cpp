/*
preorder  - root-left-right
indorder  - left-root-right
postorder - left-right-root
*/

#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data; 
    struct node *left, *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct node *root){ //root-left-right

    if(root==NULL) return;

    cout<<root->data<<" ";  // first print root
    preorder(root->left);   // then go to the left subtree and print the root
    preorder(root->right);  // then go to the right subtree 

}

void inorder(node *root){ //left-root-right

    if(root== NULL) return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}


void postorder(node *root){ //left-right-root

    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void levelOrder(node *root){ 

// push null in queue after every level
// for every inserted node check if right and left child are available if yes then push in queue

    if(root==NULL) return;

    queue<node*>q;
    q.push(root); // 0th level
    q.push(NULL); // null inserted

    while(!q.empty()){
        
        node *n= q.front();
        q.pop();

        if(n!=NULL){
            
            cout<<n->data<<" ";

            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);

        }

        // if q is empty means the last null has been popped out else some elments still remain denoting another levels
        else if(!q.empty()) // if q is not empty push null after the elements of next level
            q.push(NULL);

    }



}

int main(void){

    node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);

    /*
        1
       /  \
      2    3
     / \  / \
    4   5 6  7
    */

   cout<<"pre  : "; preorder(root);
   cout<<endl;
   cout<<"in   : "; inorder(root);
   cout<<endl;
   cout<<"post : "; postorder(root);
   cout<<endl;
   cout<<"level: "; levelOrder(root);



}
