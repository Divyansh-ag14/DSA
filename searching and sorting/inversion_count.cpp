/*

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. 
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

*/

#include<iostream>
#define ll long long int
using namespace std;

int merge(ll arr[], ll l, ll m, ll r){

    ll inv = 0;
    ll n1 = m-l+1;
    ll n2 = r-m;

    ll a[n1], b[n2];

    for(int i=0; i<n1; i++) 
        a[i] = arr[l+i]; // starting point of array is l
    
    for(int i=0; i<n2; i++)
        b[i] = arr[m+i+1]; // starting point is m+1

    ll i=0, j=0, k=l;

    while(i<n1 && j<n2){

        if(a[i] <= b[j])
            arr[k++] = a[i++];

        else{

            inv+=n1-i; // if an element at ith index is bigger then all elements after it will be bigger too (array is sorted)
            arr[k++] = b[j++];
        }
    }

    while(i<n1)
        arr[k++] = a[i++];

    while(j<n2)
        arr[k++] = b[j++];

    return inv;

}

ll mergeSort(ll arr[], ll l, ll r){

    ll inv=0;

    if(l<r){

        ll m = (l+r)/2;

        inv+= mergeSort(arr, l, m);
        inv+= mergeSort(arr, m+1, r);

        inv+= merge(arr, l, m, r);
    }

    return inv;
}

ll inversionCount(ll arr[], ll n){

    return mergeSort(arr, 0, n-1);

}

int main(void){
    ll N = 5, arr[] = {2, 4, 1, 3, 5};

    cout<<inversionCount(arr, N);
}