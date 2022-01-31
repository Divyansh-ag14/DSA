#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val) { data=val; next=NULL; }
};

bool isPalindrome(node *head){

    // get the middle element
    // for even length: get the first middle element

    node* slow=head, *fast=head;

    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    slow=slow->next; // get the next element after the mid point
    // reverse the list from here 
    node *prev=NULL, *curr=slow, *nxt=NULL;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }

    while(prev!=NULL){

        if(prev->data != head->data)
            return 0;

        prev=prev->next;
        head=head->next;

    }

    return 1;
}

int main(void){
}