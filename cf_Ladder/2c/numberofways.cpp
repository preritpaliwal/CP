// link to ques : https://codeforces.com/problemset/problem/466/C

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;

int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    ll total = 0LL;
    for(int i  = 0;i<n;i++){
        cin>>v[i];
        total += v[i];
    }

    vector<ll> pre(n,0),post(n,0);
    vector<pair<int,int>> is;
    int idx = 0;
    for(int i = 0;i<n;i++){
        if(i==0){
            pre[i] = v[i];
            post[n-1-i] = v[n-1-i];
        }
        else{
            pre[i] = pre[i-1]+v[i];
            post[n-1-i] = post[n-i]+v[n-i-1];
        }

        if(pre[i]*3 == total){
            is.push_back({i,0});
        }
        if(post[n-1-i]*3 == total){
            is.push_back({n-i-1,1});
            idx++;
        }
    }

    sort(is.begin(),is.end());

    int ans = 0;
    for(auto p:is){
        if(p.second==1){
            idx--;
        }
        else{
            ans += idx;
        }
    }
    cout<<ans<<endl;

}