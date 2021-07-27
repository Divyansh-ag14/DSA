#include<iostream>
#include<algorithm>
using namespace std;

struct activity{

    int start, finish;
};

bool compare(activity a, activity b){

    return a.finish < b.finish; 
}

void getMaxActivities(activity arr[], int n){

    sort(arr, arr+n, compare);

    cout<<arr[0].start<<" "<<arr[0].finish<<endl;

    int i=0;

    for(int j=1; j<n; j++){

        if(arr[j].start >= arr[i].finish){
            cout<<arr[j].start<<" "<<arr[j].finish<<endl;
            i=j;
        }
    }
}

int main(void){

    int n; cin>>n;

    activity arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i].start>>arr[i].finish;

    cout<<"---------"<<endl;
    getMaxActivities(arr, n);
    
    for(int i=0; i<n; i++)
        cout<<arr[i].start<<" "<<arr[i].finish<<endl;
}