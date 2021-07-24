/* 
    given a sorted array rotated at some pivot element -  serach in O(logn) 

    ex: [30, 40, 50, 10, 20]
    
    find the pivot element: (it is the only element greater then its right element)

    for a given key: 1st search the left half (0 to m), then (if required) search the right half (m+1 to n-1)

*/
#include<iostream>
using namespace std;

int search(int arr[], int key, int l, int r){

    if(l > r) return -1;

    int m = (l+r)/2;
    
    if(arr[m] == key) return m;

    if(arr[l] <= arr[m]){ // first half is sorted

        if(key>=arr[l] && key<=arr[m]) 
            return search(arr, key, l, m-1);

        else return search(arr, key, m+1, r);
    }

    else if(key>=arr[m] && key<=arr[r]) // second half is sorted
        return search(arr, key, m+1, r);

    else return search(arr, key, l, m-1);

}

int main(void){

    int arr[8] = {6, 7, 8, 9, 10, 1, 2, 5};

    cout<<search(arr, 8, 0, 7); // key is 8
}
