#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int m;cin>>m;string s[3];cin>>s[0]>>s[1]>>s[2];
    ll ans=1e9,n=s[0].size();
    for(int i=0;i<3*n;i++){
        for(int j=0;j<3*n;j++){
            if(i==j)continue;
            for(int k=0;k<3*n;k++){
                if(i==k || j==k)continue;
                if(s[0][i%n]==s[1][j%n] && s[1][j%n]==s[2][k%n]){
                    ans=min(ans,0ll+max(i,max(j,k)));
                }
            }
        }
    }
    cout<<((ans>3*n+1)?-1:ans)<<endl;
    return  0;
}