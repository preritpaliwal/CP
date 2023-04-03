#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        // cout<<i<<endl;
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // // cout<<"1"<<endl;
    // vector<int> dist(n,1e9);
    // dist[0] = 0;
    // queue<int> q;
    // q.push(0);
    // while(!q.empty()){
    //     int cur = q.front();
    //     q.pop();
    //     for(int i = 0;i<adj[cur].size();i++){
    //         if(dist[adj[cur][i]] > dist[cur]+1){
    //             dist[adj[cur][i]] = dist[cur]+1;
    //             q.push(adj[cur][i]);
    //         }
    //     }
    // }
    // // cout<<"2"<<endl;
    // int maxDist = 0;
    // int i_maxDist = 0;
    // for(int i = 0;i<n;i++){
    //     if(maxDist<dist[i]){
    //         maxDist = dist[i];
    //         i_maxDist = i;
    //     }
    //     dist[i] = 1e9;
    // }
    // // cout<<"1"<<endl;
    // cout<<"i_maxDist = "<<i_maxDist<<endl;
    // dist[i_maxDist] = 0;
    // q.push(i_maxDist);
    // while(!q.empty()){
    //     int cur = q.front();
    //     q.pop();
    //     for(int i = 0;i<adj[cur].size();i++){
    //         if(dist[adj[cur][i]] > dist[cur]+1){
    //             dist[adj[cur][i]] = dist[cur]+1;
    //             q.push(adj[cur][i]);
    //         }
    //     }
    // }
    // // cout<<"2"<<endl;

    // maxDist = 0;
    // for(int i = 0;i<n;i++){
    //     maxDist = max(maxDist,dist[i]);
    // }
    // set<int> dia;
    // dia.insert(i_maxDist);
    // for(int i = 0;i<n;i++){
    //     if(dist[i]==maxDist){
    //         dia.insert(i);
    //     }
    // }
    
    // cout<<"max Dist: "<<maxDist<<"\nNodes:  "<<endl;
    // for(int i:dia){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // vector<int> mark(n,n);
    // queue<int> q;
    // set<int> leaf;
    // q.push(0);
    // while(!q.empty()){
    //     int cur = q.front();
    //     q.pop();
    //     for(int i:adj[cur]){
    //         mark[i] = mark[cur]-1;
    //         if(adj[i].size()==1){
    //             leaf.insert(i);
    //         }
    //         else{
    //             q.push(i);
    //         }
    //     }
    // }
    // for(int l:leaf){
    //     mark[l] = 0;
    //     q.push(l);
    //     while(!q.empty()){
    //         int cur = q.front();
    //         q.pop();
    //         for(int i:adj[cur]){
    //             if(mark[i]>mark[cur]+1){
    //                 mark[i] = mark[cur]+1;
    //                 q.push(i);
    //             }
    //         }
    //     }
    // }
    // map<int,int> mp;
    // for(int i = 0;i<n;i++){
    //     mp[mark[i]]++;
    // }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}