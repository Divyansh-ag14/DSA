#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int minSwaps(vector<int>nums){

    // sorted array
    vector<pair<int,int>> sorted_array;

    // push array elements with their index
    for(int i=0; i<nums.size(); i++)
        sorted_array.push_back({nums[i], i});

    sort(sorted_array.begin(), sorted_array.end());

    int swaps = 0;

    // for every element in array
    for(int i=0; i<nums.size(); i++){

        // if index of element in sorted array is at the right position - no swaps
        if(sorted_array[i].second == i)
            continue;

        else{ // element is at wrong position

            // increent value of swap
            swaps++;

            // swap the current element with the element at index value of current element
            // current element is now placed at its correct position
            swap(sorted_array[i], sorted_array[sorted_array[i].second]);

            // check if the swapped element is at the correct position or not
            i--;
        }
    }

    return swaps;
}

int main(void){

    vector<int> nums = {10, 19, 6, 3, 5};

    cout<<minSwaps(nums);
}