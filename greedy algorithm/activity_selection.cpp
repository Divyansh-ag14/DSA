#include<iostream>
#include<algorithm>
using namespace std;

struct activity{

    int start, finsish;
};

bool compare(activity a, activity b){

    return a.finsish < b.finsish; // decreasing order
}

int getMaxActivities(activity arr[], int n){

    sort(arr, arr+n, compare);

    cout<<arr[0].start<<" "<<arr[0].finsish<<endl;

    int i=0;

    for(int j=1; j<n; j++){

        if(arr[j].start >= arr[i].finsish){
            cout<<arr[j].start<<" "<<arr[j].finsish<<endl;
            i=j;
        }
    }
}

int main(void){

    int n; cin>>n;

    activity arr[n];

    cout<<getMaxActivities(arr, n);
}