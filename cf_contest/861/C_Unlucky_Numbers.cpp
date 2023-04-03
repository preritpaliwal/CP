#include <bits/stdc++.h>
using namespace std;

int getLuck(string s){
    int maxi = 0,mini = 0;
    for(int i = 1;i<s.size();i++){
        if(s[i]<s[mini]){
            mini = i;
        }
        if(s[i]>s[maxi]){
            maxi = i;
        }
    }
    return s[maxi]-s[mini];
}

void solve(){
    int l,r;
    cin>>l>>r;

    string sl = to_string(l),sr = to_string(r);
    if(sl.size() != sr.size()){
        for(int i = 0;i<sl.size();i++){
            cout<<'9';
        }
        cout<<endl;
        return;
    }
    else{
        int lock = -1;
        for(int i = 0;i<sl.size();i++){
            if(sl[i]!=sr[i]){
                lock = i;
                break;
            }
        }
        if(lock == -1){
            cout<<sl<<endl;
        }
        else{
            if(lock>1){
                int mini = 0,maxi = 0;
                for(int i = 1;i<lock;i++){
                    if(sl[i]<sl[mini]){
                        mini=i;
                    }
                    if(sl[i]>sl[maxi]){
                        maxi=i;
                    }
                }
                if(sl[lock])
            }
            if(lock==0){
                if(sl[0]+1<sr[0]){
                    for(int i = 0;i<sl.size();i++){
                        cout<<sl[0]+1;
                    }
                    cout<<endl;
                    return;
                }
                else{
                    int lpos = 0,rpos = 0;
                    for(int i = 1;i<sl.size();i++){
                        if(sl[0]<sl[i]){
                            lpos = 0;
                            break;
                        }
                        else if(sl[0]==sl[i]){
                            lpos = 1;
                            continue;
                        }
                        else{
                            lpos = 1;
                        }
                    }
                    if(lpos==1){
                        for(int i = 0;i<sl.size();i++){
                            cout<<sl[0];
                        }
                        cout<<endl;
                        return;
                    }
                    for(int i = 1;i<sr.size();i++){
                        if(sr[0]>sr[i]){
                            rpos = 0;
                            break;
                        }
                        else if(sr[0]==sr[i]){
                            rpos = 1;
                            continue;
                        }
                        else{
                            rpos = 1;
                        }
                    }
                    if(rpos==1){
                        for(int i = 0;i<sr.size();i++){
                            cout<<sr[0];
                        }
                        cout<<endl;
                        return;
                    }

                }
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}