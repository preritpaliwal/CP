#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v(26,0);
    int burls = 0;
    for(int i = 0;i<n;i++){
        int inc = 0;
        if(s[i]<'a'){
            if(v[s[i]-'A']>0){
                inc++;
            }
            v[s[i]-'A']--;
        }
        else{
            if(v[s[i]-'a']<0){
                inc++;
            }
            v[s[i]-'a']++;
        }
        // cout<<i<<" "<<inc<<endl;
        if(inc==1){
            burls++;
        }
    }
    // cout<<burls<<endl<<endl;
    for(int i = 0;i<26;i++){
        // cout<<i<<" "<<v[i]<<endl;
        while(v[i]>1){
            if(k<=0){
                break;
            }
            v[i]-=2;
            burls++;
            k--;
            // cout<<"here";
        }
        while(v[i]<-1){
            if(k<=0){
                break;
            }
            v[i]+=2;
            burls++;
            // cout<<"There";
            k--;
        }
    }
    cout<<burls<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}