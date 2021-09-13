#include<iostream>
#include<limits.h>
using namespace std;

int minJumps(int arr[], int n){

    if(n==1) return 0; // if size is 1: we are already at end
    if(arr[0]==0) return -1; // if 1st element is 0: no jumps can be made

    int dp[n]; // dp array: it stores the min. number of jumps required to reach a point
    for(int i=0; i<n; i++) dp[i]=INT_MAX; // intitially filled with INT_MAX (as we have to minimize the values)

    dp[0]=0; // 1st element requires no jump

    for(int i=1; i<n; i++){ // start loop from 1: for 0 we already have marked ans in dp

        for(int j=0; j<i; j++){ // look at all ways of reaching i

            if(dp[j]!=INT_MAX && arr[j]+j >= i){ // if a pos can be visited and using it we can reach i

                if(dp[j]+1 < dp[i]) // check if the jumps required are less then the current value 
                    dp[i] = dp[j]+1;

            }

        }

    }

    if(dp[n-1]!=INT_MAX) return dp[n-1]; // if end can not be reached: return -1

    return -1;

}

int main(void){

    
}