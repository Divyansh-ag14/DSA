/*

Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection 
point. Take for example the following two sequences where intersection points are
printed in bold:

First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, 
or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, 
the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. 
Each line denotes a sequence and is speciﬁed using the following format:

n v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. 
Each sequence will have at least one element but no more than 10,000. 
All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.

Output
For each test case, write on a separate line, the largest possible sum that can be produced.

Sample
Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

Output:
450
2100

*/


#include<iostream>
using namespace std;

int main(void){

    while(true){

        int n;
        cin>>n;

        if(n==0) break; // when input is 0: stop

        else{

            int arr1[n]; // 1st array
            for(int i=0; i<n; i++)
                cin>>arr1[i];

            int m; cin>>m; 
            int arr2[m]; // 2nd array
            for(int i=0; i<m; i++)
                cin>>arr2[i];

            int s1=0, s2=0; // sum of arrays
            int i=0, j=0; // two pointers
            int ma=0; // final ans

            while(i<n && j<m){ // iterate through the arrays

                if(arr1[i] < arr2[j]) 
                    s1+=arr1[i++]; // store sum of 1st array

                else if(arr2[j] < arr1[i])
                    s2+=arr2[j++]; // store sum of 2nd array

                else{ // if element is same

                    ma+= max(s1, s2) + arr1[i]; // add max of s1 and s2 to ans (also add current element)
                    i++, j++; // incerement both pointers
                    s1=0, s2=0; // reset the sum to 0 (new sums will be calculated till bridge point is reached again) 
                }
            }

            while(i<n) // remaining elements in 1st array
                s1+=arr1[i++];

            while(j<m) // remaining elements in 2nd array
                s2+=arr2[j++];

            ma+= max(s1, s2); // add max of both sums to ans

            cout<<ma<<endl;

        }
    }
}