#include<iostream>
using namespace std;

int main(void){

    while(true){

        int n;
        cin>>n;

        if(n==0) break;

        else{

            int arr1[n];
            for(int i=0; i<n; i++)
                cin>>arr1[i];

            int m; cin>>m;
            int arr2[m];
            for(int i=0; i<m; i++)
                cin>>arr2[i];

            int s1=0, s2=0;
            int i=0, j=0;
            int ma=0;

            while(i<n && j<m){

                if(arr1[i] < arr2[j])
                    s1+=arr1[i++];

                else if(arr2[j] < arr1[i])
                    s2+=arr2[j++];

                else{

                    ma+= max(s1, s2) + arr1[i];
                    i++, j++;
                    s1=0, s2=0;
                }
            }

            while(i<n)
                s1+=arr1[i++];

            while(j<m)
                s2+=arr2[j++];

            ma+= max(s1, s2);

            cout<<ma<<endl;

        }
    }
}