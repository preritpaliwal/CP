#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* l;
    node* r;
    node* par;
    node(){
        val=0;
        l=nullptr;
        r=nullptr;
        par=nullptr;
    }
};

void insert(node &n1,node &n2){
    if(n1.val<n2.val){
        insert()
    }
}

void solve(){
    node root = node();
    int idx=1;
    while(true){
        int _;cin>>_;if(_==0)break;
        int cur;cin>>cur;
        node n1 = node();
        n1.val=cur;
        if(root.val==0){
            root=n1;
        }
        else{
            insert(root,n1);
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}