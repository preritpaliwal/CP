#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a==0 && c==0){
            cout<<0<<endl;
            continue;
        }
        else if(a==0){
            cout<<1<<endl;
            continue;
        }
        else if(c==0){
            cout<<1<<endl;
            continue;
        }
        if(b*c==a*d){
            cout<<0<<endl;
            continue;
        }
        double ans1 = (double)(1LL*b*c)/(1LL*a*d);
        // cout<<"yghij : "<<(1LL*b*c)/(1LL*a*d)<<" ";
        if(abs(ans1-(1LL*b*c)/(1LL*a*d))<0.00001){
            cout<<1<<endl;
            continue;
        }
        double ans2 = (double)(1LL*d*a)/(1LL*b*c);
        // cout<<ans1<<" "<<ans2<<endl;
        if(abs(ans2-(1LL*d*a)/(1LL*c*b))<0.00001){
            cout<<1<<endl;
            continue;
        }
        cout<<2<<endl;
    }
    return 0;
}

/*
8
2 1 1 1
6 3 2 1
1 2 2 3
0 1 0 100
0 1 228 179
100 3 25 6
999999999 300000000 666666666 100000000
33 15 0 84

*/