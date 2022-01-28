// inversion: arr[i] > arr[j] given i < j

#include<iostream>
#define ll long long
using namespace std;

// brute force : T: O(n^2)
ll countInversionsBrute(int arr, int n){

    ll inv = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            if(arr[j] > arr[i])
                inv++;

        }
    }

    return inv;
}

// O(nlogn) using merge sort
ll merge(int arr[], int l, int m, int r){

    ll inv=0;

    int n1 = m-l+1;
    int n2 = r-m;
    int arr1[n1], arr2[n2];

    for(int i=0; i<n1; i++) arr1[i] = arr[l+i];
    for(int i=0; i<n2; i++) arr2[i] = arr[m+1+i];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){

        if(arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];

        else{
            inv+= n1-i;
            arr[k++] = arr2[j++];
        }

    }

    while(i<n1) arr[k++] = arr1[i++];
    while(j<n2) arr[k++] = arr2[j++];

    return inv;

}

ll mergeSort(int arr[], int l, int r){

    ll inv=0;

    if(l<r){

        int m = l + (r-l)/2;

        inv+= mergeSort(arr, l, m);
        inv+= mergeSort(arr, m+1, r);
        inv+= merge(arr, l, m, r);

    }

    return inv;

}

int main(void){
}