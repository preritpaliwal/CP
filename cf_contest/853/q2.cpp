#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool possible = true;
    // if(n%2==0){
    //     int mid = n/2 - 1;
    //     int i = 0;
    //     bool start = false;
    //     while(mid-i>=0){
    //         if(!start){
    //             if(s[mid-i]!=s[i+mid+1]){
    //                 start = true;
    //             }
    //         }
    //         else{
    //             if(s[mid-i]==s[i+mid+1]){
    //                 break;
    //             }
    //         }
    //         i++;
    //     }
    //     if(mid-i>=0){
    //         while(mid-i>=0){
    //             if(s[mid-i]!=s[i+mid+1]){
    //                 possible = false;
    //                 break;
    //             }
    //             i++;
    //         }
    //     }
    // }
    // else{
    //     int mid = n/2;
    //     int i = 1;
    //     bool start = false;
    //     while(mid-i>=0){
    //         if(!start){
    //             if(s[mid-i]!=s[i+mid]){
    //                 start = true;
    //             }
    //         }
    //         else{
    //             if(s[mid-i]==s[i+mid+1]){
    //                 break;
    //             }
    //         }
    //         i++;
    //     }
    //     if(mid-i>=0){
    //         while(mid-i>=0){
    //             if(s[mid-i]!=s[i+mid]){
    //                 possible = false;
    //                 break;
    //             }
    //             i++;
    //         }
    //     }
    // }

    int l = 0,r = n-1;
    int start = 0;
    while(l<r){
        if(start==0){
            if(s[l]!=s[r]){
                start = 1;
            }
        }
        else if(start == 1){
            if(s[l]==s[r]){
                start = 2;
            }
        }
        else{
            if(s[l]!=s[r]){
                possible = false;
                break;
            }
        }
        l++;
        r--;
    }
    if(possible){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
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