/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.

Example
Input:

1
5 3
1
2
8
4
9

Output:

3

*/

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int n, int m, int c){

    int cows=1;
    int pos = arr[0];

    for(int i=1; i<n; i++){

        if(arr[i]-pos >= m){

            cows++;
            pos=arr[i];
        
        }

        if(cows == c)
            return 1;

    }

    return 0;
}


int main(void){

    int t; cin>>t;
    while(t--){

        int n,c; 
        cin>>n>>c;
        
        int arr[n];

        for(int i=0; i<n; i++) cin>>arr[i];

        sort(arr, arr+n); // sorting is imp

        int i=1, j = 1e9;

        int ans =0;

        while(i<=j){

            int m = (i+j)/2;

            if(isFeasible(arr, n, m, c)){ // if current ans(distance) is valid

                ans= m; // update the ans
                i= m+1; // try maximizing it, by increasing lower bound(i)
        
            }

            else // if ans is not valid
                j= m-1; // decrease upprer bound (j)

        }

        cout<<ans<<endl;

    }
    
}