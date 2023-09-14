#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
vector<vector<int>> dp[3];
map<char,int> mp;
map<int,int> win;
map<int,char> back;

void solve(){
    cin>>n>>k;
    cin>>s;
    // cout<<n<<k<<s<<endl;
    for(int c = 0;c<3;c++){
        dp[c].clear();
        dp[c].resize(n+1, vector<int> (k+1,0));
        for(int k_ = 0;k_<k+1;k_++){
            dp[c][0][k_] = 0;
        }
        for(int q = 1;q<n+1;q++){
            dp[c][q][0] = dp[c][q-1][0] + (win[mp[s[q-1]]]==c?1:0);
        }
    }
    for(int k_ = 1;k_<k+1; k_++ ){
        for(int n_ = 1;n_<n+1;n_++){
            for(int c = 0;c<3;c++){
                int tmp = 0;
                for(int c_ = 0;c_<3;c_++){
                    tmp = max(tmp,dp[c_][n_-1][k_ - (c!=c_?1:0)] + (win[mp[s[n_-1]]]==c_?1:0));
                }
                dp[c][n_][k_] = tmp;
            }
        }
    }
    for(int c = 0;c<3;c++){
        cout<<"\n##########\n";
        for(int n_ = 0;n_<=n;n_++){
            for(int k_ = 0;k_<=k;k_++){
                cout<<dp[c][n_][k_]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n\n-----------\n\n";
    }
    int ans = 0;
    int cf = -1;
    for(int c = 0;c<3;c++){
        if(ans<dp[c][n][k]){
            ans = dp[c][n][k];
            cf = c;
        }
    }
    cout<<ans<<endl;
    string anss;
    for(int i = n;i>0;i--){
        ans += back[cf];
        if(cf==0){
            if(dp[0][n-1][0]==dp[0][n][0])
        }
    }
    return;
}

int main(){
    mp['P']=0;
    mp['R']=1;
    mp['S']=2;
    win[0] = 2;
    win[1] = 0;
    win[2] = 1; 
    back[0] = 'P';
    back[1] = 'R';
    back[2] = 'S';
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}