#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n,k;cin>>n>>k;
    // cout<<n<<" "<<k<<"\n";
    vector<int> cnt(k);
    vector<ll> a(n);for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]%=k;
        cnt[a[i]]++;
    }
    if(cnt[0]>0){
        cout<<"0\n";
        return;
    }
    if(k!=4){
        for(int i=k-1;i>=1;i--){
            if(cnt[i]>0){
                cout<<k-i<<"\n";
                break;
            }
        }
    }
    else{
        if(cnt[2]>1){
            cout<<0<<"\n";
        }
        else if(cnt[3]>0){
            cout<<1<<"\n";
        }
        else if(cnt[2]>0 && cnt[1]>0){
            cout<<1<<"\n";
        }
        else{
            cout<<"2\n";
        }
    }
    return ;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}