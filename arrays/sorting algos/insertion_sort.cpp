/*
    The array is virtually split into a sorted and an unsorted part. 
    Values from the unsorted part are picked and placed at the correct position in the sorted part.

    algo:
    1: Iterate from arr[1] to arr[n] over the array. 
    2: Compare the current element (key) to its predecessor. 
    3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
*/

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){

    int i, key, j;

    for(i=1; i<n; i++){

        j=i-1;
        key=arr[i];

        while(j>=0 && arr[j] > key){

            arr[j+1] = arr[j];
            j=j-1;
        }

        arr[j+1]=key;
    }

}

int main(void){
}