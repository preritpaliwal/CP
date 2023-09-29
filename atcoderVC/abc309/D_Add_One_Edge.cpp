#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n1,n2,m;cin>>n1>>n2>>m;
    vector<vector<int>> adj(n1+n2+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);
    }
    vector<int> dist(n1+n2+1,-1);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int ch:adj[cur]){
            if(dist[ch]==-1){
                dist[ch]=dist[cur]+1;
                q.push(ch);
            }
        }
    }
    q.push(n1+n2);
    dist[n1+n2]=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int ch:adj[cur]){
            if(dist[ch]==-1){
                dist[ch]=dist[cur]+1;
                q.push(ch);
            }
        }
    }
    int max2=0,max1=0;
    for(int i=1;i<=n1+n2;i++){
        if(i<=n1){
            max1=max(max1,dist[i]);
        }
        else{
            max2=max(max2,dist[i]);
        }
    }
    cout<<max1+max2+1<<endl;
    return 0;
}