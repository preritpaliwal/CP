#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define qll queue<ll>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>> 
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;

void print(vll v){
    fo0(i,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

bool correct(ll &v,ll &e,vvll &edge,vll &degree,vll &c,int mid){
    qll q;
    ll color = v;
    fo0(i,v){
        if(degree[i]<=mid){
            c[i] = color--;
            q.push(i);
        }
    }

    // cout<<"q.front = "<<q.front()<<endl;;

    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        
        fo0(i,edge[cur].size()){
            degree[edge[cur][i]]--;
            if(c[edge[cur][i]]!=-1){
                continue;
            }
            if(degree[edge[cur][i]]<=mid){
                c[edge[cur][i]] = color--;
                q.push(edge[cur][i]);
            }
        }
    }

    if(color!=0){
        return false;
    }
    else{
        return true;
    }
}

int main()
{
    fast
    int t; cin>>t;
    while(t--){
        ll v,e,at,to;
        cin>>v>>e;
        vvll edge(v);
        vll degree(v,0);
        fo0(i,e){
            cin>>at>>to;
            edge[at-1].pb(to-1);
            edge[to-1].pb(at-1);
            degree[at-1]++;
            degree[to-1]++;
        }

        ll l = 0;
        ll r = v-1;
        ll ans = 0;

        vll c(v,-1);
        vll temp(v,-1);

        while(l<=r){
            ll mid = (l+r)/2;
            if(correct(v,e,edge,degree,temp,mid)){
                r = mid-1;
                c = temp;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }

        cout<<ans<<endl;
        fo0(i,c.size()){
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
3
5 7
1 2
1 3
1 4
2 3
2 4
2 5
3 5

5 4
1 2
2 3
3 4
4 5

3 3
1 2
2 3
1 3
*/