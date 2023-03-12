// link to ques : https://leetcode.com/problems/find-the-town-judge/

#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        int k = 0;
        int a[n];
        int b[n] ; 
        for(int i = 0;i<n;i++){
            a[i] = 0;
            b[i] = 0;
        }
        for(int i = 0;i<trust.size();i++){
            a[trust[i][1]-1]++;
            b[trust[i][0]-1]++;
        }
        int max = 0,i_m = -1;
        for(int i = 0;i<n;i++){
            if(max<a[i]){
                max = a[i];
                i_m=i;
            }
        }
        if(max==n-1){
            if(!b[i_m])
            return i_m+1;
            
        }

            return -1;
    }

int main()
{
    
    return 0;
}