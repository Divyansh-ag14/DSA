/*

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. 
There can be many ways or permutations to do so. In each permutation, 
one of the M students will be allocated the maximum number of pages. Out of all these permutations, 
the task is to find that particular permutation in which the maximum number of pages allocated to a student 
is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order 

*/


#include<iostream>
using namespace std;

bool isFeasible(int arr[], int n, int m, int mid){

    int students=1, pages=0;

    for(int i=0; i<n; i++){

        if(arr[i] > mid) return 0;

        if(pages + arr[i] > mid){

            students++;
            pages=arr[i];

            if(students > m) return 0;

        }

        else pages+=arr[i];

    }

    return 1;

}

int findPages(int arr[], int n, int m){

    if(n<m) return -1;

    int s=0, ans=0;
    for(int i=0; i<n; i++)
        s+=arr[i];

    int i=0, j=s; // range of binary search

    while(i<=j){

        int mid  = (i+j)/2;

        if(isFeasible(arr, n, m, mid)){ // if current no is valid

            ans = mid; // update ans
            j=mid-1; // try to minimize the ans by decreasing the upper bound (j)

        }

        else i=mid+1; // if ans is not valid: increase lower bound(i)

    }

    return ans;

}

int main(void){

    int N = 4;   
    int A[] = {12,34,67,90};
    int M = 2;

    cout<<findPages(A, N, M);
}