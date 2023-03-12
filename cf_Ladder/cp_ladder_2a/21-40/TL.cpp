// link to ques : https://codeforces.com/problemset/problem/350/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> r(n,0);
    int wmin = INT_MAX;
    int rmin = INT_MAX;
    int rmax = INT_MIN;
    int q;
    for(int i = 0;i<n;i++){
        cin>>q;
        if(q>rmax){
            rmax = q;
        }
        if(q<rmin){
            rmin = q;
        }
    }
    for(int j = 0;j<m;j++){
        cin>>q;
        if(q<wmin){
            wmin = q;
        }
    }
    if(rmax<wmin){
        if(2*rmin<wmin){
            cout<<max(rmax,2*rmin);
            return 0;
        }
    }
    cout<<"-1";
    return 0;

}