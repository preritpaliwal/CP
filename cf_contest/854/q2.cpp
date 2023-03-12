#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool allEqual(vector<int> &a){
    int n = (int) a.size();
    for(int i = 1;i<n;i++){
        if(a[i]!=a[0]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ones = 0;
    for(int &i:a){
        cin>>i;
        if(i==1){
            ones++;
        }
    }
    vector<pair<int,int>> ops;
    int q = -1;
    if(ones==0){
        if(allEqual(a)){
            q = 0;
        }
        else{
            q++;
            while(!allEqual(a)){
                int minIndex = 0;
                for(int i = 1;i<n;i++){
                    if(a[minIndex]>a[i]){
                        minIndex = i;
                    }
                }
                for(int i = 0;i<n;i++){
                    while(a[minIndex]<a[i]){
                        // cout<<a[i]<<endl;;
                        int tmp = a[i]/a[minIndex];
                        if(tmp*a[minIndex]==a[i]){
                            a[i] = tmp;
                        }
                        else{
                            a[i] = tmp+1;
                        }
                        q++;
                        ops.push_back({i+1,minIndex+1});
                    }
                }
            }
        }
    }
    else if(ones==n){
        q = 0;
    }

    cout<<q<<endl;
    if(q>0){
        for(int i = 0;i<q;i++){
            cout<<ops[i].first<<" "<<ops[i].second<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}