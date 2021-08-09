#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

bool search(node *root, int val){

    if(root==NULL) return 0;

    if(val == root->data) return 1;

    else if(val < root->data)
        return search(root->left, val);

    else return search(root->right, val);
}

void getPairs(node *root1, node*root2, int x, int &count){

    if(root1==NULL) return;

    getPairs(root1->left, root2, x, count);

    if(search(root2, x-root1->data)) 
        count++;

    getPairs(root1->right, root2, x, count);



}

int countPairs(node *root1, node *root2, int x){

    int count=0;
    getPairs(root1, root2, x, count);
    return count;
}

int main(void){
}