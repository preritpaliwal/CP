#include <bits/stdc++.h>
using namespace std;
// set<pair<int,int>> indexs;

// int lenMaxSub(string a,string b,int la,int lb,int ra,int rb,string &sub){
//     if(la>ra){
//         return 0;
//     }
//     if(lb>rb){
//         return 0;
//     }
//     if(a[la]==b[lb]){
//         string sub1;
//         sub1 += a[la];
//         int len = lenMaxSub(a,b,la+1,lb+1,ra,rb,sub1);
//         sub += sub1;
//         return len+1;
//     }
//     else{
//         string sub1;
//         int len1 = lenMaxSub(a,b,la,lb+1,ra,rb,sub1);
//         string sub2;
//         int len2 = lenMaxSub(a,b,la+1,lb,ra,rb,sub2);
//         if(len1>len2){
//             sub += sub1;
//             return len1;
//         }
//         else{
//             sub += sub2;
//             return len2;
//         }
//     }
// }

void solve(){
    string a,b;
    cin>>a>>b;
    // string sub;
    // int len = lenMaxSub(a,b,0,0,a.size()-1,b.size()-1,sub); 
    // int l = 0;
    // int l1 = 0;
    // int l2 = 0;
    // int ast = 0;
    // int cont = 0;
    // string ans;
    // // cout<<"sub = "<<sub<<endl;
    // int p = -1;
    // while(l<len){
    //     if(a[l1]==sub[l]){
    //         if(b[l2]==sub[l]){
    //             ans += sub[l];
    //             l++;
    //             l1++;
    //             l2++;
    //             if(cont==0){
    //                 p = l-1;
    //             }
    //             cont = 0;

    //             // cout<<l1<<" "<<l2<<"in 1"<<endl;
    //         }
    //         else{
    //             if(cont==0){
    //                 ast++;
    //                 cont=1;
    //                 ans += '*';
    //             }
    //             l2++;

    //             // cout<<l1<<" "<<l2<<"in 2"<<endl;
    //         }
    //     }
    //     else{
    //         if(b[l2]==sub[l]){
    //             if(cont==0){
    //                 ast++;
    //                 cont=1;
    //                 ans += '*';
    //             }
    //             l1++;

    //             // cout<<l1<<" "<<l2<<"in 3"<<endl;
    //         }
    //         else{
    //             if(cont==0){
    //                 ast++;
    //                 cont=1;
    //                 ans += '*';
    //             }
    //             l1++;
    //             l2++;

    //             // cout<<l1<<" "<<l2<<"in 4"<<endl;
    //         }
    //     }
    // }
    // if(l1<a.size() || l2<b.size()){
    //     ast++;
    //     ans+='*';
    // }
    // if(ast==1){
    //     if(ast>len){
    //         cout<<"NO\n";
    //     }
    //     else{
    //         cout<<"YES\n";
    //         cout<<ans<<endl;
    //     }
    // }
    // else{
    //     if(p!=-1){
    //         cout<<"YES\n";
    //         cout<<
    //     }
    // }

    int m = a.size();
    int n = b.size();
    if(a[0]==b[0]){
        cout<<"YES\n"<<a[0]<<"*\n";
        return;
    }
    if(a[m-1]==b[n-1]){
        cout<<"YES\n"<<"*"<<b[n-1]<<"\n";
        return;
    }

    for(int i = 0;i<m-1;i++){
        for(int j = 0;j<n-1;j++){
            if(a[i]==b[j] && a[i+1]==b[j+1]){
                cout<<"YES\n"<<"*"<<a[i]<<a[i+1]<<"*\n";
                return;
            }
        }
    }
    cout<<"NO\n";

}

int  main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}