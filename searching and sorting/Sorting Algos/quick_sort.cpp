#include<iostream>
using namespace std;

// this functions partitions the array such that the pivot element is placed at its right position
// elements less then pivot are placed before it and elements greater then it are placed after it
int partition(int arr[], int l, int r){

    int pivot = arr[l]; // starting element is pivot
    int less_than_pv=0;

    for(int i=l+1; i<=r; i++){

        if(arr[i] < pivot)
            less_than_pv++;

    }

    // place pivot element at its correct location
    int pivot_index = l + less_than_pv;
    swap(arr[pivot_index], arr[l]);

    // now place elements less than pivot before it and elements greater then it after it
    int i=l, j=r;
    while(i < pivot_index && j > pivot_index){
        
        while(arr[i] < pivot) i++; // if elements satisfy the condition: keep on iterating
        while(arr[j] > pivot) j--;

        if(i < pivot_index && j > pivot_index)
            swap(arr[i++], arr[j--]);

    }

    return pivot_index;

}

void quickSort(int arr[], int l, int r){

    if(l>=r) return; // if there is one or no element: return

    int pivot = partition(arr, l, r); // places pivot element at its correct location and returns its index
    
    quickSort(arr, l, pivot-1); // left recursion for all elements less then pivot
    quickSort(arr, pivot+1, r); // right recusion for all elements greater then pivot

}

int main(void){

    int n; cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" "; 
}