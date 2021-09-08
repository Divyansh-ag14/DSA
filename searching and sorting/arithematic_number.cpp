/*
Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference 
of an arithmetic sequence and an integer 'B'. 
you need to tell whether 'B' exists in the arithmetic sequence or not.
*/

#include<iostream>
using namespace std;

int inSequence(int a, int b, int c){

    if(c==0){ // if c is 0, we cant move further in ap
        if(a==b) return 1; // both the elements are equal: return 1
        return 0;
    }

    else{

        if((b-a)/c < 0) // this is the formula to get the nth term, so its value cant be negative
            return 0;

        if((b-a)%c == 0) return 1;  // if the difference bw numbers is reachable with c return 1
            
        return 0;

    }

}


int main(void){

    int a=1,b=3,c=2;

    cout<<inSequence(a,b,c);
}