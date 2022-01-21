#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){

    int n1= m-l+1;
    int n2 = r-m;
    int k=l;

    int arr1[n1], arr2[n2];
    
    for(int i=0; i<n1; i++) arr1[i]=arr[l+i];
    for(int i=0; i<n2; i++) arr2[i]=arr[m+1+i];

    int i=0,j=0;

    while(i<n1 && j<n2){

        if(arr1[i] <= arr2[j])
            arr[k++]=arr1[i++];

        else arr[k++]=arr2[j++];

    }

    while(i<n1)
        arr[k++]=arr1[i++];

    while(j<n2)
        arr[k++]=arr2[j++];

}

void mergeSort(int arr[], int l, int r){

    if(l>=r) return; // if there is no or 1 element: return 

        int m = l + (r-l)/2; // get the middle element: l+(r-l)/2 == (2l+r-l)/2 == (l+r)/2

        mergeSort(arr, l, m); // left recursion
        mergeSort(arr, m+1, r); // right recursion

        merge(arr, l, m, r); // merge both the parts

    


}

int main(void){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

}