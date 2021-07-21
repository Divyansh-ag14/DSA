#include<iostream>
#include<unordered_map>
using namespace std;

int main(void){

    int n; cin>>n; 
    int arr[n];
    unordered_map<int, int>map;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
        map[arr[i]]++;
    }

    cout<<"Element  Frequency"<<endl;
    for(auto i= map.begin(); i!=map.end(); i++)  
        cout<<i->first<<"        "<<i->second<<endl;

}