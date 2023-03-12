#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;

vector<ll> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vll in(numCourses,0);
    fo0(i,prerequisites.size()){
        in[prerequisites[i][0]]++;
    }
    queue<int> q;
    fo0(i,in.size()){
        if(in[i]==0){
            q.push(i);
        }
    }

    fo0(i,numCourses){
        cout<<in[i]<<" ";
    }
    cout<<endl;

    vector <vll> list(numCourses);
    fo0(i,prerequisites.size()){
        list[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    fo0(i,list.size()){
        cout<<i<<" - > ";
        fo0(j,list[i].size()){
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }

    ll count = 0;
    vll ans(numCourses,0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<"cur = "<<cur<<endl;
        ans.push_back(cur);
        count++;
        fo0(i,list[cur].size()){
            in[list[cur][i]]--;
            if(in[list[cur][i]]==0){
                q.push(list[cur][i]);
            }
        }
    }
    return ans;
}

int main()
{
    IOS
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<vector<int>> edge(e,vector<int> {0,0});
    for(int i = 0;i<e;i++){
        cin>>edge[i][0]>>edge[i][1];
    }
    vector<ll> ans = findOrder(v,edge);
    return 0;
}

/*
4
4
1 0
2 0
3 1
3 2
*/