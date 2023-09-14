/*
// GREEDY APPROACH, BUT FAILS and makes sense for it to fail as well


#include <bits/stdc++.h>
using namespace std;
using ll=long long;


bool comp(const pair<ll,ll> &a,const pair<ll,ll>  &b){
    return a.first<b.first;
}

int main(){
    ll n,x;cin>>n>>x;
    vector<ll> w(n),taken(n,0);
    for(ll i=0;i<n;i++){cin>>w[i];}
    ll ans=0;
    while(true){
        vector<pair<ll,ll>> ws;ws.push_back({0,-1});
        for(int i=0;i<n;i++){
            if(taken[i]==0){
                vector<pair<ll,ll>> tmp,tmp2(ws.size()*2);
                for(int j=0;j<ws.size();j++){
                    tmp.push_back({ws[j].first+w[i],i});
                }
                tmp2.resize(set_union(ws.begin(),ws.end(),tmp.begin(),tmp.end(),tmp2.begin(),comp)-tmp2.begin());
                ws=tmp2;
            }
        }
        pair<ll,ll> qwe={x,0};
        int idx=upper_bound(ws.begin(),ws.end(),qwe,comp)-ws.begin()-1;
        if(idx==0){
            break;
        }
        ans++;
        while(idx!=0){
            taken[ws[idx].second]=1;
            pair<ll,ll> qwe={ws[idx].first-w[ws[idx].second],0};
            idx=lower_bound(ws.begin(),ws.end(),qwe,comp)-ws.begin();
        }
    }
    cout<<ans<<endl;
}
*/

/*
// RECURSIVE CODE that cant be memoized


#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,x;
vector<ll> w;
ll solve(int k,int used,vector<ll> bins){
    if(k<0)return 0;
    if(used>=n)return 1e9;
    ll ans=1e9;
    for(int i=0;i<=used;i++){
        if(i==used){
            bins[i]-=w[k];
            ans=min(ans, 1+solve(k-1,used+1,bins));
            bins[i]+=w[k];
        }
        else{
            if(bins[i]>=w[k]){
                bins[i]-=w[k];
                ans=min(ans,solve(k-1,used,bins));
                bins[i]+=w[k];
            }
        }
    }
    return ans;
}

int main(){
    cin>>n>>x;
    w.resize(n);
    for(ll i=0;i<n;i++)cin>>w[i];
    vector<ll> bins(n,x);

    cout<<solve(n-1,0,bins)<<endl;
}


*/

/*
// TRYING WITH BITMASK DP (ITERATIVE WITH SAVING REM)

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,x;
vector<ll> w;
vector<ll> rem;
vector<ll> dp;

int main(){
    cin>>n>>x;
    w.resize(n);for(ll &i:w)cin>>i;
    dp.resize(1<<n,1+n);
    rem.resize(1<<n,x);
    dp[0]=1;
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                int submask=mask^(1<<i);
                if(rem[submask]>=w[i]){
                    if(dp[submask]<dp[mask]){
                        dp[mask]=dp[submask];
                        rem[mask]=rem[submask]-w[i];
                    }
                    else if(dp[submask]==dp[mask]){
                        rem[mask]=max(rem[submask]-w[i],rem[mask]);
                    }
                }
                else{
                    if(dp[mask]>1+dp[submask]){
                        dp[mask]=1+dp[submask];
                        rem[mask]=x-w[i];
                    }
                    else if(dp[mask]==1+dp[submask]){
                        rem[mask]=max(rem[mask],x-w[i]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}

*/

// TRYING WITH RECURSIVE BITMASK DP

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,x;
vector<int> w,dp;
vector<ll> sum;

int solve(int mask){
    if(dp[mask]!=-1)return dp[mask];
    if(sum[mask]<=x)return dp[mask]=1;
    int ans=1e9;
    int tmpmask=mask&(mask-1);
    int here=tmpmask^mask;
    for(int submask=tmpmask;submask>0;submask=(submask-1)&tmpmask){
        int maskhere=(mask^submask)|here;
        if(sum[maskhere]<=x){
            ans=min(ans,1+solve(submask));
        }
    }
    return dp[mask]=ans;
}

int main(){
    cin>>n>>x;
    w.resize(n);for(int &i:w)cin>>i;
    dp.resize(1<<n,-1);
    sum.resize(1<<n,0);
    for(int mask=0;mask<(1<<n);mask++){
        for(int j=0;j<n;j++){
            if(mask&(1<<j))sum[mask]+=w[j];
        }
    }
    dp[0]=0;
    // cout<<solve((1<<n)-1);
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                int submask=mask^(1<<i);
                // shows that to not iterate on all the submasks you will need to keep the remaining array.
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}