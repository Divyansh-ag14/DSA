// method 1 - costly push
// create 2 qs - push element in q2, then push elements of(q1 in q2 if any) lastly swap q1 and q2
// as queue pops the first element and stack pops the last 
// it is imp to reverse the order in which elements are placed inside queue
// so when q pops the first element, it is technically the last 

#include<iostream>
#include<queue>
using namespace std;

class stack{

    private:
    int N;
    queue<int>q1; queue<int>q2;

    public:
    stack(){
        N=0;
    }

    void push(int val){

        q2.push(val);
        N++;

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp=q1;
        q1=q2;
        q2=temp;

    }

    void pop(){
        if(N==0){
            cout<<"Stack underflow!"<<endl;
            return;
        }
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }

};


int main(void){

    stack s;
    for(int i=1; i<=5; i++) s.push(i);
    cout<<s.top();
    s.pop();
    cout<<s.top();
}