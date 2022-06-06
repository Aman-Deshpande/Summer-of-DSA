// Valid Parenthesis

// Problem Link: https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i< s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            if(s[i]==')'){
                if(st.empty()){
                    return false;
                }
                
                else if(st.top()!='('){
                    return false;
                }
                else
                    st.pop();
            }
            else  if(s[i]=='}'){
                if(st.empty()){
                    return false;
                }
                
                else if(st.top()!='{'){
                    return false;
                }
                else
                    st.pop();
            }
            else  if(s[i]==']'){
                if(st.empty()){
                    return false;
                }
                else if(st.top()!='['){
                    return false;
                }
                else
                    st.pop();
            }
        }
        if(st.empty()){
            return true;
        } else {
            return false;
        }
    }
}; 