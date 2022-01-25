#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data; node *next;
    node(int val){ data=val; next=NULL;}
};

void insert(node *&head, int val){
    node *n = new node(val);
    if(head==NULL){
        head=n;
        return;
    } 
    node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=n;
}

// S: O(1)
// this is an inplace solution
// we are not creating a new list, just modifiying the links
node *mergeOptimized(node *l1, node *l2){

    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    // l1 should always be smaller
    if(l1->data > l2->data)
        swap(l1, l2);

    // assingn res to l1
    node *res=l1;

    // iterate through both the lists
    while(l1!=NULL && l2!=NULL){

        // create a temp to modify links
        node *temp=NULL;

        // until l1 < l2: temp will keep pointing to l1
        while(l1!=NULL && l1->data <= l2->data){
            temp=l1;
            l1=l1->next;
        }

        // when l2 becomes less than l1: update the link
        // swap to make l1 smaller again
        temp->next=l2;
        swap(l1, l2);

    }

    return res;

}

node *merge(node *head1, node *head2){
// create 3 pointers and (one dummy node)
// one pointer will point to dummy node

    node * temp1=head1, *temp2=head2;
   node *dummynode = new node(-1); // initialize dummy node 
    node *dummy=dummynode;
    
    // traverse both lists and sotre the smaller number in next of dummy pointer
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            dummy->next=temp1;
            temp1=temp1->next;
        }
        else {
            dummy->next=temp2;
            temp2=temp2->next;
        }
        dummy=dummy->next;   // important to update it
    }

// add any remaiing nodes
    while(temp1!=NULL){
        dummy->next=temp1;
        temp1=temp1->next;
        dummy=dummy->next;
    
    }
    while(temp2!=NULL){
        dummy->next=temp2;
        temp2=temp2->next;
        dummy=dummy->next;
    }
    
    return dummynode->next;
}

node *mergeRecursive(node *head1, node *head2){

    node *ans;
    
// base conditon
    if(head1 == NULL) return head2;
    if(head2==NULL) return head1;

    if(head1->data < head2->data){
        ans=head1;
        ans->next= mergeRecursive(head1->next, head2);
    }
    else{
        ans=head2;
        ans->next = mergeRecursive(head1, head2->next);
    }

    return ans;
}

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(void){

    node *head1 = NULL, *head2=NULL;
    insert(head1, 1);
    insert(head1, 1);
    insert(head1, 1);
    insert(head1, 1);
    insert(head2, 1);
    insert(head2, 1);
    insert(head2, 1);
    cout<<"list 1: ";
    display(head1);
    cout<<endl<<"list 2: ";
    display(head2);
    //node *newhead =mergeRecursive(head1, head2);
    node *ans = mergeOptimized(head1, head2);
    cout<<endl<<"merged list: ";
    //display(newhead);
    display(ans);
}