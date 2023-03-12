// link to ques : 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fo(i,n) for(int i = 0;i<n;i++)

void make_set(vector<int> &p,int id){
    p[id] = -1;
}

int find(vector<int> &p,int id){
    if(p[id]<0){
        return id;
    }
    return p[id] = find(p,p[id]);
}

void union1(vector<int> &p,int id1,int id2){
    int pid1 = find(p,id1);
    int pid2 = find(p,id2);
    if(pid1==pid2){
        return;
    }

    if(-p[pid1]>-p[pid2]){
        p[pid1] += p[pid2];
        p[pid2] = pid1;
    }
    else{
        p[pid2] +=p[pid1];
        p[pid1] = pid2;
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<int> p(grid.size()*grid[0].size());
    vector<pair<int,int>> dir{mp(1,0),mp(0,1),mp(-1,0),mp(0,-1)};
    fo(i,grid.size()){
        fo(j,grid[i].size()){
            make_set(p,i*(grid[i].size())+j);
        }
    }
    fo(i,grid.size()){
        fo(j,grid[i].size()){
            if(grid[i][j] == '1'){
                for(pair<int,int> p : dir){
                    if(i+p.f>=0 && i+p.f <grid.size() && j+p.s>=0 && j+p.s < grid[i].size() && grid[i+p.f][j+p.s]=='1'){
                        union1(p,i*grid[i].size()+j,(i+ p.f)*grid[i].size() + j+p.s);
                    }
                }
            }
        }
    }
    int k = 0;
    for(int i = 0;i<grid.size()*grid[0].size();i++){
        if(p[i]<0){
            k++;
        }
    }

    return k;
}

int main()
{
    
    return 0;
}