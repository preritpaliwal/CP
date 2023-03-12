#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define vvll vector<vector<ll>> 
#define qll queue<ll>
#define vpll vector<pair<ll,ll>>
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;

void get_seat(vvll free,ll &a,ll &b){
    queue<pair<ll,ll>> q;
    vpll dir{mp(-1,0),mp(0,-1),mp(0,1),mp(1,0)};
    q.push(mp(a,b));
    free[a][b] = -1;
    while(!q.empty()){
        pair<ll,ll> cur = q.front();
        q.pop();
        fo0(i,dir.size()){
            if(cur.F+dir[i].F<free.size() && cur.F+dir[i].F>=0 && cur.S+dir[i].S>=0 && cur.S+dir[i].S<free[0].size()){
                if(free[cur.F+dir[i].F][cur.S+dir[i].S]==1){
                    a = cur.F+dir[i].F;
                    b = cur.S+dir[i].S;
                    return;
                }
                else{
                    if(free[cur.F+dir[i].F][cur.S+dir[i].S] != -1){
                        free[cur.F+dir[i].F][cur.S+dir[i].S] = -1;
                        q.push(mp(cur.F+dir[i].F,cur.S+dir[i].S));
                    }
                }
            }
        }
    }
}

int main()
{
    fast
    ll n,m,k,a,b;
    cin>>n>>m>>k;
    vpll final_seat;
    vll temp(m,1);
    vvll free(n,temp);
    fo0(i,k){
        cin>>a>>b;
        a--;b--;
        if(free[a][b]!=1){
            get_seat(free,a,b);
        }
        free[a][b] = 0;
        final_seat.pb(mp(a,b));
    }

    // cout<<endl;
    fo0(i,k){
        cout<<final_seat[i].F+1<<" "<<final_seat[i].S+1<<"\n";
    }

    return 0;
}