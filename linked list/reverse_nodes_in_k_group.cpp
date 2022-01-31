/*

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

*/

#include<iostream>
using namespace std;

struct node{
    int data; node *next;
    node(int val){ data=val; next=NULL; }
};

void insert(node *&head, int val){
    node *n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }

    node *temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"END"<<endl;
}

int findLen(node *head){

    if(head==NULL) return 0;

    int len=1;

    while(head->next!=NULL){
        len++;
        head=head->next;
    }

    return len;
}

node *reverseKGroup(node *head, int k){

    int len = findLen(head);

    node *dummy = new node(-1);
    dummy->next=head;

    node *prev=dummy, *curr=dummy, *nxt=dummy;

    while(len>=k){

        curr = prev->next;
        nxt = curr->next;

        for(int i=1; i<k; i++){

            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;

        }

        prev=curr;
        len-=k;

    }

    return dummy->next;

}

int main(void){

    node *head=NULL;
    for(int i=1; i<=8; i++) insert(head, i);

    display(head);
    head= reverseKGroup(head, 3);
    display(head);
    
}