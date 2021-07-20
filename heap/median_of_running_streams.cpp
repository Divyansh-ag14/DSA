/*
    brute force: for n inputs - sort the arrray an return mean
    T: (n^2logn)

    optimal approach: use min and max heaps
    divide the array into 2 parts
    (max heap stores the lower half and min heap stores the upper half) 
    during insertion - insert the element in a pos such that diff bw size of both heaps is <=1

    answer: 
    if size of heaps is not equal: top of bigger heap
    else: avg of top of both heaps
*/


#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>>pmax;
priority_queue<int, vector<int>, greater<int>>pmin;

void insert(int x){

    if(pmax.size() == pmin.size()){

        if(pmax.size()==0){ // first element
            pmax.push(x);
            return;
        }

        // since pmax contains lower half any element bigger then its top is pushed in pmin
        if(x < pmax.top()) 
            pmax.push(x);

        else pmin.push(x);
    }

    else{

        // case 1: pmax is bigger
        if(pmax.size() > pmin.size()){

            if(x >= pmax.top()) // pmax contains lower half of sorted array
                pmin.push(x);

            else{
                int temp= pmax.top(); // if x is smaller then top, it will be pushed in pmax 
                pmax.pop();          // but inorder to take care of size diff top of pmax is pushed in pmin
                pmin.push(temp);
                pmax.push(x);
            }
        }

        // case 2: pmin is bigger
        else{

            if(x <= pmin.top()) // pmin contains the greater half of the sorted array, any val < top is pushed in pmax
                pmax.push(x);

            else{

                int temp= pmin.top();
                pmin.pop();
                pmax.push(temp);
                pmin.push(x);
            }
        }
    }
}

double findMedian(){

    if(pmax.size()==pmin.size())
        return (pmax.top()+pmin.top())/2.0;

    else if(pmax.size() > pmin.size())
        return pmax.top();

    else return pmin.top();
}

int main(void){

    int arr[]= {10,15,21,30,18,19};
    for(int i=0; i<6; i++){
        insert(arr[i]);
        cout<<findMedian()<<endl;
    }
}

/*
    if equal size: 
        if x < pmax.top-> pmax.push(x)
        else-> pmin.push(x)

    if pmax > pmin (size):
        if x >= pmax.top-> pmin.push(x)
        else-> pmin.push(pmax.top)
               pmax.pop
               pmax.push(x)

    else (pmin > pmax):
        if x <= pmin.top-> pmax.push(x)
        else-> pmax.push(pmin.top)
               pmin.pop
               pmin.push(x)
*/