#include<iostream>
using namespace std;

class node{

    public:
    int data; node *next;
    node(int val){
        data=val;
        next=NULL;
    }

};

class queue{

    private:
    node *front; node *back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    void push(int val){

        node *n= new node(val);

        // for first element
        if(front==NULL){
            front=n;
            back=n;
            return;
        }
        
        back->next=n;
        back=n;
    }

    void pop(){

        if(front==NULL){
            cout<<"Queue underlow!"<<endl;
            return;
        }

        node *todel= front;
        front=front->next;
        delete todel;

    }

    int peek(){

        if(front==NULL){
            cout<<"Queue underlow!"<<endl;
            return -1;
        }

        cout<<"Front element is: "; return front->data;        
    }

    bool empty(){

        if(front==NULL){
            return true;
        }
        return false;
    }

    void display(){

        node *temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
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