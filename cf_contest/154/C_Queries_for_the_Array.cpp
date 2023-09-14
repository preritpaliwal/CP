#include <bits/stdc++.h>
using namespace std;
using ll=long long;


void solve(){
    string s;cin>>s;
    vector<int> v;
    v.push_back(1);
    int cnt=0;
    for(char c:s){
        if(c=='+'){
            cnt++;
            if(cnt==1){
                v.push_back(1);
            }
            else{
                if(v.back()==0){
                    v.push_back(0);
                }
                else{
                    v.push_back(-1);
                }
            }
        }
        else if(c=='-'){
            cnt--;
            if(cnt<0){
                cout<<"NO\n";
                return;
            }
            int last = v.back();
            v.pop_back();
            if(last==1){
                v.back()=last;
            }
        }
        else if(c=='1'){
            if(v.back()==0){
                cout<<"NO\n";
                return;
            }
            else{
                v.back()=1;
            }
        }
        else{
            if(v.back()==1){
                cout<<"NO\n";
                return;
            }
            else{
                v.back()=0;
            }
        }
    }
    cout<<"YES\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
}