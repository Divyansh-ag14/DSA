#include<iostream>
#include<math.h>
using namespace std;

bool isPalindrome(int n){

    int temp=n, num=0;

    while(temp){

        num = num*10 + temp%10;
        temp=temp/10;
    }

    if(num==n) return 1;

    return 0;
}

void findSubArray(int arr[], int n, int k){

    int num=0, i=0, j=0;
    bool found =0;

    while(j<k) // 1st window
        num = num*10 + arr[j++];

    if(isPalindrome(num))
        found=1;

    while(j<n){

        if(found) break;

        num = (num % (int) pow(10, k-1)); // remove the 1st digit
        num = num*10 + arr[j++]; // add new digit at end
        i++;

        if(isPalindrome(num)) 
            found=1;

    }

    if(!found) cout<<"no subarray found!"<<endl;

    else{ 
        while(i<=j-1)
            cout<<arr[i++]<<" ";
    }
}

int main(void){

    int n; cin>>n; 
    
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k; cin>>k;

    findSubArray(arr, n, k);
}