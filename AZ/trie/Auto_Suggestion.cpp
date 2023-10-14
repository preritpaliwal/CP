#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int wend;
    int cnt;
    map<char,Node*> ch;
    Node():wend(0),cnt(0){}
    ~Node(){
        for(auto &p:ch){
            delete p.second;
        }
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node;
    }
    ~Trie(){
        delete root;
    }
    void insert(string s){
        Node *tmp=root;
        for(char c:s){
            tmp->cnt++;
            if(tmp->ch.find(c)==tmp->ch.end()){
                tmp->ch[c]=new Node;
            }
            tmp=tmp->ch[c];
        }
        tmp->wend++;
    }
    void searcher(string s,int k){
        Node *tmp=root;
        string pre;
        bool wa=false;
        for(char c:s){
            if(tmp->ch.find(c)==tmp->ch.end() || wa){
                cout<<"\n";
                wa=true;
                continue;
            }
            tmp=tmp->ch[c];
            pre+=c;
            print(tmp,k,pre);
            cout<<"\n";
        }
    }
    int print(Node* cur,int k, string &prefix){
        int del=0;
        // cerr<<"pref: "<<prefix<<" "<<k<<endl;
        int w=cur->wend;
        while(w-del>0){
            cout<<prefix<<" ";
            del++;
            if(k<=del){
                break;
            }
        }
        for(auto p:cur->ch){
            if(del>=k)return del;
            prefix+=p.first;
            del+=print(p.second,k-del,prefix);
            prefix.pop_back();
        }
        return del;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    Trie t;
    for(int i=0;i<n;i++){
        int _;cin>>_;
        string s;cin>>s;
        t.insert(s);
    }
    for(int i=0;i<q;i++){
        int _,k;cin>>_;
        string s;cin>>s>>k;
        t.searcher(s,k);
    }
}