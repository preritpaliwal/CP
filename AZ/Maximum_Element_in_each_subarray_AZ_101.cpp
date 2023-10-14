#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        deque<pair<int,int>> q;
        int cur;
        for(int i=0;i<n;i++){
            cin>>cur;
			while(!q.empty() && q.back().first<=cur){
                q.pop_back();
            }
            while(!q.empty() && q.front().second+k<=i)q.pop_front();
            q.push_back({cur,i});
            if(i+1>=k){
				cout<<q.front().first<<" ";
            }
        }
        cout<<endl;
    }
}