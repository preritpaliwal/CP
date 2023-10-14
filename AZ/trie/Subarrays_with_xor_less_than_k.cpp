#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class Node{
    public:
    int cnt;
    Node *left,*right;
    Node():cnt(0),left(NULL),right(0){}
    ~Node(){
        delete left;
        delete right;
    }
};

class Trie{
    public:
    Node* root;
    const int ln;
    Trie():ln(32){
        root=new Node;
        insert(0);
    }
    ~Trie(){
        delete root;
    }
    void insert(int x){
        Node* tmp=root;
        for(int i=ln-1;i>=0;i--){
            tmp->cnt++;
            if(x&(1<<i)){
                if(tmp->right==NULL)tmp->right=new Node;
                tmp=tmp->right;
            }
            else{
                if(tmp->left==NULL)tmp->left=new Node;
                tmp=tmp->left;
            }
        }
        tmp->cnt++;
    }
    int maxxor(int x){
        Node *tmp=root;
        int ret=0;
        for(int i=ln-1;i>=0;i--){
            if(x&(1<<i)){
                if(tmp->left!=NULL && tmp->left->cnt>0){
                    ret|=(1<<i);tmp=tmp->left;
                }
                else tmp=tmp->right;
            }
            else{
                if(tmp->right!=NULL && tmp->right->cnt>0){
                    ret|=(1<<i);tmp=tmp->right;
                }
                else tmp=tmp->left;
            }
        }
        return ret;
    }
    ll count(int x,int k){
        Node *tmp=root;
        ll ans=0;
        for(int i=ln-1;i>=0;i--){
            if(k&(1<<i)){
                if((x&(1<<i))==0){
                    if(tmp->left!=NULL){
                        ans+=tmp->left->cnt;
                    }
                    if(tmp->right!=NULL){
                        tmp=tmp->right;
                    }else{
                        break;
                    }
                }
                else{
                    if(tmp->right!=NULL){
                        ans+=tmp->right->cnt;
                    }
                    if(tmp->left!=NULL){
                        tmp=tmp->left;
                    }else{
                        break;
                    }
                }
            }
            else{
                if(x&(1<<i)){
                    if(tmp->right!=NULL){
                        tmp=tmp->right;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(tmp->left!=NULL){
                        tmp=tmp->left;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    } 
};

void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n),pre(n);for(int &i:a)cin>>i;
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]^a[i];
    }
    Trie t;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=t.count(pre[i],k);
        t.insert(pre[i]);
        // cerr<<ans<<"\n";
    }
    cout<<ans<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
}