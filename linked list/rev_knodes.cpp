#include<iostream>
using namespace std;

class node{

    public:
    int data; node *next;
    node(int val){
        data = val;
        next = NULL;
    }

};

node * rev_k(node *&head, int k){

// update the first k nodes by iteration method and then call recusrion on the remaining linked list

    node *prev = NULL;
    node *curr = head;
    node *nextptr;

    int count=0; // to keep track of k nodes
    while(curr!=NULL && count<k){
        nextptr = curr->next;
        curr->next=prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = rev_k(nextptr, k);
    }
    return prev;

}

// node *rev_k1(node *&head, int k){

//     node *prev = NULL, *curr=head, *nextptr;
    
//     while(curr!=NULL && k--){
//         nextptr = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nextptr;
//     }

//     if(nextptr!=NULL){
//         head->next = rev_k(nextptr, k);
//     }

//     return prev;

// }

void insertAtEnd(node *&head, int val){
    
    node *n = new node(val);
     if(head==NULL){
        head=n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;

}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;;

}

int main(void){

    node * head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    cout<<"original linked list: ";
    display(head);
    node *newhead  = rev_k(head,3);
    cout<<"reversed linked list: ";
    display(newhead);

}