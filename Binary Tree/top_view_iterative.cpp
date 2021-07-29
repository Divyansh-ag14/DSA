#include<iostream>
#include<map>
#include<queue>
#include<utility>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val) { data=val; left=right=NULL; }
};

vector<int> topView(node *root){

    vector<int>ans;

    if(root==NULL) return ans;

    map<int,int>m;
    queue<pair<node*, int>>q; // queue stores height and root

    q.push({root, 0});

    while(!q.empty()){

        node *n = q.front().first;
        int h = q.front().second;
        q.pop();

        if(!m[h]) m[h] = n->data;

        if(n->left) q.push({n->left, h-1});
        if(n->right) q.push({n->right, h+1});

    }

    for(auto i=m.begin(); i!=m.end(); i++)
        ans.push_back(i->second);

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