// signle linked list having (next) of last node pointing to the head

#include<iostream>
using namespace std;

class node{ // same as single linked list
    public: 
    int data; node *next;
    node(int val) { data=val; next=NULL; }
};

void insertAtHead(node *&head, int val){

//(update the next of last node)
    node *n = new node(val);

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }

    node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n; // update last node to point to new node
    n->next=head; // new node points to head
    head=n;       // update head

}

void insertAtEnd(node *&head, int val){

    node *n = new node(val);

    if(head==NULL){
        n->next=n;
        head=n;
    // or use insertAtHead(head, val)
        return;
    }

    node *temp=head; // to travere the list
    //last node - (next=head)
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void display(node *head){
// do while loop 
    node *temp=head;

// while(temp->next!=head) - if we use this, we wont be able to print the last node
// while(temp!=head) - if we use this, we wont be able to traverse the list at all 

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);    

}

void delAtHead(node *&head){
// to del the starting element - store it in a ptr - change the next of last node to head->next - update head - del this ptr

    node *todel=head;
    node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete todel;

}
void del(node *&head, int pos){

    if(head==NULL){
        cout<<"list is empty";
        return;
    }

    if(pos==1){
        delAtHead(head);
        return;
    }

    node *temp=head;
    // go to the n-1th node
    int count =1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }

    node *deln = temp->next;

    // change the link of this (n-1th node)
    temp->next = temp->next->next;    
    delete deln;
}

int main(void){

    node * head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,6);
    insertAtEnd(head,7);
    cout<<endl;
    display(head);
    insertAtHead(head,5);
    cout<<endl;
    display(head);

    del(head, 1); // head
    cout<<endl;
    display(head);

    del(head,6); // tail
    cout<<endl;
    display(head);

    del(head,2); // in between
    cout<<endl;
    display(head);
}