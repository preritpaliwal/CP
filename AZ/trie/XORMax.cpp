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
    void Print(){
        cerr<<"cnt: "<<cnt<<"\n";
        cerr<<"Left-> \n";
        if(left)left->Print();
        cerr<<"right-> \n";
        if(right)right->Print();
    }
};

class Trie{
    public:
    Node* root;
    const int ln;
    Trie():root(NULL),ln(32){
        root=new Node;
        insert(0);
    }
    int insert(int val){
        Node* tmp=this->root;
        for(int i=ln-1;i>=0;i--){
            (tmp->cnt)++;
            if(val&(1<<i)){
                if(tmp->right==NULL)tmp->right=new Node;
                tmp=tmp->right;
            }
            else{
                if(tmp->left==NULL)tmp->left=new Node;
                tmp=tmp->left;
            }
        }
        (tmp->cnt)++;
        return 1;
    }
    int remove(int val){
        Node *tmp=root;
        for(int i=ln-1;i>=0;i--){
            (tmp->cnt)--;
            if(val&(1<<i))tmp=tmp->right;
            else tmp=tmp->left;
        }
        (tmp->cnt)--;
        return 1;
    }
    int maxxor(int val){
        int xorv=0;
        Node *tmp=root;
        for(int i=ln-1;i>=0;i--){
            // cerr<<(tmp->left==NULL)<<(tmp->right==NULL)<<((val&(1<<i))!=0)<<endl;
            if(val&(1<<i)){
                if(tmp->left!=NULL && tmp->left->cnt>0){
                    xorv|=(1<<i);
                    tmp=tmp->left;
                }
                else tmp=tmp->right;
            }
            else{
                if(tmp->right!=NULL && tmp->right->cnt>0){
                    xorv|=(1<<i);
                    tmp=tmp->right;
                }
                else tmp=tmp->left;
            }
        }
        return xorv;
    }
    ~Trie(){
        delete root;
    }
    void Print(){
        root->Print();
    }
};

int main(){
    Trie t;
    int q;cin>>q;
    while(q--){
        char c;cin>>c;int x;cin>>x;
        switch(c){
            case '?':
                cout<<t.maxxor(x)<<"\n";
                break;
            case '+':
                t.insert(x);
                break;
            case '-':
                t.remove(x);
                break;
        }
    }
}