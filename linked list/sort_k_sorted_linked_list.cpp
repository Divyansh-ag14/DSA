#include<iostream>
#include<queue>
using namespace std;

struct node{

    int data;
    node *next;
    node(int val) { data=val; next=NULL; }

};

struct compare{

    bool operator()(node *a, node *b){

        return a->data > b->data;

    }

};

struct node *sort(node *head, int K){

    if(head==NULL) return head;

    priority_queue<node*, vector<node*>, compare>pq;

    for(int i=0; i<=K && head!=NULL; i++){

        pq.push(head);
        head=head->next;

    }

    node *ans=NULL, *curr;

    while(!pq.empty()){

        if(ans==NULL){
            
            ans = pq.top();
            curr=ans;

        }

        else{

            curr->next = pq.top();
            curr = curr->next;
        }

        pq.pop();

        if(head!=NULL){

            pq.push(head);
            head = head->next; 
        
        }

    }

    curr->next = NULL;
    return ans;
}

void display(node *head){

    while(head!=NULL){

        cout<<head->data<<" -> ";
        head=head->next;
    
    }
    
    cout<<"NULL"<<endl;

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


int main(void){

    node *head=NULL;
    int arr[6]={3, 6, 2, 12, 56, 8};
    
    for(int i=0; i<6; i++)
        insert(head, arr[i]);

    head= sort(head, 2);
    display(head);
}