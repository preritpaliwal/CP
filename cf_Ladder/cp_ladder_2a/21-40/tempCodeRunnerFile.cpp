// link to ques : https://codeforces.com/problemset/problem/230/A

#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> a,vector<int> b){
    return a[0]<=v[0];
}
int main()
{
    int s,n,a;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> t;
        for(int j = 0;j<2;j++){
            cin>>a;
            t.push_back(a);
        }
        v.push_back(t);
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0;i<n;i++){
        if(s>v[i][0]){
            s+=v[i][1];
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}