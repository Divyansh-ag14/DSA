/*
    max heap: priority_queue<int, vector<int>>
    min heap: priority_queue<int, vector<int>, greater<int>>

    push: O(logn)
    pop: O(logn)
    top: O(1)
    size: O(1)
*/

#include<iostream>
#include<queue>
using namespace std;

int main(void){

    // max heap
    cout<<"max"<<endl;
    priority_queue<int, vector<int>>pq;
    pq.push(2); pq.push(1); pq.push(3); 
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    // min heap
    cout<<"min"<<endl;
    priority_queue<int, vector<int>, greater<int>>pqm;
    pqm.push(2); pqm.push(1); pqm.push(3); 
    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;

}

