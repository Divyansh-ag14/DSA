#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; }
};

int calcHeight(node *root){ // T: O(n)

    if(root==NULL) return 0;

    // int lheight= calcHeight(root->left);
    // int rheight= calcHeight(root->right);
    // return max(lheight, rheight) + 1;

    return max(calcHeight(root->left), calcHeight(root->right)) + 1;

}

// no. of nodes in the longest path between any 2 leaves
// it may or may not pass through the root node
int calcDiameter(node *root){ // T: O(n^2) for n nodes calcheight is called which takes O(n) time

    if(root==NULL) return 0;

    int lheight= calcHeight(root->left);
    int rheight= calcHeight(root->right);
    int curr_d= lheight + rheight + 1;

    int l_d= calcDiameter(root->left);
    int r_d= calcDiameter(root->right);

    return max(curr_d, max(l_d, r_d));

}

// optimized approach - instead of calling calcHeight() use a pointer for height

int calcDiameter2(node *root, int *height){

    if(root==NULL){
        *height=0;
        return 0;
    }

    int lh=0, rh=0;
    int l_d= calcDiameter2(root->left, &lh);
    int r_d= calcDiameter2(root->right, &rh);

    int curr_d= lh + rh + 1;
    *height= max(lh,rh) + 1;

    return max(curr_d, max(l_d, r_d));
}

int main(void){

     node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->right= new node(5);

    /*
        1
       /  \
      2    3
       \  
        5 
    */

   cout<<calcHeight(root)<<endl;
   cout<<calcDiameter(root)<<endl;
   int height=0;
   cout<<calcDiameter2(root, &height);
}