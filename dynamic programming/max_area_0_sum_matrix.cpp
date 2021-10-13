#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;

// function to get the length of mss
int getZero(vector<int> v){

    int ans=0;
    unordered_map<int,int> m;

    int s=0;
    for(int i=0; i<v.size(); i++){

        s+= v[i];

        // helps when all the element are positive and one element is 0
        if(v[i]==0 && ans==0)
            ans=1;

        // if sum becomes 0: ans = index + 1 as index starts from 0
        if(s==0)
            ans = i+1;

        // if a sum is repeated again: in between some numbers add upto 0
        // from current index subtract the index where sum first occured
        // store the max value
        else if(m.find(s) != m.end())
            ans = max(ans, i-m[s]);
        
        else m[s]=i;

    }

    return ans;

}

int findMatrix(int R, int C, vector<vector<int>> M){

    int ans = INT_MIN;

    for(int i=0; i<R; i++){

        vector<int> v(C);

        for(int j=i; j<R; j++){

            for(int k=0; k<C; k++){

                v[k] += M[j][k];

            }

            // getZero returns length of 1 d array multiply it with current row - ith row (+1 for coz 0 based indexing)
            ans = max(ans, getZero(v)*(j-i+1));

        }

    }

    return ans;

}

int main(void){

    vector<vector<int>> M = { 
                                { 9, 7, 16, 5 }, 
                                { 1, -6, -7, 3 },
                                { 1, 8, 7, 9 }, 
                                { 7, -2, 0, 10 } 
                            };

    cout<<findMatrix(4, 4, M);
}