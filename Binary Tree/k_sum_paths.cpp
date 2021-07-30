#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void func(node *root, int x, vector<int>&path){

    if(root==NULL) return;

    path.push_back(root->data); // push value of current root
    
    func(root->left, x, path);
    func(root->right, x, path);

    // now we have a vector path containing value of some nodes

    int sum = 0; 

    for(int j = path.size()-1; j>=0; j--){ // iterate from the last

        sum+=path[j]; // add value of node to sum

        if(sum==x){ // if sum becomes x - print all the nodes form current pos to end

            for(int k=j; k<=path.size()-1; k++)
                cout<<path[k]<<" ";

            cout<<endl;
        }
    }

    path.pop_back(); // pop the last element 
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

   vector<int>path; func(root, 10, path);

}