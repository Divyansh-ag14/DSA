#include<iostream>
#include<limits.h>
using namespace std;

class MinHeap{

    private:
    int *arr; // pointer to the elements in heap
    int capacity; // max possible size of heap
    int heap_size; // current heap size

    public:
    MinHeap(int capacity){
        this->capacity=capacity;
        heap_size=0;
        arr= new int[capacity];
    }

    int parent(int i){ return ((i-1)/2); }
    int left(int i){ return ((2*i) + 1); }
    int right(int i){ return ((2*i) + 2);}

    void insert(int k){

        if(heap_size == capacity){ // check if arr is full
            cout<<"Overflow!";
            return;
        }

        heap_size++;
        int i=heap_size-1; // current pos where element will be inserted
        arr[i]=k; // insert element at last

        while(i!=0 && arr[parent(i)] > arr[i]){ // if the current element is smaller then its parent
            swap(arr[i], arr[parent(i)]); // swap them
            i = parent(i); // i or pos of (k) now becomes equal to its older parent
        }

    }

    void heapify(int i){

        if(i>=heap_size) return;

        int l= left(i);
        int r= right(i);
        int smallest=i;

        if(l< heap_size && arr[l]<arr[i])
            smallest=l;

        if(r<heap_size && arr[r]<arr[smallest]) // note, we have replaced i with smallest here 
            smallest=r;          // in case smallest got modified, we can compare r with updated smallest value

        if(smallest!=i){ 
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){

        if(heap_size <= 0){ cout<<"Heap is empty!"; return INT_MAX;}
        
        if(heap_size==1){
            heap_size--;
            return arr[0];
        }

        int root= arr[0];
        arr[0]= arr[heap_size-1]; // replace root with last element
        heap_size--; // dec size of heap 

        heapify(0);

        return root;
    }

    void decreaseKey(int i, int new_val){

        arr[i]=new_val;

        while(i!=0 && arr[i] < arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }

    void deleteKey(int i){ // to delete a key - replace it with INT_MIN - place it at the correcct pos(root) 
                           // then extarctMin
        if(heap_size==0){ cout<<"UNDERFLOW!"; return; }
        if(heap_size==1){ heap_size--; return; }

        decreaseKey(i, INT_MIN);
        extractMin();

    }

    bool linearSearch(int key){
        for(int i=0; i<heap_size; i++){
            if(arr[i]==key)
                return 1;
        }
        return 0;
    }

    void display(){
        for(int i=0; i<heap_size; i++)
            cout<<arr[i]<<" ";
    	cout<<endl;
    }

    int getParent(int i){
        if(i==0) return i;
        return arr[parent(i)];
    }

    int getLeftChild(int i){
        if(left(i)>=heap_size) {cout<< "No child!"; return INT_MIN; }
        return arr[left(i)];
    }

    int getRighttChild(int i){
        if(right(i)>=heap_size) {cout<< "No child!"<<endl; return INT_MIN; }
        return arr[right(i)];
    }

};

int main(void){

    MinHeap obj = MinHeap(10);

    for(int i=5; i>=1; i--)
        obj.insert(i);

    obj.display();
    // cout<<obj.extractMin()<<endl;
    // obj.display();
    // cout<<obj.extractMin()<<endl;
    // obj.display();

    obj.deleteKey(1);
    obj.display();
    obj.deleteKey(3);
    obj.display();
}