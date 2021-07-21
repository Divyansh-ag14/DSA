#include<iostream>
#include<unordered_map>
using namespace std;

int main(void){

    int n; cin>>n; int arr[n];  //c=0;
    for(int i=0; i<n; i++) cin>>arr[i];

    // brtue force -   T: O(n^2)   S: O(1)
    // for(int i=0; i<n; i++){
    //     int s=0;
    //     for(int j=i; i<n; j++){
    //         s+=arr[j];
    //         if(s==0)
    //             c++;
    //     }
    // }


    // map  T: (n)   S: O(n)
    unordered_map<int, int>map;
    int prefixsum=0;

    for(int i=0; i<n; i++){

        prefixsum += arr[i];
        map[prefixsum]++;
    }

    unordered_map<int, int> :: iterator it; int ans=0;

    for(it=map.begin(); it!=map.end(); it++){

        int c= it->second;

        ans+= (c*(c-1)/2); // for every key, choose 2 vals from all the occurences of particular prefixsum (nc2)
                           // nc2 = n(n-1)/2
                           
        // if prefixsum is itself 0
        if(it->first==0)
            ans+=it->second;
    }

    cout<<ans;
}