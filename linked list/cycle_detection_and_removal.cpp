// cycle - when two nodes have same their next pointer pointing to same node
//floyd's algo - use two pointers p1 and p2 intially pointing at head
// p1 moves ahead by 1 and p2 by 2, if p1 and p2 ever land on the same node then there is a cycle in the linked list

#include<iostream>
using namespace std;

class node{
    public:
    int data; node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

bool detectCycle(node *head){

    node *p1=head, *p2=head; 

    while(p2!=NULL && p2->next!=NULL){ // focus on terminating condition - if there is no cycle then at a certain point p2 will reach the last node where its next will be null
        
        p1 = p1->next; // moves by 1
        p2 = p2->next->next; // moves by 2

        if(p1 == p2) // if p1 and p2 are on the same node
            return true;

    }
    return false;

}

// to remove cycle first traverse the two pointers till they point to the same node
// then set any of the two pointers to the head (let it be the fast pointer p2)
// increment both pointers by 1 till there next points to the same node
// modify next of p1 to null
void removeCycle(node *&head){

    node *p1=head, *p2=head; 

    do // traverse till both are equal (initially both are at head, hence the do while loop)
    {
        p1=p1->next;
        p2=p2->next->next;
    } while (p1!=p2);
    
    // set p2 to head
    p2=head;

    // traverse till next of p1 and p2 is same
    while(p1->next != p2->next){
        p1=p1->next;
        p2=p2->next;
    }

    // now set the next of p1 to null to remove cycle
    p1->next=NULL;

}

// function to make a cycle in ll
void createCycle(node *&head, int pos){

// to make a cycle - iterate through ll and reach the last node make next of this node point to the node of defined pos
// use node *startnode to store the node at the given pos 

    node *temp = head;
    node *startnode;
    int count = 1;// to keep track of pos
    while(temp->next!=NULL){
        if(count==pos) // if we are at the given position then store that node
            startnode = temp;
        temp=temp->next; 
    }
    // now temp is at the last node - simply point its next to startnode to create a cycle
    temp->next = startnode;

}

void insert(node *&head, int val){
    node *n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"END"<<endl;
}

int main(void){

    node *head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);

    display(head);
    
    if(detectCycle(head)) cout<<"cycle is present";
    else cout<<"cycle is not present";
    
    createCycle(head, 3);
    cout<<endl;
    if(detectCycle(head)) cout<<"cycle is present";
    else cout<<"cycle is not present";

    removeCycle(head);
    cout<<endl;
    if(detectCycle(head)) cout<<"cycle is present";
    else cout<<"cycle is not present";
    cout<<endl;
    
    display(head);

    
}