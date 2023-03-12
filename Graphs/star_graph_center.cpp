// link to ques : https://leetcode.com/problems/find-center-of-star-graph/

#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> v(edges.size()+1,0);
        for(int i = 0;i<edges.size();i++){
            v[edges[i][0]-1]++;
            v[edges[i][1]-1]++;
        }
        for(int i = 0;i<v.size();i++){
            if(v[i]==(edges.size())){
                return i+1;
            }
        }
        return 0;
    }

int main()
{
    
    return 0;
}