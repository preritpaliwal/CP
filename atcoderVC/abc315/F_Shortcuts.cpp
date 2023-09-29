#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<pair<int,int>> p;
vector<vector<double>> dp;
double dist(int i,int j){
    return sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second));
}
int main(){
    int n;cin>>n;p.resize(n);for(auto &i:p)cin>>i.first>>i.second;
    dp.resize(n,vector<double> (32,1e9));
    for(int i=0;i<32;i++)dp[0][i]=0;
    for(int i=1;i<n;i++){
        for(int pen=0;pen<32;pen++){
            int j=i-pen-1;
            if(j<0)break;
            for(int k=pen;k<32;k++){
                dp[i][k]=min(dp[i][k],dist(i,j)+dp[j][k-pen]);
            }
        }
    }
    double d=dp[n-1][0];
    for(int i=0;i<32;i++){
        d=min(d,dp[n-1][i]+pow(2,i-1));
    }
    cout<<setprecision(10)<<d<<endl;
    return 0;
}