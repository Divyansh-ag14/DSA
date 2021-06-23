#include<iostream>
#include<queue>
using namespace std;

class stack{

    private:
    int N;
    queue<int> q1, q2;

    public:

    stack(){
        N=0;
    }

    void push(int val){
        q1.push(val);
        N++;
    }

    void pop(){

        if(q1.empty()){
            cout<<"Stack underflow!"<<endl;
            return;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        // now length of q1 is 1
        // pop the required element and decrease the size by 1
        q1.pop();
        N--;
        // note size is only decreased by 1 as all other element will be pushed back in q1 except the last element

        queue<int>temp=q1;
        q1=q2;
        q2=temp;
    }

    int top(){

        if(q1.empty()){
            cout<<"Stack is empty!"<<endl;
             return -1;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int top= q1.front();

        // push this value in q2 as we are not removing any element just checking the top
        q2.push(top);

        queue<int>temp=q1;
        q1=q2;
        q2=temp;

        return top;
    }

    int size(){
        return N;
    }

};