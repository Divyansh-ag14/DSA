#include<iostream>
#include<string>
using namespace std;

int lcs(int x, int y, string s1, string s2){

    int dp[x+1][y+1];
    
    // intially dp array has zeros (note 1st row and 1st col will always remain 0)
    for(int i=0; i<=x; i++){
        for(int j=0; j<=y; j++)
            dp[i][j] = 0;
    }

    for(int i=1; i<=x; i++){

        for(int j=1; j<=y; j++){

            if(s1[i-1]==s2[j-1]) // if chars are equal add 1 to prev ans
                dp[i][j] = 1 + dp[i-1][j-1];

            else // if chars are not equal store the max ans till now
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
        }
    
    }

    return dp[x][y];
}
int main(void){

    int A = 6, B = 6;
    string str1 = "ABCDGH", str2 = "AEDFHR";

    cout<<lcs(A, B, str1, str2);
}