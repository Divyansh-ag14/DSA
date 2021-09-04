#include<iostream>
using namespace std;

bool isFeasible(int arr[], int n, int m, int mid){

    int students=1, pages=0;

    for(int i=0; i<n; i++){

        if(arr[i] > mid) return 0;

        if(pages + arr[i] > mid){

            students++;
            pages=arr[i];

            if(students > m) return 0;

        }

        else pages+=arr[i];

    }

    return 1;

}

int findPages(int arr[], int n, int m){

    if(n<m) return -1;

    int s=0, ans=0;
    for(int i=0; i<n; i++)
        s+=arr[i];

    int i=0, j=s; // range of binary search

    while(i<=j){

        int mid  = (i+j)/2;

        if(isFeasible(arr, n, m, mid)){

            ans = mid;
            j=mid-1;

        }

        else i=mid+1;

    }

    return ans;

}

int main(void){

    int N = 4;   
    int A[] = {12,34,67,90};
    int M = 2;

    cout<<findPages(A, N, M);
}