#include<iostream>
#include<limits.h>
using namespace std;

class MaxHeap{

    private:
    int *arr; // pointer to the elements in heap
    int capacity; // max possible size of heap
    int heap_size; // current heap size

    public:

    MaxHeap(int capacity){
        this->capacity=capacity;
        heap_size=0;
        arr= new int[capacity];
    }

    int parent(int i){ return ((i-1)/2); }
    int left(int i){ return ((2*i) + 1); }
    int right(int i){ return ((2*i) + 2);}

    void insert(int key){

        if(heap_size==capacity){ // check if arr is full
         cout<<"OVERFLOW!"<<endl;
         return;   
        }

        heap_size++;
        int i= heap_size-1;
        arr[i]=key;

        while(i!=0 && arr[i] > arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }

    void heapify(int i){

        if(i>=heap_size) return;

        int l= left(i);
        int r= right(i);
        int largest= i;

        if(l<heap_size && arr[l] > arr[i])
            largest=l;
        
        if(r<heap_size && arr[r] > arr[largest])
            largest=r;

        if(largest!=i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }

    }

    int extractMax(){

        if(heap_size <= 0){ cout<<"Heap is empty!"; return INT_MAX; }

        if(heap_size==1){
            heap_size--;
            return arr[0];
        }

        int root=arr[0];
        arr[0]= arr[heap_size-1]; // replace root with last element
        heap_size--; // dec size of heap 
        
        heapify(0);

    }

    void increaseKey(int i, int new_val){

        arr[i]=new_val;

        while(i!=0 && arr[i] > arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }

    void deleteKey(int i){

        increaseKey(i, INT_MAX);
        extractMax();
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

    MaxHeap obj(5);
    
    for(int i=1; i<=5; i++)
        obj.insert(i);
    obj.display();

    // obj.extractMax();
    // obj.display();
    obj.deleteKey(1);
    obj.display();
    
}