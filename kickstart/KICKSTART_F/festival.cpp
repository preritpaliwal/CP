// link to ques : 

#include <bits/stdc++.h>
using namespace std;

bool sortcol(const int a[3],const int b[3]){
    return a[0]<b[0];
}

int main()
{
    long long t;
    cin>>t;
    long long q = t;
    while(t--){
        cout<<"Case #"<<q-t<<": ";
        long long d,n,k;
        cin>>d>>n>>k;
        int f[n][3];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<3;j++){
                cin>>f[i][j];
            }
        }

        sort(f, f + n,sortcol);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<3;j++){
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}