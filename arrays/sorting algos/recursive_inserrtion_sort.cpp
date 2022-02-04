#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){

    // base condition
    if(n<=1) return;

    insertionSort(arr, n-1);

    int key= arr[n-1];
    int j= n-2;

    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1]=key;
}


int main(void){

    int arr[]= {5, 4, 3, 2, 1};
    insertionSort(arr, 5);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
}