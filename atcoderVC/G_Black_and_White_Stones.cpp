#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;
using vm=vector<mint>;
using mat=vector<vector<mint>>;

mat matprod(mat a,mat b){
	mat ret(a.size(), vm(b[0].size()));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			for(int k=0;k<b.size();k++){
				ret[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return ret;
}

mat matpow(mat m,ll n){
	int size=m.size();
	mat ret(size,vm(size));
	for(int i=0;i<size;i++)ret[i][i]=1;
	while(n){
		if(n%2)ret=matprod(ret,m);
		m=matprod(m,m);
		n/=2;
	}
	return ret;
}

vector<mint>binom;  //binom[i]=choose(d-1,i)
mint b(int i){
	if(i<0||i>=binom.size())return 0;
	return binom[i];
}

int main(){
	ll n,d;
	cin >> n >> d;
	binom.resize(d);
	binom[0]=1;
	for(int i=1;i<d;i++)binom[i]=binom[i-1]*(d-1-(i-1))/i;
	
	mint ans=0;
	for(int c=0;c<=d+1;c++){
		mat coef={{b(c),b(c-1)},{b(c-1),b(c-2)}};
		mat ret=matpow(coef,n);
		ans+=ret[0][0]+ret[1][1];
	}
	
	cout << ans.val() << endl;
}