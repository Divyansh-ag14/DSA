/*

IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function. 
The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). 
A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 
1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. 
he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes 
hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have 
enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. 
Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. 
In the first line of the test case we have P the number of prata ordered. 
In the next line the first integer denotes the number of cooks L and L integers follow in the same line 
each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

 

Example
Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1
Output:
12
36
1

*/

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