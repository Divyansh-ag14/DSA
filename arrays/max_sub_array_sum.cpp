#include<iostream>
using namespace std;

// T: O(n^3)
int findSum(int arr[], int n){

    int ans=INT8_MIN;

    for(int i=0; i<n; i++){      // sub array is from i to j: that takes 2 loops
        for(int j=i; j<n; j++){  // use another loop to calculate sum from i to j
            int s=0;
            for(int k=i; k<=j; k++){
                s+=arr[k];
            }
            ans=max(ans, s);
        }
    }

    return ans;
}


// T: O(n^2)
int findSum2(int arr[], int n){

    int ans=INT8_MIN;

    for(int i=0; i<n; i++){
        int s=0;
        for(int j=i; j<n; j++){
            s+=arr[j];
            ans=max(ans, s);
        }
    }

    return ans;

}

// T: O(n)
int findSum3(int arr[], int n){ // kadane

    int ans=arr[0];
    int curr_sum=arr[0];

    for(int i=1; i<n; i++){

        curr_sum = max(curr_sum+arr[i], arr[i]);
        ans = max(ans, curr_sum);
    
    }

    return ans;
}

int main(void){

    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = 8;

    cout<<findSum(arr,n)<<endl<<findSum2(arr,n)<<endl<<findSum3(arr,n);
}