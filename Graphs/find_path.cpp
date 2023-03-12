// link to ques : https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    stack<int> s;
    vector<int> v(n,0);
    s.push(start);
    if(start==end){
        return true;
    }
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        v[cur] = 1;
        for(int i = 0;i<edges.size();i++){
            if(edges[i][0]==cur){
                if(v[edges[i][1]]==0){
                    if(edges[i][1]==end){
                        return true;
                    }
                    s.push(edges[i][1]);
                }
            }
            else if(edges[i][1]==cur){
                if(v[edges[i][0]]==0){
                    if(edges[i][0]==end){
                        return true;
                    }
                    s.push(edges[i][0]);
                }
            }
        }
    }
    return false;
}

int main()
{
    
    return 0;
}