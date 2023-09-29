#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;cin>>n>>m;
    vector<string> v(n);
    for(string &s:v)cin>>s;
    for(int i=0;i<n-8;i++){
        for(int j=0;j<m-8;j++){
            bool sq1=true,sq2=true;
            for(int x=0;x<4;x++){
                for(int y=0;y<4;y++){
                    if(y==3 || x==3){
                        if(v[i+x][j+y]=='#')sq1=false;
                    }
                    else{
                        if(v[i+x][j+y]=='.')sq1=false;
                    }
                    if(x==0||y==0){
                        if(v[i+5+x][j+5+y]=='#')sq2=false;
                    }
                    else{
                        if(v[i+5+x][j+5+y]=='.')sq2=false;
                    }
                }
            }
            if(sq1&&sq2){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
    return 0;
}