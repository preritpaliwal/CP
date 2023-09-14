#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    for(int i1=0;i1<t;i1++){
        int n;cin>>n;int cnt=0;
        int a[n+2][n+2]={};int b[n+2][n+2]={};int c[n+2][n+2]={};
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<n;j++){
                a[i+1][j+1]=s[j]-'0';
            }
        }
        for(int i=1;i<=n;i++){
            b[i][0]=b[i-1][1];
            b[i][n+1]=b[i-1][n];
            for(int j=1;j<=n;j++){
                b[i][j]+=b[i-1][j-1]+b[i-1][j+1];
                if(i>=2){
                    b[i][j]+=b[i-2][j];
                }
                if(c[i-1][j]==1){
                    b[i][j]++;
                }
                b[i][j]=b[i][j]%2;
                if((a[i][j]+b[i][j])==1){
                    cnt++;c[i][j]=1;b[i][j]++;b[i][j]=b[i][j]%2;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}