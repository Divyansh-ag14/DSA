#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

// use map to check if a char can be pushed in stack or not (opening parenthesis have pos value)
unordered_map<char, int> val= { {'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3} };

string isBalanced(string s){
    stack<char> st;
    
    for(char bracket: s){
        
        if(val[bracket]<0)
            st.push(bracket);
        else{
            if(st.empty()) 
                return "No";
            
            char top= st.top();
            st.pop();
            if(val[top] + val[bracket]!=0)
                return "No";
        }
    }

    if(st.empty())
        return "Yes";
    return "No";

}

int main(void){

    string s; cin>>s;
    cout<<isBalanced(s);
    
}