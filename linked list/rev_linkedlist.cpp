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

// there are two methods two reverse a linked list (iterative and recursive)

node *rev_iter(node *&head){ // iterative method - returns new head (pointing to the last element) of type node 

// uses 3 pointers - previous current and next
// initially prev points at null, curr points at head and next points to the 2nd node
// while curr is not null - we will change the link of current (next part of current) to prev and update the 3 pointers by 1 step
// as prev is initially null - after 1st iteration 1st element will point to null
// once curr reaches null - complete list is traversed, return prev (prev now is the last ele of original ll)
// after this ll will be reversed :)

    // 3 pointers
    node * prev = NULL;
    node * curr = head;
    node * nextptr;

    // run a loop till curr is null
    while(curr!=NULL){

        nextptr = curr->next; //node after curr

        // modiify link of curr 
        curr->next = prev;

        // now shift pointers by 1 node
        prev = curr;
        curr = nextptr; 
        // nextptr is not changed as in the beg of while loop it will be modified

    }

    // after this loop - curr is at null and prev is at last element
    return prev;

}

node *rev_rec(node *&head){ // recursive method 

// keep the first node and make recursive call on the rest of the list i.e head->next

    if(head==NULL || head->next==NULL)
        return head;

    node *newhead = rev_rec(head->next);
    head->next->next = head;
    head->next=NULL;
    return newhead;

}

void insertAtEnd(node *&head, int val){
    node *n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;

}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

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
    cout<<endl<<"reversed linked list: ";
    node *newhead = rev_rec(head); // or node *newhead = rev_iter(head);
    display(newhead);
    cout<<endl;

}