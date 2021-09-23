#include<bits/stdc++.h>
using namespace std;

int dp[10005];

int util(int n, int x, int y, int z){

    if(n==0) return 0; // if legnth becomes 0: no more cuts

    if(dp[n] != -1) return dp[n]; // if dp array already has some value return it

    // at every step we have 3 options to cut
    int cut1, cut2, cut3;
    cut1=cut2=cut3=INT_MIN; // initially set to the min pssoible value (so, if condition is not satisfied they will remain min)

    if(n>=x) cut1 = util(n-x, x, y, z); // if current length is greter then x: only then cut it by x
    if(n>=y) cut1 = util(n-y, x, y, z); // if current length is greter then y: only then cut it by y
    if(n>=z) cut1 = util(n-z, x, y, z); // if current length is greter then z: only then cut it by z

    // store the max of cut value, add 1 to it (current cut) and return it
    return dp[n] = 1 + max(cut1, max(cut2, cut3)); 

}

int maximizeTheCuts(int n, int x, int y, int z){

    if(n==0) return 0; // if length is 0 no cuts can be made

    memset(dp, -1, sizeof(dp));

    int ans = util(n, x, y, z);
        
    return ans<0 ? 0 : ans;
}

int main(void){
}