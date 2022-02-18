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