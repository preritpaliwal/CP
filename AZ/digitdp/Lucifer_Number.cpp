#include <bits/stdc++.h>
using namespace std;

string l,r;
bool pr[50];
int dp[10][2][2][50][50];
int n;

int solve(int nn,int tl,int tr,int eval,int oval){
    if(nn==n){
        if(eval>oval)if(pr[eval-oval])return 1;
        return 0;
    }
    if(dp[nn][tl][tr][eval][oval]!=-1)return dp[nn][tl][tr][eval][oval];
    int lo=0,hi=9;
    if(tl==1)lo=l[nn]-'0';
    if(tr==1)hi=r[nn]-'0';
    int ans=0;
    for(int i=lo;i<=hi;i++){
        int ntl=tl,ntr=tr,neval=eval,noval=oval;
        if(i!=lo)ntl=0;
        if(i!=hi)ntr=0;
        if((n-nn)%2==1){
            noval+=i;
        }
        else {
            neval+=i;
        }
        ans+=solve(nn+1,ntl,ntr,neval,noval);
    }
    return dp[nn][tl][tr][eval][oval]=ans;
}

int main(){
    memset(pr,true,sizeof(pr));
    pr[0]=false;pr[1]=false;
    for(int i=2;i<50;i++){
        if(pr[i]){
            for(int j=i*i;j<50;j+=i)pr[j]=false;
        }
    }
    // for(int i=0;i<50;i++){
    //     cerr<<i<<" "<<pr[i]<<endl;
    // }
    int t=1;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>l>>r;
        n=r.size();
        int dif=(int)r.size()-(int)l.size();
        string tmp;
        while(dif--){
            tmp+='0';
        }
        l=tmp+l;
        cout<<solve(0,1,1,0,0)<<endl;
    }
}