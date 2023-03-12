#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(auto &x:a){
            cin>>x;
        }

        for(auto &x:b){
            cin>>x;
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long ans = 0;
        if(m>=n){
            for(int i = 0;i<n;i++){
                ans += 1LL*b[m-1-i];
            }
        }
        else{
            for(auto i:b){
                ans += i*1LL;
            }
            // cout<<ans<<" :here: ";
            for(int i = 0;i<n-m;i++){
                ans += 1LL*a[n-i-1];
            }
        }
        cout<<ans<<endl;
    }
}