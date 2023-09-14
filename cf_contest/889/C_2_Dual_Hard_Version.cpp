#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

void solve(){
    // cerr<<"-----------------\n\n";
    int n;
    cin>>n;
    vector<int> v(n);
    int mini=0,maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[mini]>v[i]){
            mini=i;
        }
        if(v[maxi]<=v[i]){
            maxi=i;
        }
        if(v[i]>0){
            cnt++;
        }
        else if(v[i]<0){
            cnt--;
        }
    }
    if(v[mini]==v[maxi]){
        cout<<0<<endl;
        return;
    }
    vector<pair<int,int>> ops;
    if(cnt>0){
        while(abs(v[mini])>abs(v[maxi])){
            ops.push_back({maxi,maxi});
            v[maxi]+=v[maxi];
        }
        for(int i=1;i<n;i++){
            // cerr<<maxi<<endl;
            if(v[i]<v[i-1]){
                ops.push_back({i,maxi});
                v[i]+=v[maxi];
                if(v[i]>v[maxi]){
                    maxi=i;
                }
                i--;
            }
        }
    }
    else if(cnt<0){
        while(abs(v[maxi])>abs(v[mini])){
            v[mini]+=v[mini];
            ops.push_back({mini,mini});
        }
        for(int i=n-2;i>=0;i--){
            if(v[i]>v[i+1]){
                ops.push_back({i,mini});
                v[i]+=v[mini];
                if(v[i]<v[mini]){
                    mini=i;
                }
                i++;
            }
        }
    }
    else{
        if(abs(v[mini])<abs(v[maxi])){
            for(int i=1;i<n;i++){
                if(v[i]<v[i-1]){
                    ops.push_back({i,maxi});
                    v[i]+=v[maxi];
                    if(v[i]>v[maxi]){
                        maxi=i;
                    }
                    i--;
                }
            }
        }
        else{
            for(int i=n-2;i>=0;i--){
                if(v[i]>v[i+1]){
                    ops.push_back({i,mini});
                    v[i]+=v[mini];
                    if(v[i]<v[mini]){
                        mini=i;
                    }
                    i++;
                }
            }
        }
    }

    cout<<ops.size()<<endl;
    for(int i=0;i<ops.size();i++){
        cout<<ops[i].first+1<<" "<<ops[i].second+1<<endl;
    }
    return;
}

int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}