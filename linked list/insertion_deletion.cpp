#include<iostream>
using namespace std;

class node{

// node is a user defined data type made out of int and pointer (int part stores the data and pointer stores the add of next node)
// head points to the first node of ll
// last node of ll has null in its (next) pointer part

    public: 
        
        int data; node *next; 
        
        node(int val){
            data = val;
            next = NULL;
        }
};

void insertionAtEnd(node *&head, int val){ // by ref as we are modifying ll

// using head traverse the ll and reach the last node
// at the last node set next as the add of the new node and set next of this new node as null

    // create new node to insert
    node *n = new node(val);

    // check if ll is empty 
    if(head==NULL){
        head=n;
        return;
    }

    // create temp pointer to iterate through ll
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    // after this loop temp is at the end of ll now inset the new node n
    temp->next = n; 
    // note n->next is already null as it is defined in the constructor
}

void insertAtStart(node *&head, int val){

    node *n = new node(val);

    // check if ll is empty 
    if(head==NULL){
        head=n;
        return;
    }

    // to insert at starting, store head in n->next and update head to point to n 
    n->next=head;
    head=n;

}

void display(node *head){ // call by val as we do not have to make any modifications

    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

} 

bool search(node *head, int val){

    node *temp = head;
    while(temp!=NULL){
        if(temp->data==val)
            return true;
        temp = temp->next;
    }
    return false;

}

void delHEad(node *&head){

    // to delete starting element just modify head to point to the second node
    // store head in a pointer to delete it (to avoid memory leak)

    node *deln = head;
    head = head->next;
    delete deln;

}

void del(node *&head, int val){

// to delete a node n -> change the link bw n-1 and nth node
// n-1 th node should point to n+1 th node instead of nth node (next part of n-1 should contain add of n+1)

    // check if val is present
    if(!search(head, val)){
        cout<<val<<" is not present in the linked list";
        return;
    }

    // check if length of linked list is 1
    if(head->next==NULL)
        delHEad(head);

    node *temp = head;
    // go to the n-1 th node
    while (temp->next->data !=val){ // ex. 1 2 3 - del 3
        temp=temp->next;           // iter 1 temp->next->data = 2, temp gets updated for iter 2 this val is eaual to 3 
                                  // so we stop here
    }

    // store the nth node in a pointer to delete it before removing its link (to avoid dangling pointer)
    node *deln = temp->next;

    // change the link of this (n-1th node)
    temp->next = temp->next->next;    

    delete deln;

}

int main(void){

    node *head = NULL;
    insertionAtEnd(head, 1);
    insertionAtEnd(head, 2);
    insertionAtEnd(head, 3);
    display(head);
    insertAtStart(head, 0);
    cout<<endl;
    display(head);
    cout<<endl<<search(head, 5);
    cout<<endl;
    del(head, 3);
    display(head);
    cout<<endl;
    delHEad(head);
    display(head);

}