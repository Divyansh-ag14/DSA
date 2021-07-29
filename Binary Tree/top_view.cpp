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
#include<utility>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

void topViewUtil(node *root, int d, int depth, map<int, pair<int,int>>&m){

    if(root==NULL) return;

    // push value of current node (key = distance of current node from root)
    if(!m[d].first)
    m[d] = {root->data, depth};

    if (m[d].second > depth) // if node is already present (check min depth)
    m[d] = {root->data, depth};

    topViewUtil(root->left, d-1, depth+1, m);
    topViewUtil(root->right, d+1, depth+1, m);

}


vector<int> topView(node *root){

    map<int, pair<int,int>>m;
    vector<int>ans;

    topViewUtil(root, 0, 0, m);

    for(auto i = m.begin(); i!=m.end(); i++){
        ans.push_back(i->second.first);
    }

    return ans;
}

int main(void){

    node* root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(5);
    root->left->right = new node(3);
    root->right->right = new node(25);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);

    vector<int>ans;

    ans=topView(root);

    for(auto i=ans.begin(); i<ans.end(); i++)
        cout<<*i<<" ";
}