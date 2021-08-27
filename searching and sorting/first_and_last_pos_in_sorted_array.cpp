#include<iostream>
#include<vector>
using namespace std;

int getPos(int arr[], int n, int x, int move){

    int l=0, r=n-1, ans=-1;

    while(l<=r){

        int m=(l+r)/2;

        if(arr[m]<x)
            l=m+1;

        else if(arr[m]>x)
            r=m-1;

        else{ // when m mathces x

            ans=m; // ans becomes index m

            if(move==-1) r=m+move; // for finding 1st index shift r towards left
            else l=m+move; // for finding last index shift l towards r

        }

    }

    return ans;

}

vector<int> find(int arr[], int n, int x){

    int first, last;

    first = getPos(arr, n, x, -1); // for the first index 
    last = getPos(arr, n, x, 1);

    vector<int> ans = {first, last};

    return ans;
}

int main(void){


}