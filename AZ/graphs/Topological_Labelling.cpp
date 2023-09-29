#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
#define forn(i,e) for(lli i = 0; i < e; i++)
#define forsn(i,s,e) for(lli i = s; i < e; i++)
#define rforn(i,s) for(lli i = s; i >= 0; i--)
#define rforsn(i,s,e) for(lli i = s; i >= e; i--)
#define pb push_back
#define ll long long

ll n, m;
vector<vector<ll>>g;
vector<ll>topo;
vector<ll>enc;
vector<ll>indeg;

void kahn(){
	queue<ll>q;
	for(ll i=1;i<=n;i++){
		if(indeg[i]==0) {q.push(i);enc[i]=1;}
	}
	while(!q.empty()){
		ll cur = q.front();q.pop();
		for(auto v:g[cur]){
			indeg[v]--;
			if(indeg[v]==0){
				q.push(v);
				enc[v]=enc[cur]+1;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	enc.resize(n+1,-1);
	indeg.assign(n+1, 0);
	for(ll i=0;i<m;i++){
		ll x, y;
		cin>>x>>y;
		g[x].push_back(y);
		indeg[y]++;
	}

	kahn();
	set<int> s;
	for(int i=1;i<=n;i++)s.insert(i);
	for(int i=1;i<=n;i++){
		enc[i]=*s.lower_bound(enc[i]);
		s.erase(enc[i]);
		cout<<enc[i]<<" ";
	}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//int _t;cin>>_t;while(_t--)
	solve();
}