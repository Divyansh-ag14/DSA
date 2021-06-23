#include<iostream>
#include<stack>
using namespace std;

int postfixEvaluation(string s){

    stack<int> st;

    for(int i=0; i<s.length(); i++){

        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0'); // sub ascii to get int 

        else{

            int b= st.top(); st.pop();
            int a= st.top(); st.pop();

            switch (s[i])
            {
            case '+':
                st.push(a+b);
                break;
            
            case '-':
                st.push(a-b);
                break;

            case '*':
                st.push(a*b);
                break;

            case '/':
                st.push(a/b);
                break;
            
            }

        }

    }
    return st.top();

}

int main(void){

    string s; cin>>s;
    cout<<postfixEvaluation(s);

}