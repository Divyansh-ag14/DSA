/*  given an array n borads and k painters
    find minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards
    (array elements are unit of time required to paint one borad)

    ex: [10, 20, 30, 40] , k=2

    partitions:
    [10] [20, 30, 40] max=90
    [10, 20] [30, 40] max=70
    [10, 20, 30] [40] max=60 (ans)
*/

#include<iostream>
#include<climits>
using namespace std;

bool isFeasible(int arr[], int n, int m, int k){

    int painters=1, time=0;

    for(int i=0; i<n; i++){

        if(arr[i] > m) return 0;

        if(time + arr[i] > m){

            painters++;
            time=arr[i];

            if(painters>k) return 0;
        }

        else time+=arr[i];
    }
}

int paintersPartiotion(int arr[], int n, int k){

    if(k<=0) return -1;

    int i=0, j=0, res=INT_MAX;

    for(int i=0; i<n; i++)
        j+=arr[i];

    while(i<=j){

        int m = (i+j)/2;

        if(isFeasible(arr, n, m, k)){

            res=min(res, m);
            j=m-1;
        }

        else i=m+1;
    }

    return res;
}

int main(void){

    int n; cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    int k; cin>>k;

    cout<<paintersPartiotion(arr, n, k);
}