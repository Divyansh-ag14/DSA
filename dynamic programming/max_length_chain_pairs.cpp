/*
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
You have to find the longest chain which can be formed from the given set of pairs. 
 
Example:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}

Output: 3

Explanation: The given pairs are { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },
the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
*/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

struct val{

    int first, second;
};

int maxChain(struct val p[], int n){

    vector<int> dp(n, 1); // smallest length can be 1

    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
        v.push_back({p[i].first, p[i].second});

    int ans = 0;

    sort(v.begin(), v.end()); // sorted according to the 1st element of pairs

    // now we just have to check if the first element of next pair is greater then second element of last pair

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(v[j].second < v[i].first)
                dp[i] = max(dp[i], dp[j]+1);

        }

        ans = max(ans, dp[i]);

    }

    return ans;

}

int main(void){

    int N = 5;
    val P[N];

    for(int i=0; i<N; i++){

        int x, y; 
        cin>>x>>y;
        P[i].first = x;
        P[i].second = y;

    }

    cout<<maxChain(P, N);

}