#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){ // after every pass: the greatest element in unsorted array is placed at its right index

            if(arr[j] > arr[j+1]){

                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(void){

    int arr[]= {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
}