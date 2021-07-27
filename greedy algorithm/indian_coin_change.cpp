// given an amount x - find the min no of coins required to get a value of x

#include<iostream>
#include<algorithm>
using namespace std;

int main(void){

    int n; cin>>n;

    int arr[n]; 
    for(int i=0; i<n; i++) cin>>arr[i];

    int x; cin>>x;

    sort(arr, arr+n, greater<int>()); // sort in decreasing order

    int s=0;

    for(int i=0; i<n; i++){

        s+= x/arr[i]; // no of particular domination that can be taken (no)
        x-= x/arr[i] * arr[i]; // original val becomes val - total value of current domination (no * arr[i])

    }

    cout<<s;

}