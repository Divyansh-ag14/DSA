/*
A step array is an array of integers where each element has a difference of at most k with its neighbor. 
Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.
*/

#include<iostream>
using namespace std;

// T: O(n)   S: O(1)
int search(int arr[], int n, int k, int x){

    int ans = -1;

    int i=0;

    while(i<n){

        if(arr[i]==x){ // if the element if found return the index
            ans=i;
            break;
        }


        // else: find the no of min jumps required to find the element
        // use max as at least one jump is required (when division becomes 0)
        i = i + max(1, abs(arr[i]-x)/k); 

    }

    return ans;

}

int main(void){

    int arr[6] = {2,4,5,7,7,6};

    cout<<search(arr, 6, 2, 7);

}