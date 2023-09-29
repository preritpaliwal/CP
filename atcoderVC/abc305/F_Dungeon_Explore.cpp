#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;cin>>n>>m;
    vector<int> vis(n+1,0);
    vis[1]=1;
    stack<int> s;s.push(1);
    for(int i=0;i<2*n;i++){
        int k;cin>>k;vector<int> cur(k);for(int i=0;i<k;i++){cin>>cur[i];}
        int allvis=1;
        for(int i:cur){
            if(vis[i]==0){
                allvis=0;
                vis[i]=1;
                s.push(i);
                cout<<i<<endl;
                if(i==n){
                    return 0;
                }
                break;
            }
        }
        if(allvis){
            s.pop();
            cout<<s.top()<<endl;
        }
    }
    return 0;
}