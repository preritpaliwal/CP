// link to blog : https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include <bits/stdc++.h>
using namespace std;

void solve(int row,int col,int n,vector<vector<int>> &v,int &color){
    if(row<0 || row>=n || col<0 || col>= n || v[row][col]!=-1){
        return;
    }
    v[row][col] = color++;
    int dir[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
    for(int i = 0;i<8;i++){
        solve(row+dir[i][0],col+dir[i][1],n,v,color);
    }
}

int main(){
    int n = 6,color = 0;
    vector<vector<int>> v(n,vector<int> (n,-1));
    solve(0,0,n,v,color);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}