/*

Bishu went to fight for Coding Club. There were N soldiers with various powers. 
There will be Q rounds to fight and in each round, Bishu's power will be varied. 
With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). 
After each round, All the soldiers who are dead in the previous round will reborn. 
Such that in each round there will be N soldiers to fight. 
As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.

The second line contains an array of N numbers denoting the power of each soldier

This third line contains Q, which denotes the number of rounds.

Q lines follow, each line having one number denoting the power of Bishu.


OUTPUT:

For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.

CONSTRAINTS:

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100


Sample Input            Sample Output
7                       3 6
1 2 3 4 5 6 7           7 28
3                       2 3
3
10
2

*/


#include <iostream>
#include<algorithm>
using namespace std;

int main(void){

	int n, m;

	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr, arr+n);

	int sum_arr[n+1];
	sum_arr[0]=0;

	for(int i=1; i<=n; i++)
		sum_arr[i] = sum_arr[i-1] + arr[i-1];


	cin>>m;

	while(m--){

		int x;
		cin>>x;

		int idx = upper_bound(arr, arr+n, x) - arr;

		cout<<idx<<" "<<sum_arr[idx]<<endl;

	}

}