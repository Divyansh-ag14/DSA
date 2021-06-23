// single ll -> node: two parts (data and next)
// doubly ll -> node: three parts (prev data next), prev: stores the add of prev node
// benifits - we can traverse in both forward and backward direction
// note: prev pointer of 1st node points at null and next pointer of last node points at null;

// ll -  1->2->3->NULL
// dll - NULL<=>1<=>2<=>3->NULL (prev of 1 and next of 3 <=>NULL)

#include<iostream>
using namespace std;

class node{
    
    public:

    node *prev; int data; node *next;

    node(int val){
        prev = NULL;
        data = val;
        next = NULL;

    }

};

void insertionAtHead(node *&head, int val){

// to insert node at starting - point next of this node to head, then point prev of head to this node
// then update head to new node

    node *n = new node(val);
    if(head == NULL){
        head=n;
        return;
    }
    n->next=head;
    head->prev=n;
    head = n;

}

void insertAtLast(node *&head, int val){

// to insert node at last simply traverse the list and reach the last node
// make its next point to new node
// make sure to update prev of new node to the last node of original list

    node *n = new node(val);
    if(head == NULL){ // allows us to insert at head at before tail (in main() - we can now start with this function first if we want)
        head=n;
        return;
    }

    node *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    
    temp->next=n;

    // update prev pointer
    n->prev=temp;

}

void delHead(node *&head){

    node *todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;

}

void del(node *&head, int val){
// last node have  to be specailly taken care of

    if(head->next== NULL){ //only single node in dll
        delHead(head);
        return;
    }

    if(head->prev==NULL){
        delHead(head); // if someone uses this function to delete starting node - it will call delHead()
    }
    
    node *temp = head;

    // unlike going to the n-1th node in ll we can go to the nth node in dll
    // to delete this node - update next of n-1 node to n+1 and prev of n+1 to n-1   
    while(temp!=NULL && temp->data!=val){
        temp=temp->next;
        
    }

    // first see if specified node is the last (as its next is null it has to be treated differently)
    // to delete the last node - update the next of n-1th node to null
    //save the last node in a ptr and delete it to avoid memory leak
    if(temp->next==NULL){
        node *todel = temp;
        temp->prev->next=NULL;
        delete todel;
        return;
    } 
    
    // now we are at the nth node - update the links of n-1th and n+1th node
    // note: this will not work for last node at its next is null
    temp->prev->next = temp->next; // temp->prev = n-1th node
    temp->next->prev = temp->prev; // temp->next = n+1th node
    delete temp;

}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(void){

    node *head = NULL;
    insertionAtHead(head, 1);
    insertAtLast(head, 2);
    insertAtLast(head, 3);
    display(head);
    insertionAtHead(head, 0);
    cout<<endl;
    display(head);
    cout<<endl;
    del(head, 3);
    display(head);
    cout<<endl;
    delHead(head);
    display(head);

}