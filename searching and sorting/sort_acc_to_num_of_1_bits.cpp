/*

You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their 
binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]


Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 104

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution{

    public:

    static bool comp(int a, int b){

        // __builtin_popcount() tells the number of set bits
        return __builtin_popcount(a) < __builtin_popcount(b);

    }

    vector<int> sortByBits(vector<int>&arr){

        sort(arr.begin(), arr.end());

        // stable sort keeps the elements in original position if set bits are equal
        stable_sort(arr.begin(), arr.end(), comp);

        return arr;
    }

    // 2nd method
    vector<int> sortByBits2(vector<int> &arr){

        // create a map to store the number of bits in asceding order 
        // the map conains: an int that represents the number of bits
        //                  a vector that sotres all the numbers having equal bits
        // so map is used to store bits as index where each index has vector
        vector<int> ans;
        map<int, vector<int>> m;

        // store bits in map: sorted in asceding order
        // store the element corresponding to that bit
        for(auto i: arr){

            int bits = __builtin_popcount(i);
            m[bits].push_back(i);
        }

        // now we have a sorted order of bits with their respective arrays
        // simply iterate the map and push vector elements at each key to ans vector
        // (dont forget to sort the vectors)
        for(auto i: m){

            vector<int> nums = i.second;
            sort(nums.begin(), nums.end()); // imp

            for(auto j: nums)
                ans.push_back(j);

        }

        return ans;

    }
};

int main(void){

    Solution ans;
    int n;
    
    cout<<"Enter the number of elements: "; cin>>n;
    vector<int> input(n);
    
    cout<<"Enter the numbers: ";
    for(int i=0; i<n; i++)
        cin>>input[i];

    vector<int> output = ans.sortByBits2(input); // by defualt the 2nd method is called: change it to sortByBits if yo wish to

    for(auto i: output) cout<<i<<" ";
    
}