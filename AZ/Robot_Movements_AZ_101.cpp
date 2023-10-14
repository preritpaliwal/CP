#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,r,c,x,y;cin>>n>>r>>c>>x>>y;
    string s;cin>>s;n=s.size();
    vector<set<pair<int,int>>> rows(r+1,{{1,c}}),cols(c+1,{{1,r}});
    rows[x].clear();
    if(1<=y-1)rows[x].insert({1,y-1});
    if(y+1<=c)rows[x].insert({y+1,c});
    cols[y].clear();
    if(1<=x-1)cols[y].insert({1,x-1});
    if(x+1<=r)cols[y].insert({x+1,r});
    for(int i=0;i<n;i++){
        // cerr<<s[i]<<" ";
        if(s[i]=='N'){
            auto it=cols[y].lower_bound({x,INT_MAX});
            if(it==cols[y].begin())x=1;
            else{
                it--;
                x=it->second;
                if(it->first<=it->second-1)cols[y].insert({it->first,it->second-1});
                cols[y].erase(it);
                it = --rows[x].lower_bound({y,INT_MAX});
                if(it->first<=y-1)rows[x].insert({it->first,y-1});
                if(y+1<=it->second)rows[x].insert({y+1,it->second});
                rows[x].erase(it);
            }
        }
        else if(s[i]=='S'){
            auto it=cols[y].lower_bound({x,0});
            if(it==cols[y].end())x=r;
            else{
                x=it->first;
                // cerr<<x<<" ";
                if(it->first+1<=it->second)cols[y].insert({it->first+1,it->second});
                cols[y].erase(it);
                it = --rows[x].lower_bound({y,INT_MAX});
                if(it->first<=y-1)rows[x].insert({it->first,y-1});
                if(y+1<=it->second)rows[x].insert({y+1,it->second});
                rows[x].erase(it);
            }
        }
        else if(s[i]=='E'){
            auto it=rows[x].lower_bound({y,INT_MAX});
            if(it==rows[x].end())y=c;
            else{
                y=it->first;
                if(it->first+1<=it->second)rows[x].insert({it->first+1,it->second});
                rows[x].erase(it);
                it = --cols[y].lower_bound({x,INT_MAX});
                if(it->first<=x-1)cols[y].insert({it->first,x-1});
                if(x+1<=it->second)cols[y].insert({x+1,it->second});
                cols[y].erase(it);
            }
        }
        else if(s[i]=='W'){
            auto it=rows[x].lower_bound({y,INT_MAX});
            if(it==rows[x].begin())y=1;
            else{
                it--;
                y=it->second;
                if(it->first<=it->second-1)rows[x].insert({it->first,it->second-1});
                rows[x].erase(it);
                it = --cols[y].lower_bound({x,INT_MAX});
                if(it->first<=x-1)cols[y].insert({it->first,x-1});
                if(x+1<=it->second)cols[y].insert({x+1,it->second});
                cols[y].erase(it);
            }
        }
        // cerr<<x<<" "<<y<<endl;
        // cerr<<"rows: \n";
        // for(auto &v:rows){
        //     for(auto &p:v)cerr<<"("<<p.first<<","<<p.second<<") ";
        //     cerr<<endl;
        // }
        // cerr<<"cols: \n";
        // for(auto &v:cols){
        //     for(auto &p:v)cerr<<"("<<p.first<<","<<p.second<<") ";
        //     cerr<<endl;
        // }
    }
    cout<<x<<" "<<y<<endl;
    // cerr<<"\n\n\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}