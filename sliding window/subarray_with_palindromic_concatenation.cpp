#include<iostream>
using namespace std;

bool isPalindrome(int arr[], int start, int end){

    while(start<end){

        if(arr[start++] != arr[end--]) 
            return 0;

    }

    return 1;
}

void findSubArray(int arr[], int n, int k){

    bool found = 0; 
    int i=0;

    for(i=0; i<=n-k; i++){

        if(isPalindrome(arr, i, i+k-1)){

            found=1;
            break;

        }
            
    }

    if(found){

        while(i<=i+k-1)
            
            cout<<arr[i++]<<" ";
    
    }

    else cout<<"no subarray found!"<<endl;
}

int main(void){

    int n; cin>>n; 
    
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k; cin>>k;

    findSubArray(arr, n, k);
}