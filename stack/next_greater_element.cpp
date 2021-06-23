#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(void){

    int n; cin>>n;
    int arr[n]; 
    for(int i=0; i<n; i++) cin>>arr[i];

    // // O(N^2)
    // int ans[n];
    // for(int i=0; i<n; i++) ans[i]=-1;
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(arr[j]>arr[i]){
    //             //ans[i]=arr[j];
    //             break;
    //         }
    //     }
    // }
    // for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    

    // O(N)
    // (we are pushing indices in stack instead of values)
    stack<int>s;
    int ans[n];
    for(int i=0; i<n; i++){

        while(!s.empty() && arr[i]> arr[s.top()]){ // is stack is not empty and current elment at top is lesser then ith element
            ans[s.top()]=arr[i]; // then assingn that index with ith index
            s.pop();
        }

        s.push(i); 

    }

    // remaining elements have no element greater then them
    while(!s.empty()){
        ans[s.top()]=-1;
        s.pop();
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" -> "<<ans[i]<<endl;
    }

}
