// Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int kadane(vector<int> v){

    int ans=INT_MIN;
    int mx_until=0;

    for(int i=0; i<v.size(); i++){

        mx_until += v[i];

        if(mx_until > ans) ans = mx_until;

        if(mx_until < 0) mx_until = 0;

    }

    return ans;

}


// Expected Time Complexity:O(R*R*C)
// Expected Auxillary Space:O(R*C)
int maximumSumRectangle(int R, int C, vector<vector<int>> M){

    int ans = INT_MIN;

    for(int i=0; i<R; i++){ // for every row

        vector<int> v(C); // create a vector to store the rows 

        for(int j=i;j<R; j++){ // store and add elements of every row from current row till last row

            for(int k=0; k<C; k++){

                v[k] += M[j][k];

            }

            // compare max sum of current subarray with ans 
            // use kadane algo to find mss
            ans = max(ans, kadane(v));
        }

    }

    return ans;

}

int main(void){

    int R=4, C=5;
    vector<vector<int>> M={
        {1,2,-1,-4,-20},
        {-8,-3,4,2,1},
        {3,8,10,1,3},
        {-4,-1,1,7,-6}
    };

    cout<<maximumSumRectangle(R, C, M);
}