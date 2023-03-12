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
    
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(y>x){
            int z = abs(y-x);
            if(z%2){
                cout<<(z+1)/2 +1;
            }
            else{
                cout<<z/2;
            }
        }
        else{
            cout<<x-y;
        }
        cout<<endl;
    }
    return 0;
}