#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    string s;cin>>s;ll pos;cin>>pos;
    ll n=s.size();
    ll k=0;
    ll tmp=n;
    for(int i=0;i<n;i++){
        if(pos-tmp<=0){
            break;
        }
        k++;
        pos-=tmp;
        tmp--;
    }
    vector<char> st;
    int idx=-1;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.back()>s[i]){
            st.pop_back();
            k--;
            if(k==0){
                break;
            }
        }
        if(k==0){
            idx=i-1;
            break;
        }
        st.push_back(s[i]);
    }
    if(pos<=st.size()){
        cout<<st[pos-1];
    }
    else{
        pos-=st.size();
        cout<<s[idx+pos];
    }
    return;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}