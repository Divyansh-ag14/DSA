#include<iostream>
using namespace std;

class node{
    public:
    int data; node *next;
    node(int val){ data=val, next=NULL; }
};

// create two pointers odd and even (odd=head, even=head->next)
// create another pointer to mark the start of even nodes (this will be used to join nodes after updated links)
void oddEven(node *&head){

    node *odd=head;
    node *even=head->next;
    node *even_start=even;
    
    // if length is even then even->next will be null else odd->next will be null (for last node)
    while(odd->next!=NULL && even->next!=NULL && odd!=NULL && even!=NULL){

        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;

    }

    odd->next = even_start;

}


void insert(node *&head, int val){

    node *n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(void){

    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    display(head);
    cout<<endl;
    oddEven(head);
    display(head);


}