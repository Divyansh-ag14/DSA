#include<iostream>
#include<vector>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> M){

    // we are not creating new dp array: modify the given array

    // start from the 2nd col as the last cols has max values for it already
    for(int i=m-2; i>=0; i--){

        for(int j=0; j<n; j++){ // for every row element in that col

            int right = M[j][i+1]; // get the element next to it

            int right_up = j==0 ? 0 : M[j-1][i+1]; // get the upper right element 
 
            int right_down = j==n-1 ?  0 : M[j+1][i+1]; // get the lower right element

            // store the max path ans
            M[j][i] = M[j][i] + max(right, max(right_up, right_down));

        }

    }

    // after the above loops ans will be in the first col
    // check first element of every row

    int ans = M[0][0];

    for(int i=1; i<n; i++)
        ans = max(ans, M[i][0]);

    return ans;
}

int main(void){

    int n = 4, m = 4;

    vector<vector<int>>M = {{1, 3, 1, 5},
                            {2, 2, 4, 1},
                            {5, 0, 2, 3},
                            {0, 6, 1, 2}};

    cout<<maxGold(n, m, M);
    
}