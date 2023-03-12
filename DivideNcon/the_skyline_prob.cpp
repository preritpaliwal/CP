// link to ques : 

#include <bits/stdc++.h>
using namespace std;

int lies(vector<vector<int>> b,int x,int y,int z){
    int k = -1;
    for(int i = 0;i<b.size();i++){
        if(x>=b[i][0] && x<=b[i][1] && (z/2!=i)){
            if(y<b[i][2]){
                k = b[i][2];
            }
        }
    }
    return k;
}

int main()
{
    vector<vector<int>> b;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        vector<int> v;
        for(int j = 0;j<3;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        b.push_back(v);
    }

    // for(int i = 0;i<b.size();i++){
        
    //     for(int j = 0;j<3;j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<pair<int,int>> c;
    for(int i = 0;i<2*n;i+=2){
        c.push_back(make_pair(b[i/2][0],b[i/2][2]));
        c.push_back(make_pair(b[i/2][1],0));
    }

    for(int i = 0;i<2*n;i++){
        int k = lies(b,c[i].first,c[i].second,i);
        if(k!=-1){
            c[i].second = k;
        }
    }

    vector<int> to_be_removed;
    sort(c.begin(),c.end());
    for(int i = 0;i<2*n;i++){
        if(c[i].second==c[i+1].second){
            to_be_removed.push_back(i+1);
        }
    }
    
    int j = 0;
    vector<vector<int>> z;

    for(int i = 0;i<c.size();i++){
        if(i==to_be_removed[j]){
            j++;
            continue;
        }
        vector<int> v{c[i].first,c[i].second};
        z.push_back(v);
        cout<<c[i].first<<","<<c[i].second<<endl;
    }
    return 0;
}

/*
INPUT : 

5
2 9 10 3 7 15 5 12 12 15 20 10 19 24 8

2
0 2 3 2 5 3

*/