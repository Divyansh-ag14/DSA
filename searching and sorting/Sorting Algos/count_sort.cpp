/*

1. find the count of every distinct element in the array
(for this create a count array of size max element + 1 present in array and store the count of each element in it)
(max index of count array = max element of array)

2. calculate the position of each element in the sorted array
(for this modify the count array by adding the number of occurences of prev element to next element) - count_arr[i] += count_arr[i-1]

3. now travesre the array from last and check the pos in position array
(place this element in a new array at pos = position - 1)
(decrement 1 from position i.e modified count array for that element)

ex - arr = 1 3 2 3 4 1 6 4 3 (size = 9)
    
    count_arr = 0 2 1 3 2 0 1 (size = 7)
   (index)      0 1 2 3 4 5 6 
    
    position = 0 2 3 6 8 0 9  (modified count_arr)
    (index)  = 0 1 2 3 4 5 6    

    ans  =   [                ] // initally empty
    (index) = 0 1 2 3 4 5 6 7 8 

    now traverse arr from right hand side
    first element is 3 - check position at index 3 - place 3 at pos-1 i.e at index 5 in ans and decrement val of position by 1 
    move to the next element of arr
    repeat till ans is completely filled

*/

#include<iostream>
using namespace std;

void countSort(int arr[], int n){

    // find max ele
    int mx = arr[0];
    for(int i=0; i<n; i++){
        mx = max(mx, arr[i]);
    }
    int size = mx+1;
    int count_arr[size]={0};

    // store count 
    for(int i=0; i<n; i++){
        count_arr[arr[i]]++;
    }

    // modify count_arr
    for(int i=1; i<=size; i++){
        count_arr[i] += count_arr[i-1];
    }

    // ans array
    int ans[n];
    for(int i = n-1; i>=0; i--){
        ans[--count_arr[arr[i]]] = arr[i]; // pre decrement position for element in arr at index i before storing it in ans
    }

    // finally update the orginal array
    for(int i=0; i<n; i++){
        arr[i] = ans[i];
    }

}

int main(void){
    int n;
    cout<<"Enter array size: "; cin>>n;
    int arr[n];
    cout<<"Enter elements in the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"original array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    countSort(arr, n);
    cout<<endl<<"sorted array  : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
