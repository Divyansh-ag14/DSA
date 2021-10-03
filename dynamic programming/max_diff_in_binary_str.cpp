/*

Given a binary string S consisting of 0s and 1s. 
The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) 
in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.

Example:

Input: S = "11000010001" 
Output: 6 

Explanation: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 

*/

#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

int maxSubstring(string &S){

    int ans=INT_MIN, mx=0;

    for(int i=0; i<S.length(); i++){

        // if only 1 is present: return -1
        // so for every 0 add 1 and for every 1 add -1
        int x = S[i]=='0' ? 1 : -1;

        mx += x;

        // store max ans at every point
        if(ans < mx) ans = mx;

        // if current sum is negative: reset it to 0
        if(mx < 0) mx = 0;

    }

    return ans;

}

int main(void){

    string S = "11000010001";
    cout<<maxSubstring(S);

}