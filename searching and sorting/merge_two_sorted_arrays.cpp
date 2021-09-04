#include<iostream>
#include<algorithm>
using namespace std;

// T: O(n) S: O(n)
void merge1(int arr1[], int arr2[], int n, int m){

    int c[n+m];

    int i=0, j=0, k=0;

    while(i<n && j<m){

        if(arr1[i] <= arr2[j])
            c[k++] = arr1[i++];

        else
            c[k++] = arr2[j++];

    }

    while(i<n)
        c[k++] = arr1[i++];

    while(j<m)
        c[k++] = arr2[j++];

    i=0,j=0;

    for(int i=0; i<n; i++)
        arr1[i] = c[i];

    for(int i=0; i<m; i++)
        arr2[i] = c[n+i];

    for(int i=0; i<n; i++)
       cout<<arr1[i]<<" ";

    cout<<endl;
    for(int i=0; i<m; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;
}

// T: O(n*m)   S: O(1)
void merge2(int arr1[], int arr2[], int n, int m){

    for(int i=m-1; i>=0; i--){

        int j, last=arr1[n-1];

        for(j=n-2; j>=0 && arr1[j] > arr2[i]; j--)
            arr1[j+1] = arr1[j];

        if(j!=n-2 || last > arr2[i]){

            arr1[j+1] = arr2[i];
            arr2[i] = last;

        }

    }

    for(int i=0; i<n; i++)
       cout<<arr1[i]<<" ";

    cout<<endl;
    for(int i=0; i<m; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

}


// T: O((n+m)log(n+m))   S: O(1)
void merge(int arr1[], int arr2[], int n, int m){

    int i=0, j=0, k=n-1;

    while(i<=k && j<m){

        if(arr1[i] < arr2[j])
            i++;

        else swap(arr1[k--], arr2[j++]);

    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+m);

    for(int i=0; i<n; i++)
       cout<<arr1[i]<<" ";

    cout<<endl;
    for(int i=0; i<m; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;
}

int main(void){

    int N = 4, M = 5;
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    
    merge(arr1, arr2, N, M);
}