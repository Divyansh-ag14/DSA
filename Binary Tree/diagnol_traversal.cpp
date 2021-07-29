#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val) { data=val; left=right=NULL; }
};

vector<int> diagnol(Node *root){

    vector<int>ans;

    if(root==NULL) return ans;

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){

        Node *n = q.front();
        q.pop();

        while(n){ // keep pushing right in vector and left in queue

            if(n->left) q.push(n->left);
            ans.push_back(n->data);
            n = n->right;
        }
    }

    return ans;
}

int main(void){

    Node *root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);

    /*
        1
       /  \
      2    3
     / \  / \
    4   5 6  7
    */

   vector<int>ans = diagnol(root);

   for(auto i: ans) cout<<i<<" ";

}