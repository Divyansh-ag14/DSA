#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val) { data=val; next=NULL; }
};

int getMiddle(node *head){

    if(head == NULL || head->next == NULL)
        return head->data;
    
    node *temp = head;
    int c = 1;

    while(temp->next != NULL){
        temp = temp->next;
        c++;
    }

    c = (c/2) + 1;

    while(--c)
        head = head->next;

    return head->data;

}

int getMid(node *head){

    if(head->next==NULL)
        return head->data;

    node *slow=head, *fast=head;

    while(fast!=NULL && fast->next!=NULL){

        fast=fast->next->next;
        slow=slow->next;
    }

    return slow->data;
}

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
    cout<<"NULL"<<endl;
}

int main(void){

    node *head=NULL;
    for(int i=1; i<=6; i++)
        insert(head, i);

    display(head);
    cout<<getMiddle(head)<<endl;
    cout<<getMid(head);
}