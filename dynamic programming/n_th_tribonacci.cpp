#include<iostream>
using namespace std;

int tribonacci(int n){

    int a=0, b=1, c=1;
    int ans=0;

    if(n==0) return 0;
    if(n<=2) return 1;

    for(int i=3; i<=n; i++){

        ans = a+b+c;
        a=b;
        b=c;
        c=ans;
    }

    return ans;
}

int main(void){
}