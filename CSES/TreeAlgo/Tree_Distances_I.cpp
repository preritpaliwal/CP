#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> maxDists;
vector<int> indp[2];
vector<int> outdp;

void maxDistInSub(int nn,int pp){
    indp[0][nn] = 0;
    indp[1][nn] = 0;
    for(int ch:adj[nn]){
        if(ch!=pp){
            maxDistInSub(ch,nn);
            if(indp[0][nn]<1+indp[0][ch]){
                indp[1][nn] = indp[0][nn];
                indp[0][nn] = 1+indp[0][ch];
            }
            else if(indp[1][nn]<1+indp[0][ch]){
                indp[1][nn] = 1+indp[0][ch];
            }
        }
    }
}

void maxDistOutSub(int nn,int pp){
    // cerr<<nn<<" "<<pp<<endl;
    outdp[nn] = 0;
    if(pp!=0){
        outdp[nn] = 1+outdp[pp];
        if(indp[0][pp]==1+indp[0][nn]){
            outdp[nn] = max(outdp[nn],1+indp[1][pp]);
        }
        else{
            outdp[nn] = max(outdp[nn],1+indp[0][pp]);
        }
    }
    for(int ch:adj[nn]){
        if(ch!=pp){
            maxDistOutSub(ch,nn);
        }
    }
    maxDists[nn] = max(outdp[nn],indp[0][nn]);
}

int main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    indp[0].resize(n+1,-1);
    indp[1].resize(n+1,-1);
    outdp.resize(n+1,-1);
    maxDists.resize(n+1,-1);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxDistInSub(1,0);
    maxDistOutSub(1,0);
    for(int i=1;i<=n;i++){
        cout<<maxDists[i]<<" ";
        // cerr<<indp[0][i]<<" ";
    }
    cout<<endl;
}