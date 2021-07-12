#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};
/*
    use 2 stacks (for current and next level)
    push root in stack (curr)
    print root 
    if LtoR is 1 - push left child then right child in stack (next)
    else vica versa
    pop elments from curr stack
    swap curr and next
    change LtoR accordingly to 0 or 1
*/
    

void zigzag(node *root){

    // base condition
    if(root==NULL) return;

    stack<node *>currlevel, nextlevel;
    bool LtoR= 1;

    currlevel.push(root);

    while(!currlevel.empty()){
        
        node *temp= currlevel.top();
        currlevel.pop();

        if(temp!=NULL){
            cout<<temp->data<<" ";
            
            if(LtoR){

                if(temp->left)
                    nextlevel.push(temp->left);
                if(temp->right)
                    nextlevel.push(temp->right);
            }
            else{
                
                if(temp->right)
                    nextlevel.push(temp->right);
                if(temp->left)
                    nextlevel.push(temp->left);
            }

        }

        if(currlevel.empty()){
            
            LtoR= !LtoR;
            swap(currlevel, nextlevel);
        }
        
    }

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

   zigzag(root);
}