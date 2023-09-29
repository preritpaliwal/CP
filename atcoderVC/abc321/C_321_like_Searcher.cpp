#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
string ans;
void solve(){
    cin>>n;
    if(n<=9){cout<<n<<endl;return;}
    int cnt=9;
    queue<string> q;
    for(int i=1;i<10;i++)q.push(string(1,i+'0'));
    while(!q.empty()){
        string s=q.front();q.pop();
        // cerr<<s<<" "<<cnt<<endl;
        for(char c='0';c<s.back();c++){
            cnt++;
            string tmp=s+c;
            if(cnt==n){cout<<tmp<<endl;break;}
            q.push(tmp);
        }
    }
    return ;
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
