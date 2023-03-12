// link to ques : https://codeforces.com/problemset/problem/165/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> x(n,make_pair(0,0));
    vector<pair<int,int>> y(n,make_pair(0,0));

    for(int i = 0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),comp);

    
    return 0;
}