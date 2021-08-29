#include<iostream>
#include<algorithm>
using namespace std;

/*
sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, 
sort according to their position in the original array i.e., a stable sort.
*/

bool comp(int a, int b){

    return __builtin_popcount(a) > __builtin_popcount(b);
}

void sortByBitCount(int arr[], int n){

    stable_sort(arr, arr+n, comp);
}

int main(void){

    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};

    sortByBitCount(arr, 9);

    for(int i=0; i<9; i++)
        cout<<arr[i]<<" ";

    /*
    15 - 1111
    7  - 0111
    5  - 0101
    3  - 0011
    9  - 1001
    6  - 0110
    2  - 0010
    4  - 0100
    32 - 10000
    */
}