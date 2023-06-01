#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    vector<pair<int,int>> pre;
    int cur=1;
    for(int i = 1;i<n;i++){
        if(v[i]>v[i-1]){
            pre.push_back({i,max(cur-2,0)});
            cur=1;
        }
        else{
            cur++;
        }
    }
    pre.push_back({n,max(cur-2,0)});

    for(int i = 1;i<pre.size();i++){
        pre[i].second = pre[i-1].second + pre[i].second;
    }
    // for(int i = 0;i<pre.size();i++){
    //     cerr<<pre[i].first<<" "<<pre[i].second<<endl;
    // }
    

    for(int _ = 0;_<q;_++){
        int ql,qr;
        cin>>ql>>qr;
        ql--;
        qr--;
        int li = 0,l=0,r=pre.size(),ri=r;
        while(l<=r){
            int mid = (l+r)/2;
            if(pre[mid].first>ql){
                li = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        l = 0,r= ri;
        while(l<=r){
            int mid = (l+r)/2;
            if(pre[mid].first>qr){
                ri = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(li==ri){
            int inner=0;
            cout<<min(qr-ql+1,2)<<endl;
            // cerr<<li<<" "<<ri<<" "<<inner<<endl;
            continue;
        }
        int inner = 0;
        inner += (pre[li].first-1==ql?0:pre[li].first-ql-2);
        if(ri==0){
            inner += (qr==0)?0:qr-1;
        }
        else{
            inner += (qr==pre[ri-1].first)?0:qr-pre[ri-1].first-1;
            inner += pre[ri-1].second-pre[li].second;
        }
        cout<<qr-ql+1 - inner<<endl;
        // cerr<<li<<" "<<ri<<" "<<inner<<endl;

    }
    return;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}