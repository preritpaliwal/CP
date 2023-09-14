#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int type=-1;
    bool pos=true;
    for(int i=0;i<n;i++){
        cin>>b[i];
        // cerr<<a[i]<<" "<<b[i]<<" "<<type<<endl;
        if(a[i]==0 && b[i]==0){
            continue;
        }
        int hcf=__gcd(a[i],b[i]);
        a[i]/=hcf;
        b[i]/=hcf;
        if(type==-1){
            if(a[i]%2 == 1 && b[i]%2==1){
                type=0;
            }
            else if(a[i]%2==1){
                type=1;
            }
            else if(b[i]%2==1){
                type=2;
            }
            else{
                cerr<<"What?"<<endl;
            }
        }
        else{
            if(type==0){
                if(a[i]%2==0 || b[i]%2==0){
                    pos=false;
                    // break;
                }
            }
            else if(type==1){
                if(a[i]%2==0 || b[i]%2==1){
                    pos=false;
                    // break;
                }
            }
            else if(type==2){
                if(a[i]%2==1 || b[i]%2==0){
                    pos=false;
                    // break;
                }
            }
        }
        
    }
    if(pos){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        // cerr<<"----------------------\n\n";
        solve();
    }
}