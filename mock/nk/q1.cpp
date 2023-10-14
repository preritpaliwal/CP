#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string ShortestCommonSupersequence(string &s1, string &s2) {
    // write code here.
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    vector<vector<pair<int,int>>> ans(n+1,vector<pair<int,int>> (m+1,{-1,-1}));
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
        if(i!=0){
            ans[i][0]={i-1,0};
        }
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
        if(j!=0){
            ans[0][j]={0,j-1};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans[i][j]={i-1,j-1};
            }
            else{
                if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j]=1+dp[i-1][j];
                    ans[i][j]={i-1,j};
                }
                else{
                    dp[i][j]=1+dp[i][j-1];
                    ans[i][j]={i,j-1};
                }
            }
        }
    }
    string ret;
    int ni=n,nj=m;
    while(true){
        auto tmp=ans[ni][nj];
        if(ni==tmp.first){
            ret+=s2[tmp.second];
        }
        else{
            ret+=s1[tmp.first];
        }
        ni=tmp.first;
        nj=tmp.second;
        if(ni==-1 && nj==-1){
            break;
        }
    }
    ret.pop_back();
    reverse(ret.begin(),ret.end());
    return ret;
}























void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j])i++, j++;
        else j++;
    }
    if (i != x.size())f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j])i++, j++;
        else j++;
    }
    if (i != y.size())f = 0;
    cout << f << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}