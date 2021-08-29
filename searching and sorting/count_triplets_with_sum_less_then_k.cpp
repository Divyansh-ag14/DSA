#include<iostream>
#include<algorithm>
using namespace std;

// T: O(n^2)   S: O(1)
long long countTriplets(long long arr[], int n, long long sum){
	    
	sort(arr, arr+n);
	    
	long long ans = 0;
	    
	for(int i=0; i<n-2; i++){
	        
	    int j = i+1; // elemnt next to i
	    int k = n-1; // last element
	    
	    while(j<k){
	        
	        if(arr[i] + arr[j] + arr[k] < sum){ // if sum less then given sum
	            ans += k-j; // increment ans by k-j (as k is the greatest element, if its sum is less then given then all others will also satisfy the condition )
	            j++;
	        }
	        
	        else k--; // if sum is bigger then decrement k
	            
	    }
	        
	}
	    
    return ans;
}

int main(void){
}