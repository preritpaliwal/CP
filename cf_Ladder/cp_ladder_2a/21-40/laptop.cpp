// link to ques : https://codeforces.com/problemset/problem/456/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    for(int i = 1;i<n;i++){
        if(v[i].second<v[i-1].second){
            cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
    return 0;
}