#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;

    string s1 = s,t1=t;
    sort(s1.begin(),s1.end());
    sort(t1.begin(),t1.end());
    int all = 1;
    for(int i =0;i<n;i++){
        if(s1[i]!=t1[i]){
            all=0;
        }
    }

    if(all==0){
        cout<<"NO\n";
    }
    else{
        if(n<k){
            int q = 1;
            for(int i = 0;i<n;i++){
                if(s[i]!=t[i]){
                    q=0;
                    break;
                }
            }
            if(q==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(n>=2*k){
            cout<<"YES\n";
        }
        else{
            set<char> se;
            int inq = 0;
            while(inq+k<n){
                if(inq+k+1<n){
                    se.insert(s[inq+k+1]);
                }
                se.insert(s[inq]);
                se.insert(s[inq+k]);
                inq++;
            }
            int pos = 1;
            for(int i = n-k;i<k;i++){
                // cout<<s[i]<<" "<<t[i]<<endl;
                if(s[i]!=t[i]){
                    pos = 0;
                    break;
                }
            }
            for(int i = 0;i<n-k;i++){
                if(se.find(t[i])==se.end()){
                    pos=0;
                    break;
                }
            }
            for(int i = k;i<n;i++){
                if(se.find(t[i])==se.end()){
                    pos=0;
                    break;
                }
            }
            if(pos==0){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }

}

int  main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}