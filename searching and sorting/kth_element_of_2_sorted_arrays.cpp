#include<iostream>
using namespace std;

//Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. 
//The task is to find the element that would be at the k’th position of the final sorted array.


int kthElement(int arr1[], int arr2[], int n, int m, int k){

    int i=0, j=0, x=0;

    while(i<n && j<m){

        if(arr1[i] <= arr2[j]){

            x++;
            if(x==k) return arr1[i];
            i++;

        }
        
        else{

            x++;
            if(x==k) return arr2[j];
            j++;

        }

    }

    while(i<n){

        x++;
        if(x==k) return arr1[i];
        i++;

    }

    while(j<n){

        x++;
        if(x==k) return arr2[j];
        j++;

    }
}


int main(void){
}