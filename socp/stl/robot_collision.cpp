// // link to question : https://vjudge.net/contest/444867#problem/A

// #include <bits/stdc++.h>
// using namespace std;

// stack<pair<int,int>> reverse(stack<pair<int,int>> s){
//     stack <pair<int,int>> r;
//     while(!s.empty()){
//         r.push(s.top());
//         s.pop();
//     }
//     return r;
// } 

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;
//         cin>>n>>m;
//         int a[n];
//         char b[n];
//         vector <pair<int,int>> odd,even;
//         for(int i = 0;i<n;i++){
//             cin>>a[i];
//             if(a[i]%2){
//                 odd.push_back(make_pair(a[i],i));
//             }
//             else{
//                 even.push_back(make_pair(a[i],i));
//             }
//         }
//         int time[n];
//         for(int i = 0;i<n;i++){
//             cin>>b[i];
//             time[i] = -1;
//         }
//         // cout<<"start"<<endl;
//         stack <pair<int,int>> stackr,stackl;
//         for(int i = 0;i<odd.size();i++){
//             if(b[odd[i].second]=='R'){
//                 stackr.push(odd[i]);
//             }
//             else{
//                 if(!stackr.empty() && stackr.top().first<odd[i].first){
//                     time[stackr.top().second] = (odd[i].first-stackr.top().first)/2;
//                     time[odd[i].second] = (odd[i].first-stackr.top().first)/2;                    
//                     stackr.pop();
//                 }
//                 else{
//                     stackl.push(odd[i]);
//                 }
//             }
//         }
//         // cout<<"end"<<endl;
//         if(!stackl.empty())
//         stackl = reverse(stackl);
//         while(stackl.size()>1){
//             pair <int,int> p1,p2;
//             p1 = stackl.top();
//             stackl.pop();
//             p2 = stackl.top();
//             stackl.pop();
//             time[p1.second] = (p1.first+p2.first)/2;
//             time[p2.second] = (p1.first+p2.first)/2;
//         }
//         while(stackr.size()>1){
//             pair <int,int> p1,p2;
//             p1 = stackr.top();
//             stackr.pop();
//             p2 = stackr.top();
//             stackr.pop();
//             time[p1.second] = m - (p1.first+p2.first)/2;
//             time[p2.second] = m - (p1.first+p2.first)/2;
//         }
//         if(stackl.size()==1 && stackr.size()==1){
//             pair <int,int> p1,p2;
//             p1 = stackr.top();
//             stackr.pop();
//             p2 = stackl.top();
//             stackl.pop();
//             time[p1.second] = m - (p1.first-p2.first)/2;
//             time[p2.second] = m - (p1.first-p2.first)/2;
//         }
//         // 
//         // }
//         if(!stackr.empty()){
//             stackr.pop();
//         }
//         if(!stackl.empty()){
//             stackl.pop();
//         }

//         for(int i = 0;i<even.size();i++){
//             if(b[even[i].second]=='R'){
//                 stackr.push(even[i]);
//             }
//             else{
//                 if(!stackr.empty() && stackr.top().first<even[i].first){
//                     time[stackr.top().second] = (even[i].first-stackr.top().first)/2;
//                     time[even[i].second] = (even[i].first-stackr.top().first)/2;         
//                     stackr.pop();           
//                 }
//                 else{
//                     stackl.push(even[i]);
//                 }
//             }
//         }
        
        
//         stackl = reverse(stackl);
//         while(stackl.size()>1){
//             pair <int,int> p1,p2;
//             p1 = stackl.top();
//             stackl.pop();
//             p2 = stackl.top();
//             stackl.pop();
//             time[p1.second] = (p1.first+p2.first)/2;
//             time[p2.second] = (p1.first+p2.first)/2;
//         }
//         while(stackr.size()>1){
//             pair <int,int> p1,p2;
//             p1 = stackr.top();
//             stackr.pop();
//             p2 = stackr.top();
//             stackr.pop();
//             time[p1.second] = m - (p1.first+p2.first)/2;
//             time[p2.second] = m - (p1.first+p2.first)/2;
//         }
//         if(stackl.size()==1 && stackr.size()==1){
//             pair <int,int> p1,p2;
//             p1 = stackr.top();
//             stackr.pop();
//             p2 = stackl.top();
//             stackl.pop();
//             time[p1.second] = m - (p1.first-p2.first)/2;
//             time[p2.second] = m - (p1.first-p2.first)/2;
//         }
//         for(int i = 0;i<n;i++){
//             cout<<time[i]<<" ";
//         }
//         cout<<endl;
//     }
// }

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct bot{
	int x, d;
};

int main() {
	int t;
	cin >> t;
	forn(_, t){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<bot> a(n);
		forn(i, n) scanf("%d", &a[i].x);
		forn(i, n){
			char c;
			scanf(" %c", &c);
			a[i].d = c == 'L' ? -1 : 1;
		}
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&a](int x, int y){
			return a[x].x < a[y].x;
		});
		vector<int> ans(n, -1);
		vector<vector<int>> par(2);
		for (int i : ord){
			int p = a[i].x % 2;
			if (a[i].d == -1){
				if (par[p].empty())
					par[p].push_back(i);
				else{
					int j = par[p].back();
					par[p].pop_back();
					ans[i] = ans[j] = (a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
				}
			}
			else{
				par[p].push_back(i);
			}
		}
		forn(p, 2){
			while (int(par[p].size()) > 1){
				int i = par[p].back();
				par[p].pop_back();
				int j = par[p].back();
				par[p].pop_back();
				ans[i] = ans[j] = (2 * m - a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
			}
		}
		forn(i, n){
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}