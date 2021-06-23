#include<iostream>
using namespace std;

class node{
    public:
    int data; node *next;
    node(int val){ data=val; next=NULL; }
};

node *append_k(node *&head, int k, int l){

// to append last k nodes at starting- while(temp->next!=null) - traverse
// use a counter at l-k loc - newtail and next to it will be newhead (l-k+1)
// make next of newtail null and next of temp(last node) as head
// newhead will be the ans

    int count=1; 

    node *temp = head, *newhead, *newtail;
    
    while(temp->next!=NULL){

        if(count==l-k){
            newtail = temp;
        }
        if(count==l-k+1){
            newhead = temp;
        }
         temp=temp->next;
        count++;
    }
    if(k==1){ // to insert last node at first - while loop terminates one step before for this case
        newhead=temp;
    }
    newtail->next=NULL;
    temp->next=head;
    return newhead;

    // uses one less pointer
    // while(count!=l-k){ 
    //     count++;
    //     temp=temp->next;
    // }
    // newtail=temp;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    // temp->next=head;
    // head=newtail->next;
    // newtail->next=NULL;
    // return head;
}

int findLen(node *head){
    if(head== NULL) return 0;
    node *temp=head;
    int count = 1;
    while(temp->next!=NULL){
        count++; temp=temp->next;
    }
    return count;

}


void insert(node *&head, int val){
    node *n = new node(val);
    if(head==NULL){ head=n; return; }
    node *temp=head;
    while(temp->next!=NULL){ temp=temp->next; }
    temp->next=n;
}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){ cout<<temp->data<<" "; temp=temp->next; }
}

int main(void){
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    display(head);
    node *newhead = append_k(head, 3, findLen(head));
    cout<<endl;
    display(newhead);

 }