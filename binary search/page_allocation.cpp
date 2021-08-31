/* given an array of books where every book contains n pages
   divide all these books among m students, such that the max pages allocated is min i.e minmize the maximum no of allocated pages

   ex:
    pages = [12, 34, 67, 90]
    students(m) = 2

    allocation:
    [12], [34, 67, 90] max = 191
    [12, 34], [67, 90] max = 157
    [12, 34, 67], [90] max = 113 (ans)
*/


#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool isFeasible(int arr[], int n, int mid, int m){ // the max pages a stu can read is m

    int students=1, sum=0; // sum denotes the curr no of pages allocated to student

    for(int i=0; i<n; i++){

        if(arr[i] > mid) // if current book has more pages then m - return 0 (as we cannot skip any book)
            return 0;

        if(sum + arr[i] > mid){ // if student cannot read any more pages
                                // increase students    
            students++;
            sum=arr[i];

            if(students>m) // if no of student become more then allowed: return 0
                return 0;
        }

        else{ // student can read more pages

            sum+=arr[i];

        }
    }

    return 1;

}

int allocatePages(int arr[], int n, int m){

    if(n<m) return -1;

    int res= INT_MAX, sum=0;

    for(int i=0; i<n; i++)
        sum+=arr[i];

    // range of binary search: 0 to sum of all
    // (each stu has to have one book)

    int i=0, j=sum;

    while(i<=j){

        int mid = (i+j)/2; 

        if(isFeasible(arr, n, mid, m)){ 

            // if m is feasible - try to minimize the res by updating j
            res = min(mid, res);
            j = mid-1; 
        }

        // else increase range
        else i = mid+1;
    }

    return res;
}

int main(void){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int m; cin>>m;

    cout<<allocatePages(arr, n, m);
}