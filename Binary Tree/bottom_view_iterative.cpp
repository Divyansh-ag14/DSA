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
#include<queue>
#include<utility>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

vector<int> bottomView(node *root){

    vector<int>ans;

    if(root==NULL) return ans;

    map<int,int>m;
    queue<pair<node*, int>>q; // queue stores height and root

    q.push({root, 0});

    while(!q.empty()){

        node *n = q.front().first;
        int h = q.front().second;
        q.pop();

        m[h] = n->data;

        if(n->left) q.push({n->left, h-1});
        if(n->right) q.push({n->right, h+1});

    }

    for(auto i=m.begin(); i!=m.end(); i++)
        ans.push_back(i->second);

    return ans;

}

int main(void){

    vector<int>ans;

    ans=bottomView(root);

    for(auto i=ans.begin(); i<ans.end(); i++)
        cout<<*i<<" ";
}