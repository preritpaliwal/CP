#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
ll inv(ll x){
    ll p=mod-2;
    ll mul=x;
    ll cur=1;
    while(p!=0){
        if(p&1)cur=(mul*cur)%mod;
        mul*=mul;
        mul%=mod;
        p>>=1;
    }
    return cur;
}
struct cmp{
    bool operator()(const pair<ll,ll> &p1,const pair<ll,ll> &p2)const{
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
};
int main(){
    ll t;cin>>t;
    while(t--){
        ll q;cin>>q;
        ll sum=0,cnt=0;
        multiset<ll> s,l;
        map<ll,ll> mp;
        multiset<pair<ll,ll>,cmp> freq;
        while(q--){
            string qi;cin>>qi;
            if(qi=="insert"){
                ll x;cin>>x;
                sum+=x;cnt++;sum%=mod;
                if(freq.find({mp[x],x})!=freq.end())freq.erase({mp[x],x});
                mp[x]++;
                freq.insert({mp[x],x});
                if(cnt%2==1) s.insert(x);
                else l.insert(x);
                while((!l.empty()) && (*s.rbegin())>(*l.begin())){
                    s.insert(*l.begin());
                    l.insert(*s.rbegin());
                    s.erase(--s.end());
                    l.erase(l.begin());
                }
            }
            else if(qi=="getMean"){
                if(cnt==0){cout<<-1<<"\n";continue;}
                cout<<((sum)*inv(cnt))%mod<<"\n";
            }
            else if(qi=="getMedian"){
                if(cnt==0){cout<<-1<<"\n";continue;}
                if(cnt%2==1){
                    cout<<(*s.rbegin())<<"\n";
                }
                else{
                    cout<<((*s.rbegin()+*l.begin())*inv(2))%mod<<"\n";
                }
            }
            else if(qi=="getMode"){
                if(cnt==0){cout<<-1<<"\n";continue;}
                cout<<freq.rbegin()->second<<endl;
            }
            else{
                int x;cin>>x;
                sum-=x;cnt--;  
                if(freq.find({mp[x],x})!=freq.end())freq.erase({mp[x],x});
                mp[x]--;
                freq.insert({mp[x],x});
                if(x>(*s.rbegin())){
                    l.erase(x);
                    if(cnt%2==1)continue;
                    l.insert(*s.rbegin());
                    s.erase(--s.end());
                }
                else{
                    s.erase(x);
                    if(cnt%2==0)continue;
                    s.insert(*l.begin());
                    l.erase(l.begin());
                }
            }
        }
    }
}