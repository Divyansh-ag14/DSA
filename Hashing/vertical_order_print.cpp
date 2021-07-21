/*  
    1. start with the root node (d=0)
    2. recursively call left and right with (d-1) and (d+1)
    3. push the value into vector corrseponding to the distance d
    4. output the map

    ex: [10, 7, 4, 3, 11, 14, 16]

        tree representation:
                 |    
                10          [-2] - 3
              |/ | \|       [-1] - 7
              7  |  4       [0]  - 10 11 14
            |/|\ | /|\|     [1]  - 4
            3   11/   16    [2]  - 16
            |    /    |      
                14    
                 |
        
        ans= 3 7 10 11 14 4 16

*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void getVerticalOrder(node *root, int d, map<int, vector<int>>&m){

    if(root==NULL) return;

    // push value of current node (key = distance of current node from root)
    m[d].push_back(root->data);

    getVerticalOrder(root->left, d-1, m);
    getVerticalOrder(root->right, d+1, m);

}

void printVerticalOrder(node *root, int d, map<int, vector<int>>m){

    getVerticalOrder(root, d, m);

    map<int, vector<int>> :: iterator it;

    for(it=m.begin(); it!=m.end(); it++){

        for(int i=0; i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
    }
}

int main(void){

    node *root= new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(16);

    map<int, vector<int>> m;

    printVerticalOrder(root, 0, m);
}