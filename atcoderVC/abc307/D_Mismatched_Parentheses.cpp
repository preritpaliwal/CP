#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;string s;cin>>s;vector<int> v(n,0);
    vector<char> st;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(st.empty()){
            cnt+=s[i]=='(';
            st.push_back(s[i]);
            continue;
        }
        if(s[i]!=')'){
            st.push_back(s[i]);
            cnt+=s[i]=='(';
        }
        else{
            while(cnt>0 && st.back()!='('){
                st.pop_back();
            }
            if(cnt>0){
                cnt--;
                st.pop_back();
            }
            else{
                st.push_back(')');
            }
        }
    }
    for(char c:st)cout<<c;
}