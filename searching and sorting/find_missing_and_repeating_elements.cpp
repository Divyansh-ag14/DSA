#include<iostream>
#include<vector>
using namespace std;


// go to every element of array and mark the value on that ubdex as negative
// if, from some element(i)  we reach an element that is already negative then i is repeating
// as we marked an element at index i already
// missing number: index element which is not negative  

int *findTwoElements(int arr[], int n){

    int repeating, missing;

    for(int i=0; i<n; i++){ 

        if(arr[abs(arr[i])-1] < 0) // we reaching a negative element again
            repeating = abs(arr[i]); // store the repeating number

        else arr[abs(arr[i])-1] = -arr[abs(arr[i])-1]; // if we are visiting an element first time make it negative   
    }

    for(int i=0; i<n; i++){

        if(arr[i]>0){
            missing = i+1;
            break;
        }
    }

    int *ans = new int[2]{repeating,missing};

    return ans;
}

int main(void){

    int arr[5] = {2, 4, 3, 3, 5};

    int *ans = findTwoElements(arr, 5);
    cout<<"repeatig: "<<ans[0]<<endl<<"missing: "<<ans[1];
}