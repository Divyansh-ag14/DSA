#include<iostream>
using namespace std;

#define n 100

class queue{
    
    private:
    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr= new int[n];
        front= -1;
        back= -1;
    }

    void push(int val){

        // check for overflow
        if(back==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }

        back++; // increment from -1 for the first time
        arr[back]= val;

        if(front==-1) // when the first element is inserted it is important to set front to 0
            front++;

    }

    void pop(){

        //check for underflow- (back==1 || front > back)
        if(back==1 || back<front){ //(front==-1 || front>back)
            cout<<"Queue underlow"<<endl;
            return;
        }

        front++;

    }

    int peek(){ // to see the first/front element of queue

        // check if queue is empty
        if(back==-1 || back<front){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        cout<<"Front element is: "; return arr[front];
    }

    bool empty(){

        if(back==-1 || back<front){
            cout<<"Queue is empty"<<endl;
            return true;
        }

        return false;

    }

    void display(){

        for(int i=front; i<=back; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    } 

};

int main(void){

    queue q;
    for(int i=1; i<=7; i++)
        q.push(i);
    q.display();
    cout<<q.peek()<<endl;
    q.pop();
    q.display();
    cout<<q.empty();
}