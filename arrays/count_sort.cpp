

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
