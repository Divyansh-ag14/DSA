#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    // base condition
    if(n==1) return;

    for(int i=0; i<n; i++){
        if(arr[i] > arr[i+1]){
            int temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
    }
    bubbleSort(arr, n-1);
}

int main(void){

    int arr[]= {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
}