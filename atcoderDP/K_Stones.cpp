#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);for(int &i:a)cin>>i;
    vector<int> dp(k+1,0);
    for(int i=0;i<=k;i++){
        int win=0,lose=0;
        for(int j=0;j<n;j++){
            if(i-a[j]>=0){
                if(dp[i-a[j]]==0){
                    lose++;
                }
                else{
                    win++;
                }
            }
        }
        if(win==n)dp[i]=0;
        else if(lose>0)dp[i]=1;
        // cerr<<dp[i]<<endl;
    }
    if(dp[k])cout<<"First";
    else cout<<"Second";
    return 0;
}