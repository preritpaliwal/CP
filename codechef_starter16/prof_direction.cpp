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
    int t;
    cin>>t;
    while(t--){
        char c;
        int n;
        cin>>n;
        vector<int> v(n,0);
        fo(i,n){
            cin>>c;
            v[i] = (c=='L') ? -1 : 1;
        }
        int pmsf = INT_MIN;
        int pmeh = 0;
        fo(i,n){
            pmeh += v[i];
            if(pmeh>pmsf){
                pmsf = pmeh;
            }
            if(pmeh<0){
                pmeh = 0;
            }
        }
        if(pmsf>1){
            cout<<"YES\n";
            continue;
        }
        int nmsf = INT_MAX;
        int nmeh = 0;
        fo(i,n){
            nmeh += v[i];
            if(nmeh<nmsf){
                nmsf = nmeh;
            }
            if(nmeh>0){
                nmeh = 0;
            }
        }

        if(nmsf<-1){
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";

    }
    return 0;
}