// peak element: greater then its left and right neighbour

#include<iostream>
using namespace std;

int findPeak(int arr[], int n, int l, int r){

    int m = (l+r)/2;

    // check if m is the peak element (also check if m is the first or last element)
    if((m==0 || arr[m-1] <= arr[m]) && (m==n-1 || arr[m+1] <= arr[m]))
        return m; 

    // if left element is greater then m - check in left half
    else if(m>0 && arr[m-1]>arr[m]) 
        return findPeak(arr, n, l, m-1);

    // else right element is greater then m -  check in right half
    else return findPeak(arr, n, m+1, r);
}

int main(void){

    int arr[7] = {1,2,3,4,5,6,7};

    int idx= findPeak(arr, 7, 0, 6);

    cout<<"index: "<<idx<<endl<<"element: "<<arr[idx];
}