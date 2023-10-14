#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> mat(n,vector<ll> (m)), ans(n, vector<ll> (m,0));
    vector<vector<pair<ll,pair<ll,ll>>>> ro(n,vector<pair<ll,pair<ll,ll>>> (m)),co(m,vector<pair<ll,pair<ll,ll>>> (n));
    multiset<pair<ll,pair<ll,ll>>> ms;
    for(ll i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            ms.insert({mat[i][j],{i,j}});
            ro[i][j]={mat[i][j],{i,j}};
            co[j][i]={mat[i][j],{i,j}};
        }
    }
    for(int i=0;i<n;i++){
        sort(ro[i].begin(),ro[i].end());
    }
    for(int i=0;i<m;i++){
        sort(co[i].begin(),co[i].end());
    }
    for(auto &it:ms){
        ll val=it.first;
        ll curi=it.second.first;
        ll curj=it.second.second;
        cerr<<"val,curi,curj: "<<val<<" "<<curi<< " "<<curj<<endl;
        auto ridx=lower_bound(ro[curi].begin(),ro[curi].end(),it);
        auto cidx=lower_bound(co[curj].begin(),co[curj].end(),it);
        cerr<<"ridx,cidx: "<<ridx->second.first<<","<<ridx->second.second<<" "<<cidx->second.first<<","<<cidx->second.second<<endl;
        if(ridx==ro[curi].begin() && cidx==co[curj].begin()){
            ans[curi][curj]=1;
        }
        else if(ridx==ro[curi].begin()){
            cidx--;
            if(val!=cidx->first)ans[curi][curj]=1;
            ans[curi][curj]+=ans[cidx->second.first][cidx->second.second];
        }
        else if(cidx==co[curj].begin()){
            ridx--;
            if(val!=ridx->first)ans[curi][curj]=1;
            ans[curi][curj]+=ans[ridx->second.first][ridx->second.second];
        }
        else{
            ridx--;cidx--;
            cerr<<ridx->first<<" "<<cidx->first<<endl;
            if(val==ridx->first && val==cidx->first){
                ans[curi][curj]=ans[ridx->second.first][ridx->second.second];
                if(ans[ridx->second.first][ridx->second.second]!=ans[cidx->second.first][cidx->second.second]){
                    cerr<<"$$$$$$$$$$$$$$$$$$$$$\n\n\\n\n\n\n";
                }
            }
            else if(ridx->first==val){
                
            }
        }
        cerr<<"ans: "<<ans[curi][curj]<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cerr<<"\n\n\n";
}


int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}