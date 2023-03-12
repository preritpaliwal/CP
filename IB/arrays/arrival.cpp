#include <bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = (int)arrive.size();
    int availableRooms = K;
    map<int,int> arr,dep;
    for(int i = 0;i<n;i++){
        arr[arrive[i]] = i;
    }
    for(auto x : arr){
        cout<<x.first<<" "<<depart[x.second]<<endl;
    }
    auto it = arr.begin();
    while(it!=arr.end()){
        cout<<availableRooms<<endl;
        pair<int,int> arrival = *it;
        cout<<"arrival.first,leave = "<<arrival.first<<" "<<depart[arrival.second]<<endl;
        if(dep.size()!=0){
            // cout<<"arrival.first = "<<arrival.first<<", dep.begin = "<<*(dep.begin())<<endl;
            if(arrival.first > ((*(dep.begin())).first)){
                availableRooms+=(*(dep.begin())).second;
                dep.erase((*(dep.begin())).first);
            }
        }
        cout<<"after checking : "<<availableRooms<<endl;
        if(availableRooms==0){
            // cout<<"why not here"<<endl;
            return false;
        }
        availableRooms--;
        dep[depart[arrival.second]]++;
        it++;
    }
    return true;
}




int main(){
    vector<int> A{17, 0 ,45 ,11 ,16, 43 ,15 ,42 ,2, 41, 0, 27 ,37 ,25 ,17, 42 ,24, 23 ,11, 4 ,29, 39, 6, 10, 42, 16, 17 ,39, 1};
    vector<int> B{25, 24, 52, 51 ,26, 46 ,25 ,45 ,9 ,51, 49, 48, 51 ,66, 65 ,57, 69 ,43, 50, 9, 32, 55, 10, 58, 62, 46 ,19, 87, 12};
    cout<<"ans : "<<hotel(A,B,16)<<endl;;
    return 0;
}