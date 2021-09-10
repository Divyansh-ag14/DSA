#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int wordBreakUtil(string A, vector<string> &B, unordered_map<string, int> &dp){

    int str_length=A.length();

    if(str_length==0) return 1; // if len is 0: return 1 (no more searching required)

    if(dp[A] != 0) return dp[A]; // if map has some ans return it

    for(int i=1; i<=str_length; i++){ // for a given str generate substrings

        bool flag = 0; 
        string sub_str = A.substr(0, i);

        for(int j=0; j<=B.size(); j++){ // check for the sub string in vector

            if(sub_str.compare(B[j])==0){ // if it is found

                flag =1; // change flag and break
                break;
            }

        }

        // if substring is found then check for the rest of the string i (string - subtring)
        // ex: for abcd if ab is found check for cd
        if(flag==1 && wordBreakUtil(A.substr(i, str_length), B, dp) == 1) 
            return dp[A]=1; // if it is found return 1
        
    }

    // else return -1
    return dp[A] = -1;

}

int wordBreak(string A, vector<string> &B){

    // dp map to store string and its occurence in vector
    // by deafult int in map is 0
    unordered_map<string, int> dp;

    int ans = wordBreakUtil(A, B, dp);

    if(ans==1) return 1;
    return 0;

}
int main(void){

    int n = 12;
    vector<string> B = { "i", "like", "sam", "sung", "samsung", "mobile", "ice","cream", "icecream", "man", "go", "mango" };
    string A = "ilike";

    cout<<wordBreak(A, B);
}