/*
A Derangement is a permutation of n elements, such that no element appears in its original position. 
For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.
*/

#include<iostream>
using namespace std;

// Time complexity is exponential
int countDer(int n){

    if(n==0 || n==1)
        return 0;
    
    if(n==2) return 1;

    // a number can be placed in n-1 ways 
    // if suppose first element is placed at last (or any other pos) and last element is placed at first: n-2 options
    // if the number is placed at any pos but the number at that pos is not exchanged: n-1 options
    return (n - 1) * (countDer(n - 1) + countDer(n - 2));

}

// dynamic approach

int dp[1000];

// T: O(n)  S: O(n)
int countDer2(int n){

    dp[0]=0, dp[1]=0, dp[2]=1;

    for(int i=3; i<=n; i++)
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);

    return dp[n];
}

// space optimized approach
// as for every element we only have to check i-1 and i-2th elements: we can store them in variables rather than array
// T: O(n)  S: O(1)
int countDer3(int n){

    if(n==0 || n==1) return 0;
    if(n==2) return 1;

    int a = 0; // dp[1]
    int b = 1; // dp[2]

    for(int i=3; i<=n; i++){

        int temp = (i-1) * (a+b);
        a = b;
        b = temp;

    }

    return b;

}

int main(void){

    cout<<countDer(4)<<endl;
    cout<<countDer2(4)<<endl;
    cout<<countDer3(4);
}