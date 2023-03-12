// link to ques : 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fo(i,n) for(int i = 0;i<n;i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod = 10e9 + 7;
    int t;
    cin>>t;
    // cout<<"t = "<<t<<endl;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        int a[n][n];
        fo(i,n){
        cin>>v[i];
        a[i][i] = v[i];
        }
        
        for(int k = 1;k<n;k++){
            for(int i = 0;i<n-k;i++){
                a[i][i+k] = max(a[i+1][i+k],a[i][i+k-1]);
            }
        }
        // fo(i,n){
        //     fo(j,n){
        //         if(j>=i){
        //             cout<<a[i][j]<<" ";
        //         }
        //         else{
        //             cout<<"# ";
        //         }
        //     }
        //     cout<<endl;
        // }
        ll ans = 0;
        fo(j,n){
            ll ansj = 0;
            fo(i,j+1)
            {
                ansj += a[i][j];
            }
            ans += ansj*(n-j);
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}