#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val) { data=val; next=NULL; }
};

void getMid(node *head, node *&first, node *&second){

    node *slow=head, *fast=head;

    while(fast!= NULL && fast->next!=NULL){
        
        fast=fast->next->next;

        if(fast!=NULL)
            slow=slow->next;
    }

    first= head;
    second=slow->next;
    slow->next=NULL;

}

node *merge(node *first, node *second){

    if(first==NULL) return second;
    if(second==NULL) return first;

    node *ans;

    if(first->data <= second->data){
        
        ans = first;
        ans->next = merge(first->next, second);
        
    }

    else{

        ans = second;
        ans->next = merge(first, second->next);

    }

    return ans;

}

void mergeSort(node *&head){

    if(head ==NULL || head->next == NULL) return;

    node *curr = head, *first, *second;

    getMid(curr, first, second);

    mergeSort(first);
    mergeSort(second);

    head = merge(first, second);

}

void insert(node *&head, int val){

    node *n = new node(val);

        if(head == NULL){
            head = n;
            return;

        } 

    node *temp = head;
    while(temp->next != NULL){
        temp=temp->next;

    }

    temp->next = n;

}

void display(node *head){

    while(head!=NULL){

        cout<<head->data<<" -> ";
        head = head->next;

    }

    cout<<"NULL"<<endl;
}

int main(void){

    node *head=NULL;

    insert(head, 5);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 4);
    
    display(head);

    mergeSort(head);
    display(head);
}