#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve1(){
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

void solve(){
    string s;cin>>s;
    map<char,int> mp;
    for(char c:s){
        mp[c]++;
    }
    string ans = s;
    int n = ans.size();
    int i = 0;
    int one = 0;
    for(auto &tmp:mp){
        if(one==0){
            while(tmp.second>1){
                ans[i] = tmp.first;
                ans[n-1-i] = tmp.first;
                i++;
                tmp.second-=2;
            }
            if(tmp.second==1){
                one = tmp.first;
            }
        }
        else if(one==-1){
            while(tmp.second!=0){
                tmp.second--;
                ans[i++] = tmp.first;
            }
        }
        else{
            if(tmp.first != (*(mp.rbegin())).first){
                while(tmp.second>2){
                    ans[i] = tmp.first;
                    ans[n-1-i] = tmp.first;
                    tmp.second-=2;
                    i++;
                }
                if(tmp.second==1){
                    ans[i] = tmp.first;
                    ans[n-1-i] = one;
                    i++;
                    one = -1;
                    tmp.second--;
                }
                else if(tmp.second==2){
                    ans[i] = tmp.first;
                    ans[i+1] = tmp.first;
                    ans[n-1-i] = one;
                    i++;
                    i++;
                    one = -1;
                    tmp.second-=2;
                }
            }
            else{
                while(tmp.second>1){
                    ans[i] = tmp.first;
                    ans[n-1-i] = tmp.first;
                    tmp.second-=2;
                    i++;
                }
                if(tmp.second==1){
                    ans[i] = tmp.first;
                    ans[n-1-i] = one;
                    i++;
                    one = -1;
                    tmp.second--;
                }
            }
        }
    }
    if(one!=-1){
        if(one==0){
            // cout<<"wtfff"<<endl;
        }
        else{
            ans[i] = one;
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