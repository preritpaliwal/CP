// link to ques : https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

bool bsv(vector<vector<int>> m,int i,int j,int val){
    int u = i;
    int d = m.size()-1;
    while(d>=u){
        int mid = (u+d)/2;
        if(m[mid][j]==val){
            return true;
        }
        else if(m[mid][j]>val){
            d = mid-1;
        }
        else{
            u = mid+1;
        }
    }
    return false;
}

bool rightcornersearch(vector<vector<int>> m,int i,int j,int val){
    if(m[i][j]==val){
        return true;
    }
    if(m[i][j]<val){
        if(bsv(m,i,j,val)){
            return true;
        }
        return rightcornersearch(m,i,j-1,val);
    }
    
}

bool searchMatrix(vector<vector<int>>& m, int target) {
    return rightcornersearch(m,0,m[0].size()-1,target);
}

int main()
{
    
    return 0;
}