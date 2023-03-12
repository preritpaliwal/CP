#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        bool pos = true;
        int maxv = 0;
        map<int,int> m;
        for(int i = 0;i<n;i++){
            cin>>v[i];
            m[v[i]]++;
            if(m[v[i]]>2){
                pos = false;
                break;
            }
            // cout<<pos<<" : pos"<<endl;
        }
        if (m.find(1)!=m.end()){
            if(m[1]>=2){
                pos=false;
            }
        }
        // cout<<pos<<" pos"<<endl;
        // if(m[n]!=2 && n!=1){
        //     pos = false;
        // }
        // cout<<pos<<endl;
        if(!pos){
            cout<<"NO\n";
            continue;
        }
        int num = 1;
        int first = 1;
        for(auto &i:m){
            if(i.second==2){
                while(m.find(num)!=m.end()){
                    num++;
                }
                i.second = num++;
                first = 0;
            }
            else if(i.second==1){
                i.second = i.first;
            }
            if(i.first==first){
                num++;
                first++;
            }
        }
        
        vector<int> p(n,0),q(n,0);
        set<int> s;
        for(int i = 0;i<n;i++){
            if(s.find(v[i])==s.end()){
                p[i] = v[i];
                q[i] = m[v[i]];
                s.insert(v[i]);
            }
            else{
                q[i] = v[i];
                p[i] = m[v[i]];
            }
        }

        cout<<"YES\n";
        for(int i = 0;i<n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i<n;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}