#include<iostream>
#include<math.h>
using namespace std;

// gievn an integer find no of perfect squares less then it
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