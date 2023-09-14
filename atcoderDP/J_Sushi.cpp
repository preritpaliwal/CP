#include <bits/stdc++.h>
using namespace std;
int n;
double dp[301][301][301];
double solve(int n0,int n1,int n2,int n3){
    // cerr<<"call: "<<n0<<" "<<n1<<" "<<n2<<" "<<n3<<":"<<dp[n0][n1][n2][n3]<<endl;
    if(dp[n1][n2][n3]!=-1)return dp[n1][n2][n3];
    double ans=0;
    if(n1!=0)ans+= (solve(n0+1,n1-1,n2,n3))*(1.0*n1)/n;
    if(n2!=0)ans+= (solve(n0,n1+1,n2-1,n3))*(1.0*n2)/n;
    if(n3!=0)ans+= (solve(n0,n1,n2+1,n3-1))*(1.0*n3)/n;
    if(n0!=0)ans=(ans+1)*((1.0*n)/(n-n0));
    else ans+=1;
    // cerr<<"ret: "<<n0<<" "<<n1<<" "<<n2<<" "<<n3<<" : "<<ans<<endl;
    return dp[n1][n2][n3]=ans;
}
int main(){
    cin>>n;
    vector<int> v(4,0);
    for(int i=0;i<n;i++){int a;cin>>a;v[a]++;}
    for(int i2=0;i2<=n;i2++)for(int i3=0;i3<=n;i3++)for(int i4=0;i4<=n;i4++)dp[i2][i3][i4]=-1;
    dp[0][0][0]=0;
    cout<<setprecision(10)<<solve(v[0],v[1],v[2],v[3])<<endl;
}