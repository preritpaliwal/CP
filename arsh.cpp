#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lld long long int
#define fo(i,a,n) for(lld i=a;i<n;i++)
#define fo1(i,a,n) for(lld i=n;i>=a;i--)
#define pb(k) push_back(k)
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
#define sort(a) sort(a.begin(),a.end())
#define rev(a) sort(a.begin(),a.end(),greater<int>())
using namespace std;
#define endl '\n'

class Node
{
    public:
        int val;
        vector<Node *> children;
        // Node(){
        //     this->val = val;
        // }
        // void pushData(int val){
        //     this->children.pb(val);
        // }
};

void display(Node *root)
{
    string s = to_string(root->val) + " -> ";
    for(Node *child : root->children){
        s += to_string(child->val) + ", ";
    }
    // cout<<"hello"<<endl;
    s += ".";
    cout<<s<<endl;
    for(Node *child : root->children){
        display(child);
    }
}

int main()
{
    stack<Node*> st;
    Node *root;
    // int n; cin>>n;
    int arr[] = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }
        else{
            Node *t = new Node;
            t->val = arr[i];
            if(st.size()>0){
                Node *temp = st.top();
                (temp->children).pb(t);
            }
            else{
                root = t;
            }
            st.push(t);
        }
        // cout<<i<<endl;
    }
    display(root);
    // cout<<root.val<<endl;
}