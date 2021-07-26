// given an array and an integer k - form a subarray of size k having sum divisible by 3
// (if a no is divsible by 3, then sum of its digits is also divisible by 3)

#include<iostream>
#include<utility>
using namespace std;

void find(int arr[], int n, int k){

    int i=0, j=0, num=0;
    pair<int, int> ans;

    for(j=0; j<k; j++)
        num+= arr[j];

    if(num%3==0){

        ans = {0, j-1};

        for(i=ans.first; i<=ans.second; i++)
            cout<<arr[i]<<" ";
        
        return;

    }

    while(j<n){

        num-= arr[i++];
        num+= arr[j++];

        if(num%3==0){

            ans = {i, j-1};
            for(int x=ans.first; x<=ans.second; x++)
                cout<<arr[x]<<" ";
            return;
        }
    }

    cout<<"there is no subarray having number divisible by 3"<<endl;

}

int main(void){

    int arr[6] = {1, 2, 3, 4, 5, 6};

    find(arr, 6, 3);
}