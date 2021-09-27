#include<iostream>
#include<string>
using namespace std;

// check iterative first
// during the process we only check i-1 and j-1 positions
// so we only need two rows (as at every point we go back to the prev row at max)
int lcs(int x, int y, string s1, string s2){

    int dp[2][y+1];
    
    // intially dp array has zeros (note 1st row and 1st col will always remain 0)
    for(int i=0; i<2; i++){
        for(int j=0; j<=y; j++)
            dp[i][j] = 0;
    }

    for(int i=1; i<=x; i++){

        for(int j=1; j<=y; j++){

            if(s1[i-1]==s2[j-1]) // if chars are equal add 1 to prev ans
                dp[i%2][j] = 1 + dp[(i-1)%2][j-1]; // i%2 to keep it in range 0-1

            else // if chars are not equal store the max ans till now
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
        
        }
    
    }

    return dp[x%2][y];
}

int main(void){

    int A = 6, B = 6;
    string str1 = "ABCDGH", str2 = "AEDFHR";

    cout<<lcs(A, B, str1, str2);
}
