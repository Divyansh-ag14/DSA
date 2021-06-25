#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data; 
    node *left, *right;
    node(int val){ data=val; left=NULL; right=NULL; }
};

bool getPath(node *root, int n, vector<int>&p){

    // base case
    if(root==NULL) return false;

    p.push_back(root->data); // push the current node (int val)

    if(root->data==n) // if equal to n- return true
        return true;

    // else find n in left and right subtree
    if(getPath(root->left, n, p) || getPath(root->right, n, p))
        return true;
    
    // if not present in either- then pop the current element from vector and return false
    p.pop_back();
    return false;
}

// find path of both n1 and n2 from root node
// the first element from where path changes is the lca- (lowest common ancestor) 
// O(n)
int lca(node *root, int n1, int n2){

    vector<int>p1,p2; // for storing paths

    // first check if n1 and n2 are valid nodes- if not return -1
    if(!getPath(root, n1, p1) || !getPath(root, n2, p2))
        return -1;

    int pc;
    for(pc=0; pc<p1.size() && p2.size(); pc++){
        if(p1[pc] != p2[pc])
            break;
    }

    return p1[pc-1];

}

// O(n)

node *lca2(node *root, int n1, int n2){

    if(root==NULL) return NULL;

    if(root->data==n1 || root->data==n2)
        return root;
    
    node *left= lca2(root->left, n1, n2);
    node *right= lca2(root->right, n1, n2);

    if(left!=NULL && right!=NULL)
        return root;
    
    else if(left==NULL && right==NULL)
        return NULL;

    else if(left!=NULL)
        return left;

    else return right;

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
       /  \
      2    3
     /    / \
    4    5   6
        /
       7
    */

   int n1=7, n2=6;

   cout<<lca(root, n1, n2)<<endl;
    node *LCA=lca2(root, n1, n2);
    cout<<LCA->data;
}