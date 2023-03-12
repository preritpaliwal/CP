#include <bits/stdc++.h>
using namespace std;

int t[102][102][102];
int solve(string &A,int B,int l,int r){
    int len = r-l+1;
    if(B>len){
        return 1e9;
    }
    if(t[l][r][B]!=-1){
        return t[l][r][B];
    }
    if(B==1){
        int wh = 0,bl = 0;
        for(int i = l;i<=r;i++){
            if(A[i]=='W'){
                wh++;
            }
            else{
                bl++;
            }
        }
        t[l][r][B] = bl*wh;
        return bl*wh;
    }
    int ans = 1e9;
    for(int i = l;i<r;i++){
        for(int j = 1;j<B;j++){
            ans = min(ans,solve(A,j,l,i)+solve(A,B-j,i+1,r));
        }
    }
    t[l][r][B] = ans;
    return ans;
}
int arrange(string A, int B) {
    int n = A.size();
    memset(t,-1,sizeof(t));
    solve(A,B,0,n-1);
    for(int k = 0;k<=B;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<t[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n_______________-----------_______________\n";
    }
    return t[0][n-1][B];
}

int main(){
    string s = "WBBWWWBWWWWWWWWBWWWWBBWWWWWBBWWWWWWWBWBW";
    int n = 20;
    cout<<arrange(s,n)<<endl;;
}