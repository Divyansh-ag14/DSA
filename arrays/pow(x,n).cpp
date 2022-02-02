/*

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

*/

#include<iostream>
using namespace std;

double myPow(double x, int n){

    double ans = 1.00;

    if(n==0) return ans;

    long nn = n; // long: as conversion from neg to pos may cause overflow
    if(nn<0) nn=-nn;

    while(nn){

        if(nn%2){ // odd power

            ans = ans*x;
            nn=nn-1;

        }

        else{

            x = x*x;
            nn=nn/2;

        }

    }

    if(n<0) ans = double(1)/ double(ans);

    return ans;
}

int main(void){
}