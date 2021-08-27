#include<iostream>
#include<math.h>
using namespace std;

int countSquares(int n){

    // root(n) generates perfect sqaure then ans is root-1;
    // else ans is root(n);

    int root = sqrt(n);

    if(root*root==n) return root-1;
    else return root;
}

int main(void){

    cout<<countSquares(16);
}