#include<iostream>
using namespace std;

class node {
    public:
    int data; node *next;
    node(int val){ data=val; next=NULL;}
};

// to find intersection point - first find the length of the two linked lists (l1 and l2)
// set count =0 and traverse the bigger ll till count=l1-l2,  suppose (l1>l2)
// now traverse both ll and if they ever point to the same node then that will be the intersection point
// for traversing use temp1 and temp2 - temp1 for bigger ll and temp2 for smaller

int findLength(node *head){
    node *temp=head;
    if(head==NULL) return 0;
    int count=1;
    while(temp->next!=NULL){
        count ++;
        temp=temp->next;
    } 
    return count;
}

int interSectionNew(node *head1, node *head2){

    node *a=head1, *b=head2;

    while(a!=b){

        a = a==NULL ? head2 : a->next;
        b = b==NULL ? head1 : b->next;

    }

    return a->data;

}

int intersection(node *&head1, node*&head2){

    int l1= findLength(head1);
    int l2= findLength(head2);
    
    if(l1==0 ||l2==0) return 0;

    int d=0; // difference
    node* temp1= head1, *temp2=head2;
    if(l1>l2){
        temp1=head1; // bigger
        temp2=head2;
        d=l1-l2;
    }
    else{
        temp1=head2;
        temp2=head1;
        d=l2-l1;
    }

    // traverese temp1 till both reach the same position (not node but position)

    while(d--){
        if (temp1==NULL) return -1; 
        temp1=temp1->next;
    }

    // now traverse both and see if they ever point to the same node
    while(temp1!=NULL && temp2!=NULL){
        
        if(temp1==temp2){ //return the element (intersection point)
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }

    return -1; // no intersection point
}

// fucntion to intersect two nodes it assumes l1 is bigger then l2
void intersect(node *&head1, node *&head2, int pos){
    node *temp1=head1;
    pos--; // imp
    while(pos--) temp1=temp1->next;

    node *temp2=head2;
    while(temp2->next!=NULL) temp2=temp2->next; // end of smaller ll
    // insert temp at the end of smaller ll
    temp2->next=temp1;

}

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

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(void){

    node *head1 = NULL, *head2=NULL;
    insert(head1, 4);
    insert(head1, 1);
    insert(head1, 8);
    insert(head1, 4);
    insert(head1, 5);
    insert(head2, 5);
    insert(head2, 6);
    insert(head2, 1);
    cout<<"list 1: ";
    display(head1);
    cout<<endl<<"list 2: ";
    display(head2);
    intersect(head1, head2, 3);
    cout<<endl<<"after intersection"<<endl;
    cout<<"list 2: ";
    display(head2);
    cout<<endl;
    int ans = intersection(head1, head2);
    int len1= findLength(head1);
    cout<<ans;
    cout<<endl<<interSectionNew(head1, head2);
}


