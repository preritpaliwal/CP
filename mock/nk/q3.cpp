#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {};
};

vector<int> ans;
void getsubk(Node* cur,int k){
    if(k==0){
        ans.push_back(cur->data);
        return;
    }
    if(k<0)return;
    if(cur->left)getsubk(cur->left,k-1);
    if(cur->right)getsubk(cur->right,k-1);
}

int get(Node* cur,int k,int tar){
    if(cur==NULL)return 0;
    if(cur->data==tar){
        getsubk(cur,k);
        return 1;
    }
    int retval=0;
    int left=0;
    if(cur->left){retval=get(cur->left,k,tar);if(retval==1);left=1;}

    if(cur->right && retval == 0){retval=get(cur->right,k,tar);left=2;};
    if(retval>0){
        if(k<retval){
            return retval+1;
        }
        if(k==retval){
            ans.push_back(cur->data);
            return retval+1;
        }
        if(left==1 && (cur->right!=NULL)){
            getsubk(cur->right,k-retval-1);
        }
        else if(left==2 && (cur->left!=NULL)){
            getsubk(cur->left,k-retval-1);
        }
        return retval+1;
    }
    else{
        return 0;
    }
}

vector <int> KDistanceNodes(Node* root, int k, int tar) { 
    // Write Code Here.
    ans.clear();
    get(root,k,tar);
    sort(ans.begin(),ans.end());
    return ans;
}

Node *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    // cout << data << endl;
    vector<string> dat;
    string t;
    for (auto c : data)
    {
        if (c == ',')
        {
            dat.push_back(t);
            t.clear();
        }
        else
            t.push_back(c);
    }
    dat.push_back(t);
    int i = 0;
    queue<Node *> q;
    auto root = new Node(stoll(dat[0]));
    q.push(root);
    auto cur = root;
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (dat[i] != "x")
        {
            x->left = new Node(stoll(dat[i]));
            q.push(x->left);
        }
        i++;
        if (dat[i] != "x")
        {
            x->right = new Node(stoll(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}
void solve() {
    int n, k, tar;
    cin >> n >> k >> tar;
    string s;
    cin >> s;
    auto root = deserialize(s);
    auto ans = KDistanceNodes(root, k, tar);
    for (auto x : ans)cout << x << " ";
    cout << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
