#include<iostream>
using namespace std;

bool isFeasible(int arr[], int n, int mid, int p){

    int time = 0; 
    int pratas = 0;

    for(int i=0; i<n; i++){ // for every element in arr

        time = arr[i]; // initialize time with its rank
        int j = 2; 

        while(time <= mid){ // while a chef can cook

            pratas++; // inc the amount of food
            time = time + (arr[i]*j); // time is increased by multiplying j in every iteration 
            j++;

        }

        if(pratas>=p) return 1; // if food becomes greater then or equal to the required amount in time: return 1

    }

    return 0; // else return 0

}

int main(void){

    int t;
    cin>>t;

    while(t--){

        int p; cin>>p;
        int n; cin>>n;
        int ranks[n];
        for(int i=0; i<n; i++)
            cin>>ranks[i];

        int ans = 0;
        int low = 0;
        int high = 1e8;

        while(low<=high){
 
            int mid = (low+high)/2;
            if(isFeasible(ranks, n, mid, p)){
                
                ans = mid; // if current ans(time) is valid 
                high = mid-1; // try decreasing it

            }

            else low = mid+1; // if curr time is not valid: increase lower bound(low)

        }

        cout<<ans<<endl;

    }

}