#include<iostream>
using namespace std;

struct node{
    int data;
    node *next, *arb;
    node(int val) { data=val; next=arb=NULL; }
};

// create n new nodes and point their arbitary according to original nodes arbitary
// then update their next pointers

node *clone(node *head){

    if(head==NULL) return head;

    node *curr = head;


    // create n new nodes (1 new (copy) node is created after every original node)
    while(curr!=NULL){

        node *temp=curr->next;
        curr->next = new node(curr->data);
        curr->next->next = temp;
        curr= temp;
    }

    curr = head;

    // for the n new nodes point their arbitary to orginal node's arbitary's next 
    // next of arbitary of curr has same value as arbitary  
    while(curr!=NULL){

        curr->next->arb = curr->arb ? curr->arb->next : NULL; // if arb does not exist - push null
        curr = curr->next->next; // (next->next - to ensure we reach original node and not copy)

    }

    curr = head->next;
    node *temp = curr;

    while(head!=NULL && curr!=NULL){

        head->next = head->next->next;
        curr->next = curr->next ? curr->next->next : NULL;

        head = head->next;
        curr = curr->next;

    }

    return temp;

}

int main(void){
}