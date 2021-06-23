#include<iostream>
#include<stack>
using namespace std;

int prefixEvaluation(string s){

    stack<int>st;

    for(int i=s.length()-1; i>=0; i--){

        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0'); // sub ascii of 0 to get int
        
        else{
            // take out two ints if an operator is encountered
            int a=st.top();st.pop();
            int b= st.top(); st.pop();

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

            case '^':
                st.push(a^b);
                break;
            }
        }
    }
    return st.top();
}


int main(void){

    string s; cin>>s;

    cout<<prefixEvaluation(s);
}