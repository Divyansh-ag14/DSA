#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val) { data=val; next=NULL; }
};

node *rev(node *head){

    if(head==NULL || head->next==NULL)
        return head;

    node *ans= rev(head->next);
    head->next->next=head;
    head->next=NULL;

    return ans;
}

node *add(node *head1, node *head2){

    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    head1= rev(head1);
    head2= rev(head2);

    int s=0, c=0;
    node *res=NULL, *temp=NULL, *curr=NULL;

    while(head1 || head2){

        // sum = carry + (data of head1 else 0) + (data of head2 else 0)
        s= c + (head1? head1->data : 0) + (head2? head2->data : 0);

        if(s>9) c=1;
        else c=0;

        s=s%10; // to get the last digit

        temp = new node(s); // new node temp to store digit node

        if(res==NULL) res=temp; // if this is the first node
        else curr->next=temp; // else append it to the next of current node

        curr=temp; // update current node

        if(head1) head1=head1->next; // if any of the heads become null then we cant go to their next 
        if(head2) head2=head2->next; // so check if they are valid values before updating them

    }

    if(c){ // after while loop if carry is still present - means ans list has one extra node

        temp= new node(c); // store carry in temp node
        curr->next=temp; // append it to the next of current node
    }
    
    res= rev(res);
    return res;

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
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(void){

    node *head1=NULL,*head2=NULL,*head3=NULL;

    insert(head1, 4); insert(head1, 4); insert(head1, 9);
    insert(head2, 3); insert(head2, 4); insert(head2, 9);

    head3=add(head1, head2);

    display(head3);

}