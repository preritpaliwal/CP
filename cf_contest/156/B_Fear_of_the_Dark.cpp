#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll px,py,ax,ay,bx,by;cin>>px>>py>>ax>>ay>>bx>>by;
    double aod=sqrt(ax*ax+ay*ay);
    double bod=sqrt(bx*bx+by*by);
    double inter=sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by))/2;
    double apd=sqrt((px-ax)*(px-ax)+(py-ay)*(py-ay));
    double bpd=sqrt((px-bx)*(px-bx)+(py-by)*(py-by));
    cout<<setprecision(11);
    if(px==0 && py==0){
        cout<<0<<endl;return;
    }
    double ans=max(aod,apd);
    ans=min(ans,max(bod,bpd));
    ans=min(ans,max(inter, min(max(apd,bod),max(aod,bpd))));
    cout<<ans<<endl;
    return;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}