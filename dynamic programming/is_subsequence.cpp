/*

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true


Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*/

#include<iostream>
#include<string.h>
using namespace std;

bool isSubsequence(string s, string t){

    int m=s.size(), n=t.size();
    int i=0,j=0;

    while(i<n && j<m){

        if(s[i]==t[j]) i++;
        j++;
    }

    // i only reaches the end if we are able to traverse the entire string s
    // due to the if statement: it means that all the chars in s are present in string t
    return i==n;
}


int main(void){
}
