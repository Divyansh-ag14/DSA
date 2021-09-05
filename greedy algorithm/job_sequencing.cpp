#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{

    int id, dead, profit;
};

bool comparison(Job a, Job b){
        
    return a.profit > b.profit;
}
    
void JobScheduling(Job arr[], int n) { 
    
    sort(arr, arr+n, comparison); // sort jobs in decreasing order of profit 

    vector<int>jobs;
    int profit=0;
        
    int max_dead = arr[0].dead; // create an array slot to mark jobs on particular days
    
    for(int i=1; i<n; i++) 
        max_dead = max(max_dead, arr[i].dead);
            
    int slot[max_dead + 1];
        
    for(int i=0; i<=max_dead; i++)
        slot[i] = -1; // initially no slot is taken
            
        
    for(int i=0; i<n; i++){ 
        
        for(int j=arr[i].dead; j>0; j--){ // for every job - mark slot as late as possible
                                    // the last day to mark slot for a job is its deadline
            
            if(slot[j] == -1){ // if slot is empty
                
                slot[j] = i; // mark slot with index of job
                jobs.push_back(arr[i].id); 
                profit += arr[i].profit;
                
                break; // as job has been marked
            }
        }
    }

    cout<<"Selected Jobs: ";
    for(int i=0; i<jobs.size(); i++)
        cout<<jobs[i]<<" ";
    cout<<endl<<"Max Profit: "<<profit;
}

int main(void){

    int n = 5;
    Job arr[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27},
                   {4, 1, 25}, {5, 3, 15}};

    JobScheduling(arr, n);

}