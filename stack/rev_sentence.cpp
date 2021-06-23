#include<iostream>
#include<stack>
using namespace std;

void revStr(string str){

    stack<string> s;

    for(int i=0; i<str.length(); i++){
        string word= "";
        while(str[i]!=' ' && i<str.length()){
            word+=str[i];
            i++;
        }

        s.push(word);
    }
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(void){

    string str;
    getline(cin, str);

    revStr(str);
}