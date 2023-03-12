#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &i:v){
        cin>>i;
    }
    vector<ll> ans(n,1);
    cout<<"1 ";
    double prevScore = v[0];
    int prevEq = 0;
    for(int i = 1;i<n;i++){
        double newScore;
        if(prevEq==1){
            newScore = prevScore*v[i]/(ans[i-1]);
        }
        else if(prevEq==0){
            newScore = prevScore*v[i]/(ans[i-1]+1);
        }
        else if(prevEq==2){
            newScore = prevScore*v[i]/2;
        }
        cout<<"i,preveq,newscore,prevscore = "<<i<<" "<<prevEq<<" "<<newScore<<" "<<prevScore<<endl;
        prevEq = 0;
        if(abs(newScore-prevScore)<0.0001){
            prevEq = 1;
            ans[i] = ans[i-1]+1;
        }
        else if(newScore>prevScore){
            ans[i] = ans[i-1]+1;
        }
        else{
            newScore = prevScore;
            ans[i] = ans[i-1];
        }
        if(abs(newScore-v[i])<0.0001){
            prevEq = 2;
        }
        else if(newScore<v[i]){
            newScore = v[i];
            ans[i] = 1;
        }
        prevScore = newScore;
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}