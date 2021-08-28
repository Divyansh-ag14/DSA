#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// T: O(n)   S: O(n)
bool pair(int arr[], int n, int x){

    unordered_map<int,int>m;
    
    for(int i=0; i<n; i++)
        m[arr[i]]=1;
        
    for(int i=0; i<n; i++){
        
        if(m[arr[i] + x])
            return 1;
    }
    
    return 0;

}

// T: O(nlogn)   S: O(1) 
bool pair2(int arr[], int n, int x){

    sort(arr, arr+n);

    int a=0, b=n-1;

    for(int i=0; i<n; i++){

        int idx = upper_bound(arr+i+1, arr+n, x+arr[i]) - arr - 1;

        if(arr[idx] - arr[i] == x) return 1;
    }

    return 0;
}

int main(void){
}