#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir{{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m,si,sj,ei,ej,sdir;

bool isEndReachable(int i1,int j1,int i2,int j2,int curDir){
    // cerr<<i1<<j1<<" "<<i2<<j2<<" "<<curDir<<endl;
    int k = (i2-i1)/dir[curDir].first;
    // cerr<<k<<endl;
    return j1 + k*dir[curDir].second == j2 && k>=0;
}

void solve(){
    string direction;
    cin>>n>>m>>si>>sj>>ei>>ej>>direction;
    int curDir = -1;
    if(direction=="DR"){
        curDir = 0;
    }
    else if(direction=="DL"){
        curDir = 1;
    }
    else if(direction=="UR"){
        curDir = 2;
    }
    else if(direction=="UL"){
        curDir = 3;
    }
    sdir = curDir;
    int nBounces = 0;
    int curi=si,curj=sj;
    while(true){
        // break if end reachable
        if(isEndReachable(curi,curj,ei,ej,curDir)){
            cout<<nBounces<<endl;
            return;
        }
        // update contact point and dir, increment bounce
        int k = 0;
        int newDir = -1;
        if(curDir==0){
            k = min(n-curi,m-curj);
            if(n-curi==m-curj){
                newDir = 3;
            }
            else if(n-curi>m-curj){
                newDir = 1;
            }
            else{
                newDir = 2;
            }
        }
        else if(curDir==1){
            k = min(n-curi,curj-1);
            if(n-curi == curj-1){
                newDir = 2;
            }
            else if(n-curi>curj-1){
                newDir = 0;
            }
            else{
                newDir = 3;
            }

        }
        else if(curDir==2){
            k = min(curi-1,m-curj);
            if(curi-1==m-curj){
                newDir = 1;
            }
            else if(curi-1>m-curj){
                newDir = 3;
            }
            else{
                newDir = 0;
            }
        }
        else{
            k = min(curi-1,curj-1);
            if(curi-1==curj-1){
                newDir = 0;
            }
            else if(curi-1>curj-1){
                newDir = 2;
            }
            else{
                newDir = 1;
            }
        }
        curi += k*dir[curDir].first;
        curj += k*dir[curDir].second;
        nBounces++;
        curDir = newDir;
        // break if initial state is reached
        if(isEndReachable(curi,curj,si,sj,curDir) && sdir==curDir){
            break;
        }
        if(nBounces==1){
            si = curi;
            sj = curj;
            sdir = curDir;
        }
    }
    cout<<-1<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve(); 
        // cerr<<"-----------"<<endl;
    }
}