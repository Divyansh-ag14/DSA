#include<iostream>
#include<unordered_map>
using namespace std;

// majority element: an element appearing more then n/2 times where n is the size of array

// T: O(n)   S: O(n)
int majorityElement(int arr[], int size){
        
    unordered_map<int,int> m;
    
    for(int i=0; i<size; i++)
        m[arr[i]]++;
            
    for(auto it: m){
        
        if(it.second> size/2)
            return it.first;
    } 
    
    return -1;

}


// T: O(n)   S: O(1)
// use a couonter: increment for same elements and decrement for different
// at last a potential ans will have counter eaqual to 1 at least
// run a for loop and verify if its frequency is > n/2 or not

int majorityElementOptimized(int arr[], int size){

    // initialize ans with 1st element    
    int predicted_majority_element = arr[0];
    int count = 1;
    
    for(int i=1; i<size; i++){

        if(arr[i]==predicted_majority_element) // if next element is same 
            count++;

        else count--; // if elements are diff decrement count

        if(count==0){ // if, for the prev ans count becomes 0 then update it with current array element
            predicted_majority_element=arr[i];
            count=1;
        }

    }

    // check if ans is right else return -1
    count =0;
    for(int i=0; i<size; i++){
        if(arr[i]==predicted_majority_element)
            count++;
    }

    if(count > size/2) return predicted_majority_element;
    else return -1;
     
}


int main(void){

    int arr[5] = {3,1,3,3,2};

    cout<<majorityElementOptimized(arr, 5); 
}