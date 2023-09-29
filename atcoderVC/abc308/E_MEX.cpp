#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll mex(int i,int j,int k){
    for(int a=0;a<4;a++){
        if(a!=i && a!=j && a!=k)return a;
    }
    return 3;
}

int main(){
    ll n;cin>>n;vector<ll> a(n);for(ll &i:a)cin>>i;
    string s;cin>>s;
    // vector<ll> smex[3];
    // for(ll i=0;i<n;i++){
    //     if(s[i]=='X')smex[2].push_back(i);
    //     else if(s[i]=='E')smex[1].push_back(i);
    //     else if(s[i]=='M')smex[0].push_back(i);
    // }
    // vector<vector<ll>> xinfo(smex[2].size()+1,vector<ll> (3,0));
    // for(ll i=0;i<smex[2].size();i++)xinfo[i][a[smex[2][i]]]++;
    // for(ll i=(ll)xinfo.size()-2;i>=0;i--)for(ll j=0;j<3;j++)xinfo[i][j]+=xinfo[i+1][j];
    // vector<vector<ll>> einfo(smex[1].size()+1,vector<ll> (6,0));
    // for(ll i=0;i<smex[1].size();i++){
    //     ll idx=upper_bound(smex[2].begin(),smex[2].end(),smex[1][i])-smex[2].begin();
    //     for(ll j=0;j<3;j++){
    //         ll x=min(a[smex[1][i]],j),y=max(a[smex[1][i]],j);
    //         if(x==y){
    //             if(x==0)einfo[i][0]=xinfo[idx][0];
    //             if(x==1)einfo[i][3]=xinfo[idx][1];
    //             if(x==2)einfo[i][5]=xinfo[idx][2];
    //         }
    //         else if(x==0){
    //             if(y==1)einfo[i][1]=xinfo[idx][j];
    //             else einfo[i][2]=xinfo[idx][j];
    //         }
    //         else einfo[i][4]=xinfo[idx][j];
    //     }
    // }
    // for(ll i=(ll)smex[1].size()-2;i>=0;i--)for(int j=0;j<6;j++)einfo[i][j]+=einfo[i+1][j];
    // ll ans=0;
    // for(int i=0;i<smex[0].size();i++){
    //     ll idx=upper_bound(smex[1].begin(),smex[1].end(),smex[0][i])-smex[1].begin();
    //     if(a[smex[0][i]]==2)ans+=(einfo[idx][0]+einfo[idx][2])+3*(einfo[idx][1]);
    //     else if(a[smex[0][i]]==1)ans+=2*(einfo[idx][0]+einfo[idx][1])+3*(einfo[idx][2]);
    //     else ans+=(einfo[idx][0]+einfo[idx][2]+einfo[idx][5])+2*(einfo[idx][1]+einfo[idx][3])+3*(einfo[idx][4]);
    // }
    // cout<<ans<<endl;
    vector<vector<ll>> m(n,vector<ll> (3,0)),x(n,vector<ll> (3,0));
    for(int i=0;i<n;i++){
        if(s[i]=='M'){
            m[i][a[i]]++;
        }
        if(s[n-1-i]=='X'){
            x[n-1-i][a[n-i-1]]++;
        }
        if(i!=0){
            for(int j=0;j<3;j++){
                m[i][j]+=m[i-1][j];
                x[n-i-1][j]+=x[n-i][j];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<n-1;i++){
        if(s[i]=='E'){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    ans+=mex(j,k,a[i])*(m[i][j]*x[i][k]);
                }
            }
        }
    }
    cout<<ans<<endl;
}