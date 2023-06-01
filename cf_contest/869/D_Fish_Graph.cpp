#include <bits/stdc++.h>
using namespace std;

bool cycleDetected(vector<vector<int>> &v, int n,vector<int> &parent, int end){
    cerr<<"here\n"<<n<<" "<<end<<endl;
    for(int i = 1;i<parent.size();i++){
        cerr<<parent[i]<<" ";
    }
    cerr<<endl;
    set<int> inCycle;
    int extraEdges = 0;
    int curNode = n;
    int uniqueNode = -1;
    int noEdges = 0;
    while(curNode != parent[end]){
        if(curNode==0){
            return false;
        }
        inCycle.insert(curNode);
        curNode = parent[curNode];
    }
    // cerr<<"incycle: ";
    // for(auto i:inCycle){
    //     cerr<<i<<" ";
    // }
    // cerr<<endl;
    curNode = n;
    while(curNode != parent[end]){
        if(curNode==0){
            return false;
        }
        int curExtraEdges = 0;
        // cerr<<curNode<<" ";
        for(int i = 0;i<v[curNode].size();i++){
            // cerr<<v[curNode][i]<<" ";
            if(inCycle.find(v[curNode][i])==inCycle.end()){
                curExtraEdges++;
            }
        }
        // cerr<<endl;
        if(curExtraEdges==2){
            uniqueNode = curNode;
        }
        extraEdges+=curExtraEdges;
        curNode = parent[curNode];
        noEdges++;
    }
    // cout<<"works?"<<endl;
    cerr<<extraEdges<<endl;
    cerr<<uniqueNode<<endl;
    if( uniqueNode!=-1){
        cout<<"YES\n";
        cout<<noEdges+2<<endl;
        int curNode = n;
        int prevNode = end;
        while(curNode!=parent[end]){
            cout<<curNode<<" "<<prevNode<<endl;
            if(curNode==uniqueNode){
                for(int i = 0;i<v[curNode].size();i++){
                    if(inCycle.find(v[curNode][i])==inCycle.end()){
                        cout<<v[curNode][i]<<" "<<curNode<<endl;
                    }
                }
            }
            prevNode = curNode;
            curNode = parent[curNode];
        }
        return true;
    }
    return false;
}

bool dfs(vector<vector<int>> &v, int n, vector<int> &parent){
    // cerr<<n<<endl;
    bool ret = false;
    for(int i = 0;i<v[n].size();i++){
        int curNode = v[n][i];
        if(parent[curNode]==-1){
            // cerr<<"curNode: "<<curNode<<endl;
            parent[curNode] = n;
            ret |= dfs(v,curNode,parent);
            if(ret){
                return ret;
            }
        }
        else if(parent[n]==curNode){
            continue;
        }
        else{
            if(cycleDetected(v,n,parent,curNode)){
                return true;
            }
        }
    }
    return ret;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        cerr<<i<<" : ";
        for(int j = 0;j<v[i].size();j++){
            cerr<<v[i][j]<<" ";
        }
        cerr<<endl;;
    }
    vector<int> parent(n+1,-1);
    bool ret = false;
    for(int i = 1;i<=n;i++){
        if(parent[i]==-1){
            parent[i] = 0;
            ret |= dfs(v,i,parent);
            if(ret){
                break;
            }
        }
    }

    if(!ret){
        cout<<"NO\n";
    }


    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}