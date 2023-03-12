// link to ques : https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

bool isBipartiteConnected(vector<vector<int>>& graph,int start,vector<int> &v){
    queue<int> q;
    q.push(start);
    v[start] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<graph[cur].size();i++){
            if(v[graph[cur][i]]==0){
                v[graph[cur][i]] = 3 - v[cur];
                q.push(graph[cur][i]);
            }
            else if(v[graph[cur][i]]==v[cur]){
                return false;
            }
        }
    }
    return true;
}

bool visited(vector<int> v,int &k){
    for(int i = 0;i<v.size();i++){
        if(v[i]==0){
            k = i;
            return false;
        }
    }
    k = -1;
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> v(graph.size(),0);
    int k = 0;
    while(!visited(v,k)){
        if(!isBipartiteConnected(graph,k,v)){
            return false;
        }
    }
    return true;
}

int main()
{
    
    return 0;
}