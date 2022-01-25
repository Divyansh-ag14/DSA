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



int main(void){

    int N = 6, K = 2;
    char arr[] = {'T', 'T', 'P', 'P', 'T', 'P'};

    cout<<catchThieves(arr, N, K)<<endl;
    
}