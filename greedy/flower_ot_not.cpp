// link to ques : https://leetcode.com/problems/can-place-flowers/submissions/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& f, int n) {
    vector<int> v;
    v.push_back(-2);
    for(int i = 0;i<f.size();i++){
        if(f[i]==1){
            v.push_back(i);
        }
    }
    v.push_back(f.size()+1);
    int k = 0;
    for(int i = 0;i<v.size()-1;i++){
        int diff = v[i+1]-v[i];
        if(diff>3){
            k += ((diff/2)-1);
        }
        
    }
    bool t= false;
    if(n<=k){
        t = true;
    }
    return t;
}

int main()
{
    
    return 0;
}