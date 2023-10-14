#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int cnt;
    Node* left;
    Node* right;
    Node():cnt(0),left(NULL),right(NULL){}
    ~Node(){
        delete left;
        delete right;
    }
};

class Trie{
    public:
    Node* root;
    const int ln;
    Trie():root(NULL),ln(32){
        root=new Node;
    }
    ~Trie(){
        delete root;
    }
    void insert(int x){
        Node *tmp=this->root;
        for(int i=this->ln -1;i>=0;i--){
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
        int ret=0;
        Node *tmp=this->root;
        for(int i=this->ln-1;i>=0;i--){
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
        // cerr<<x<<" "<<ret<<endl;
        return ret;
    }
};

void solve(){
    int n;cin>>n;
    vector<int> pre(n),a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            pre[i]=pre[i-1]^a[i];
        }
        else{
            pre[i]=a[i];
        }
    }
    Trie t;
    t.insert(0);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,t.maxxor(pre[i]));
        t.insert(pre[i]);
    }
    cout<<ans<<"\n";
    // cerr<<"\n\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}