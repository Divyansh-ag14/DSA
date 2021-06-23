#include<iostream>
#include<stack>
using namespace std;

class queue{

    private:
    stack<int>s;

    public:

    void push(int val){

        s.push(val);

    }

    int pop(){

        if(s.empty()){
            cout<<endl<<"Queue underflow!"; return -1;
        }

        int top= s.top();
        s.pop();

        if(s.empty()){
            return top;
        }

        int item= pop();
        s.push(top);
        
        return item;
    }

    bool empty(){

        return s.empty();
    }


};

int main(void){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.empty();
    q.pop();
}