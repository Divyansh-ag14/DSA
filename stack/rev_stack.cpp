#include<iostream>
#include<stack>
using namespace std;

void insertAtLast(stack<int> s, int element){

    if(s.empty()){
        s.push(element);
        return;
    }
    int topelement= s.top();
    s.pop();

    insertAtLast(s, element);
    s.push(topelement);

}

void rev_stack(stack<int> s){

    if(s.empty()) return;

    int element= s.top();
    s.pop();

    rev_stack(s);
    insertAtLast(s, element);

}

int main(void){

    stack<int> s;
    int n; cin>>n;
    for(int i=0; i<n; i++){ int x; cin>>x;
     s.push(x);}

    rev_stack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }



    

}