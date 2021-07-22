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

node *merge(node *arr[], int K){

    if(K==0) return NULL;

    priority_queue<node*, vector<node*>, compare>pq;

    for(int i=0; i<K && arr[i]!=NULL; i++)
        pq.push(arr[i]);

    node *n = new node(0);
    node *dummy = n;

    while(!pq.empty()){

        node *curr = pq.top();
        pq.pop();

        dummy->next = curr;
        dummy = dummy->next;

        // if there are elements in the same linked list, then push them into the queue
        if(curr->next!=NULL)
            pq.push(curr->next);

    }

    return n->next;
}

void insert(node *&head, int val){

    node *temp = head;
    node *n = new node(val);

    while(temp->next != NULL)
        temp = temp->next;
    
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

    int k= 3;
    node *arr[k];

    arr[0] = new node(1);
    insert(arr[0], 3);
    insert(arr[0], 5);
    insert(arr[0], 7);

    arr[1] = new node(2);
    insert(arr[1], 4);
    insert(arr[1], 6);
    insert(arr[1], 8);

    arr[2] =  new node(0);
    insert(arr[2], 9);
    insert(arr[2], 10);
    insert(arr[2], 11);

    node *head = merge(arr, k);

    display(head);

}