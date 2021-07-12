#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val) { data=val; next=NULL; }
};

void swapFirstAndLast(node *head){

    if(head==NULL || head->next==NULL) return;

    node *temp=head;
    node *first=head;
    node *last;

    while(temp->next!=NULL)
        temp=temp->next;

    last= temp;

    swap(last->data, first->data);
}

void insert(node *&head, int val){

    node *n= new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

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

    node *head= NULL;
    for(int i=1; i<=5; i++)
        insert(head, i);

    display(head);
    swapFirstAndLast(head);
    display(head);

}