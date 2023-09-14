#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>> adj;
vector<long long> sz;
vector<long long> indp;
vector<long long> outdp;

void sumIn(long long nn,long long pp){
    indp[nn] = 0;
    sz[nn] = 1;
    for(long long ch:adj[nn]){
        if(ch!=pp){
            sumIn(ch,nn);
            indp[nn] += indp[ch]+sz[ch];
            sz[nn] += sz[ch];
        }
    }
}

void sumOut(long long nn,long long pp){
    outdp[nn] = 0;
    if(pp!=0){
        outdp[nn] = outdp[pp] + n-2*sz[nn] + indp[pp]-indp[nn];
    }
    for(long long ch:adj[nn]){
        if(ch!=pp){
            sumOut(ch,nn);
        }
    }
}

int main(){
    cin>>n;
    adj.resize(n+1);
    indp.resize(n+1,-1);
    outdp.resize(n+1,-1);
    sz.resize(n+1,-1);
    for(long long i = 0;i<n-1;i++){
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sumIn(1,0);
    sumOut(1,0);
    // for(long long i =1;i<=n;i++){
    //     cerr<<indp[i]<<" ";
    // }
    // cerr<<"\n";
    // for(long long i=1;i<=n;i++){
    //     cerr<<outdp[i]<<" ";
    // }
    // cerr<<endl;
    for(long long i = 1;i<=n;i++){
        cout<<indp[i]+outdp[i]<<" ";
    }
    cout<<endl;
}