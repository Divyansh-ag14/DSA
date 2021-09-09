#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(void){

    deque<int>dq;
    vector<int>v;

    // for(int i=1; i<=5; i++)
    //     dq.push_back(i);
    
    // for(int i=6; i<=9; i++)
    //     dq.push_front(i);

    // for(auto i: dq)
    //     cout<<i<<" ";

    // dq.pop_back();
    // cout<<endl;
    // for(auto i: dq)
    //     cout<<i<<" ";

    // dq.pop_front();
    // cout<<endl;
    // for(auto i: dq)
    //     cout<<i<<" ";

    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

}