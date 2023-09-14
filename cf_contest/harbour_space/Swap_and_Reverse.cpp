#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll=long long;

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    string tmp=s;
    if(k%2==0){
        sort(tmp.begin(),tmp.end());
        cout<<tmp<<endl;
    }
    else{
        string odd,eve;
        for(int i=0;i<n;i++){
            if(i%2==0){
                eve+=s[i];
            }
            else{
                odd+=s[i];
            }
        }
        sort(odd.begin(),odd.end());
        sort(eve.begin(),eve.end());
        string ans;
        int idx=0,e=0,o=0;
        while(idx<n){
            if(idx%2==0){
                ans+=eve[e++];
                idx++;
            }
            else{
                ans+=odd[o++];
                idx++;
            }
        }
        cout<<ans<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}