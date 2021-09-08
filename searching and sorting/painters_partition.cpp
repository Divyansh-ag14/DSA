#include<iostream>
using namespace std;

bool isFeasible(int arr[], long long m, int n, int k){

    int painters=1; // initially a single painter is assigned
    long long time =0; // curr time is 0

    for(int i=0; i<n; i++){ // for all elements

        if(arr[i] > m) return 0; // if an element is > then allowed time: return 0 (m is not feasible/valid)

        if(time + arr[i] > m){ // if curr time + array element is > m 

            painters++; // increase the number of painters
            time = arr[i]; // update time

            if(painters > k) return 0; // if painters become greater then k: return 0

        }

        else time +=arr[i]; // else if a painter can paint for more time: inc curr time

    }

    return 1; // if the for loop executes successfully: return 1 (ans is feasible)

}


long long minTime(int arr[], int n, int k){

    long long i=0, j=0, ans=0;

    for(int i=0; i<n; i++)
        j+=arr[i];

    while(i<=j){ // range of binary search 0 to- sum of array (as the max time will be the sum of all elements)

        long long m = (i+j)/2;

        if(isFeasible(arr, m, n, k)){ // if m is feasible

            ans = m; // update ans
            j = m-1; // try to minimize it

        }

        else i = m+1; // if m is not feasible: inc. the lower bound

    }

    return ans;

}

int main(void){

    int  n = 5, k = 3 ,arr[] = {5,10,30,20,15};
    cout<<minTime(arr, n, k);

}