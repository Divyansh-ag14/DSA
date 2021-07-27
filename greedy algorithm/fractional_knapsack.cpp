#include<iostream>
#include<algorithm>
using namespace std;

struct knapsack{
    
    double val, weight;
}; 

bool compare(knapsack a, knapsack b){

    return a.val/a.weight > b.val/b.weight;
}

double getMaxValue(knapsack arr[], int n, double w){

    sort(arr, arr+n, compare);

    double ans=0;

    for(int i=0; i<n; i++){

        if(w >= arr[i].weight){ // entire item can fit
            
            w-=arr[i].weight;
            ans+=arr[i].val;
        
        }

        else{ // some part of the item can fit

            double vw = arr[i].val / arr[i].weight;

            ans+= vw* w;
            w=0;

        } 

    }

    return ans;
}

int main(void){

    int n; cin>>n;

    knapsack arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i].val>>arr[i].weight;

    cout<<getMaxValue(arr, n, 50);

}