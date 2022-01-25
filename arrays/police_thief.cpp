/*

Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. 
Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions:

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from him.

Example 1:

Input:
N = 5, K = 1
arr[] = {P, T, T, P, T}
Output: 2

Explanation: Maximum 2 thieves can be 
caught. First policeman catches first thief 
and second police man can catch either second 
or third thief.

*/


#include<iostream>
#include<vector>
using namespace std;

// T: O(n)  S: O(n)
int catchThieves(char arr[], int n, int k){

    // store the indices of police and thieves
    vector<int> police, thief;

    for(int i=0; i<n; i++){

        if(arr[i]=='P') police.push_back(i);
        else thief.push_back(i);

    }

    // itearte over the index arrays if the abs of diff is <=k inc counter and indices
    // if not inc the min of pol, thi
    int pol=0, thi=0, res=0;

    while(pol<police.size() && thi<thief.size()){

        if(abs(police[pol] - thief[thi]) <= k){

            res++;
            pol++;
            thi++;
            
        }

        else{ // inc the min index

            if(police[pol] < thief[thi]) pol++;
            else thi++;

        }

    }

    return res;

}

// optimal : S O(1)
int catchThievesOptimal(char arr[], int n, int k){

    // get the first index of police and thief
    int pol=-1, thi=-1, res=0;

    for(int i=0; i<n; i++){
        if(arr[i]=='P'){
            pol=i; // index of first police
            break;
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i]=='T'){
            thi=i; // index of first police
            break;
        }
    }

    while(pol<n && thi<n){

        if(abs(pol-thi) <= k){ // if a thief can be caught: inc res and find the next pol and thi

            res++;

            pol=pol+1;
            while(pol<n && arr[pol]!= 'P') 
                pol++;

            thi=thi+1;
            while(thi<n && arr[thi]!= 'T') 
                thi++;

        }

        else{

            // if police is behind thief: get the next pol to catch it
            if(pol < thi){

                pol=pol+1;
                while(pol<n && arr[pol]!= 'P') 
                pol++;

            }

            else{

                thi=thi+1;
                while(thi<n && arr[thi]!= 'T') 
                thi++;

            }

        }

    }

    return res;

}

int main(void){

    int N = 6, K = 2;
    char arr[] = {'T', 'T', 'P', 'P', 'T', 'P'};

    cout<<catchThieves(arr, N, K)<<endl;
    cout<<catchThievesOptimal(arr, N, K);
}