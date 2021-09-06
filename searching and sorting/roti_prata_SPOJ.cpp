#include<iostream>
using namespace std;

bool isFeasible(int arr[], int n, int mid, int p){

    int time = 0;
    int pratas = 0;

    for(int i=0; i<n; i++){

        time = arr[i];
        int j = 2;

        while(time <= mid){

            pratas++;
            time = time + (arr[i]*j);
            j++;

        }

        if(pratas>=p) return 1;

    }

    return 0;

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
                
                ans = mid;
                high = mid-1;

            }

            else low = mid+1;
        }

        cout<<ans<<endl;

    }
}