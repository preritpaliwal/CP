#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    map<char,Node*> ch;
    ~Node(){
        for(auto &p:ch){
            delete p.second;
        }
    }
};

class Trie{
    public:
    Node *root;
    int cnt;
    Trie():cnt(0){
        root=new Node;
    }
    ~Trie(){
        delete root;
    }
    void insert(string s){
        Node* tmp=root; 
        int news=0;
        for(char c:s){
            if(tmp->ch.find(c)==tmp->ch.end()){
                news++;
                tmp->ch[c]=new Node;
            }
            tmp=tmp->ch[c];
        }
        cnt+=news;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    map<char,int> bad;
    for(int i=0;i<26;i++){
        char c;cin>>c;
        bad['a'+i]=1-(c-'0');
    }
    int k;cin>>k;
    int n=s.size();
    Trie t;
    for(int i=0;i<n;i++){
        string cur;
        int cnt=0;
        for(int j=i;j<n;j++){
            cnt+=bad[s[j]];
            if(cnt>k)break;
            cur+=s[j];
        }
        t.insert(cur);
    }
    cout<<t.cnt<<"\n";
}