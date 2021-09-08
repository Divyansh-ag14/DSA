#include<iostream>
using namespace std;

// number of zeros can be calculated using the formula =: x/5 + x/25 + .... (x is the number we caluclate facotrial of)

bool isFeasible(int m, int n){

    int count=0, f=5;

    while(f<=m){

        count += m/f; // inc count by the number of 5s present after divsion by (current f)
        f*=5; // update f

    }

    return count>=n; // if count >=n return 1 else return 0

}

int findNum(int n){

    int low = 0, high = 5*n, ans=0;

    while(low<=high){

        int m = (low+high)/2;

        if(isFeasible(m,n)){

            ans = m;
            high = m-1;

        }

        else low=m+1;

    }

    return ans;

}

int main(void){
}