#include<iostream>
using namespace std;

// brute  T: O(n)  S: O(n)
int *findTwoElements(int arr[], int n){

    int missing=-1, repeating=-1;

    int mx=arr[0];
    for(int i=1; i<n; i++)
        mx = max(mx, arr[i]);

    int freq_arr[mx+1];

    for(int i=0; i<mx+1; i++)
        freq_arr[i]=0;

    for(int i=0; i<n; i++)
        freq_arr[arr[i]]++;

    for(int i=1; i<=mx; i++){

        if(freq_arr[i] > 1)
            repeating=i;

        if(freq_arr[i]==0)
            missing=i;

    }

    int *ans = new int[2]{repeating, missing}; 

    return ans;

}

// better T: O(n)  S: O(1)
int *findTwoElements2(int arr[], int n){

    int repeating, missing;

    // go to every element and using its value as index: mark the elements negative
    for(int i=0; i<n ; i++){

        if(arr[abs(arr[i])-1] < 0) // if we reach a negative element again: store the repeating number
            repeating = abs(arr[i]);

        else arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];

    }

    // if some value in array is non negative then return its index
    for(int i=0; i<n; i++){

        if(arr[i] > 0){
            missing=i+1;
            break;
        }

    }

    int *ans = new int[2]{repeating, missing}; 

    return ans;

}


int main(void){

    int arr[]= {4,3,6,2,1,1};
    int *ans = findTwoElements2(arr, 6);

    cout<<ans[0]<<endl<<ans[1];

}