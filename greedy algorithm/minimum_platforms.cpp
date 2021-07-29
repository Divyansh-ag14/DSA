#include<iostream>
#include<algorithm>
using namespace std;

struct train{

    int arrival, departure;
};

int getMinPlatforms(int arr[], int dep[], int n){

    sort(arr, arr+n);
    sort(dep, dep+n);

    int platforms = 1, temp=1;

    int i=1,j=0;

    while(i<n && j<n){

        if(arr[i] <= dep[j]){ // if train arrives berfore departure of prev, platform is increased
            temp++;
            i++;
        }

        else{
            temp--; // one train has left before arrival of current train (so platform is decreased)
            j++;
        }

        platforms = temp > platforms ? temp : platforms; // get max at each iteration
    }

    return platforms; 

}

int main(void){

    int n; cin>>n;
    int arr[n], dep[n];

    cout<<"arrival time:"<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<"departure time:"<<endl;
    for(int i=0; i<n; i++) cin>>dep[i];

    cout<<getMinPlatforms(arr, dep, n);
}