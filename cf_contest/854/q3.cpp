#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    string ans = s;
    int l = 0;
    int r = s.size()-1;
    int tog = 1;
    int i;
    for(i = 0;i<s.size();i++){
        if(tog){
            ans[r--] = s[i];
            if(i+1<s.size()){
                if(s[i+1]!=s[i]){
                    break;
                }
            }
        }
        else{
            ans[l++] = s[i];
        }
        tog = 1-tog;
    }
    i++;
    for(;i<s.size();i++){
        ans[l++] = s[i];
    }
    int n = s.size();
    for(i = 0;i<n/2;i++){
        if(ans[i]!=ans[n-i-1]){
            break;
        }
    }
    for(;i<n/2;i++){
        if(ans[i]>=ans[n-i-2] && i!=n-i-2){
            int z = ans[n-i-2];
            ans[n-i-2] = ans[n-i-1];
            ans[n-i-1] = z;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}