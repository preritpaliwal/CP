#include <bits/stdc++.h>
using namespace std;



long long recur(vector<long long> &l,vector<long long> &r, long long k, long long n){
    if(n==l.size()){
        return (long long)1e18;
    }
    int curlen = r[n]-l[n]+1;
    long long pointerLock = 0;
    if(n!=0){
        pointerLock = r[n-1];
    }
    if(curlen>=k){
        return min(l[n]-pointerLock+k-1  +2,r[n] - pointerLock + recur(l,r,k,n+1));
    }
    else{
        return min(r[n]-pointerLock + 2 + recur(l,r,k - (r[n]-l[n]+1),n+1),r[n]-pointerLock +recur(l,r,k,n+1));
    }
}

void solve(){
    long long n,k;
    cin>>n>>k;
    vector<long long> l(n),r(n);
    for(long long i = 0;i<n;i++){
        cin>>l[i];
    }
    long long full = 0;
    for(long long i = 0;i<n;i++){
        cin>>r[i];
        full += r[i]-l[i]+1;
    }
    if(k>full){
        cout<<-1<<endl;;
        return;
    }

    // cout<<recur(l,r,k,0)<<endl;

    vector<long long> kmax(n);
    vector<long long> cost(n);
    for(int i = 0;i<n;i++){
        
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}