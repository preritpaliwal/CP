// link to ques : https://codeforces.com/problemset/problem/136/A

#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        int z;
        cin>>z;
        v.push_back(make_pair(i,z));
    }

    sort(v.begin(),v.end(),compare);

    for(int i = 0;i<n;i++){
        cout<<v[i].first+1<<" ";
    }
    return 0;
}