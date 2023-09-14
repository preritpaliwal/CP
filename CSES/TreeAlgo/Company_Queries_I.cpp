#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> par;
vector<vector<int>> parList;

void process(int nn, int k){
    if(k==0 || nn==-1){
        cout<<nn<<endl;
        return;
    }

    int tmp = k;
    int entryNo = 0;
    int cnt = 0;
    int two = 1;
    while(tmp!=0){
        if(tmp&1){
            entryNo = cnt;
        }
        tmp>>=1;
        cnt++;
        if(tmp!=0){
            two<<=1;
        }
    }
    if((int)parList[nn].size()>entryNo){
        process(parList[nn][entryNo],k-two);
    }
    else{
        cout<<"-1"<<endl;
        return;
    }
}

int main(){
    int q;
    cin>>n>>q;
    par.resize(n+1,-1);
    parList.resize(n+1);
    for(int i=1;i<=n;i++){
        if(i!=1){
            cin>>par[i];
        }
        parList[i].push_back(par[i]);
    }
    for(int i = 2;i<=n;i++){
        int entryNo = 0;
        while(parList[i][entryNo]!=-1){
            int cur = -1;
            if((int)parList[parList[i][entryNo]].size()>entryNo){
                cur = parList[parList[i][entryNo]][entryNo];
            }
            parList[i].push_back(cur);
            entryNo++;
        }
    }
    while(q--){
        int nn,k;
        cin>>nn>>k;
        // cerr<<nn<<" "<<k<<endl;
        process(nn,k);
    }
}