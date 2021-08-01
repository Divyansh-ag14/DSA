#include<iostream>
using namespace std;

int main(void){
 
    // 1st approach O(n)

    // xor returns 1 only if both bits are diff
    // for every number except the unique number xorsum will be equal to 0 and at last will only contain the unique number
    // 0000 ^ unique_number = unique_number

    int n=9;
    int arr[n] = {1,1,2,3,3,4,4,5,5};
    int xorsum = 0;
    for(int i=0; i<n; i++){
        xorsum = xorsum^arr[i];
    }
    cout<<"Unique element: "<<xorsum<<endl;


    // 2nd approach O(logn)

    // int the abve array 2 is the ans - divide the array into 2 half at this point
    // notice - (in left half first occurance is at even index and in right half first occurance is at odd index)
    // 1 1 2 3 3 4 4 5 5
    // 0 1 2 3 4 5 6 7 8
    // | |   | |
   //  e o   o e

   // high is set to n-2 (2nd last element)
   // the idea is to shrink the left half - once low crosses high low will be the ans

    int low=0, high=n-2;

    while(low<=high){

        int m= (low+high)/2;

        // check if m is in left half (first occurance at even index)
        if(arr[m] == arr[m^1]) // ^ gives next odd value for even number and prev even value for odd number so we check the order (o e)
            low=m+1;          // so now we do not have to right seperate conditions for checking left and right half

        else high=m-1;

   }

   cout<<"Unique element: "<<xorsum<<endl;
}

