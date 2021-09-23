/*

Given a fence with n posts and k colors, find out the number of ways of painting the fence 
such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

*/

#include<iostream>
using namespace std;

int mod = 1e9+7;
long long countWays(int n, int k){
        
    if(n==0) return 0; // if there are no fences return 0
        
    if(n==1) return k; // if n==1: number of ways of painting it is equal to the numebr of colors

    // for the first 2 fences        
    long long same = k%mod; // if there are k colors first can be painted with k options and second with only 1 option (k*1)
    long long diff = (k*(k-1))%mod; // firt can be painted with k options and the other in k-1 as we leave one color to make them different
    long long total = (same+diff)%mod; // total ways = sum of both the options
        
    for(int i=3; i<=n; i++){ // for 3rd fence and beyond
            
        same = diff%mod; // last fence can be colored same using prev(diff) as same already has 2 adjecent fences with same color
        diff = (total*(k-1))%mod; // to color the last fence different simply take the prev total and multiply with k-1 
        total = (same+diff)%mod; // store sum of both ways
            
    }
        
    return (total%mod);
    
}

int main(void){
}