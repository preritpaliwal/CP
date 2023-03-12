#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a,b; 
        cin>>a>>b;
        if(n<m){
            cout<<"NO\n";
            continue;
        }
        while(m>1){
            if(a[n-1]==b[m-1]){
                n--;
                m--;
            }
            else{
                break;
            }
        }
        if(m!=1){
            cout<<"NO\n";
            continue;
        }
        string ans = "NO\n";
        for(int i = 0;i<n;i++){
            if(a[i]==b[0]){
                ans = "YES\n";
                break;
            }
        }
        cout<<ans;
    }
}