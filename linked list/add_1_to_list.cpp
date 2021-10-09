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

node *addOne(node *head){

    if(head==NULL) return head;

    head= rev(head);

    node *curr= head;

    while(curr!=NULL){

        if(curr->next==NULL && curr->data==9){ // last digit is 9 - make it 1 and (insert 0 at last)
            
            curr->data=1;
            node *temp= new node(0);
            temp->next= head;
            head=temp;
        }

        else if(curr->data==9){ // some digit in bw is 9 - make it 0

            curr->data=0;
        }

        else{
            curr->data+=1; // if digit is less then 9 simply add 1
            break; 
        }

        curr=curr->next;
    }

    head= rev(head);
    return head;

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

    node *head=NULL;
    insert(head, 1);
    insert(head, 9);
    insert(head, 9);
    display(head);
    head=addOne(head);
    display(head);

}