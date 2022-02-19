#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

bool isValid(string s){

    stack<char> st;

    for(char bracket: s){

        if(bracket=='(' || bracket=='[' || bracket=='{')
            st.push(bracket);

        else{
                
            if(st.empty()) return 0;
                
            else{
                    
                if(st.top()=='(' && bracket!=')') return 0;
                if(st.top()=='[' && bracket!=']') return 0;
                if(st.top()=='{' && bracket!='}') return 0;
                
                st.pop();
                
            }
        }

    }

    return st.empty();
    
}

int main(void){
}