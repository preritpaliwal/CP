// link to ques : 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    long long q = t;
    while(t--){
        cout<<"Case #"<<q-t<<": ";
        int n,x,y;
        cin>>n;
        vector<vector<int>> v;
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            vector<int> q{x,y};
            v.push_back(q);
        }
        cin>>x>>y;

        if(n<3){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        vector<pair<double,int>> angle;
        for(int i = 0;i<n;i++){
            double x_diff = (double)(v[i][0]-x);
            double y_diff = (double)(v[i][1]-y);
            if(x_diff==0){
                if(y_diff>0){
                    angle.push_back(make_pair(90,i));
                }
                else{
                    angle.push_back(make_pair(-90,i));
                }
            }
            if(x_diff>0){
                angle.push_back(make_pair(180*atan(y_diff/x_diff)/M_PI,i));
            }
            else{
                if(y_diff>=0){
                    angle.push_back(make_pair(180 + 180*atan(y_diff/x_diff)/M_PI,i));
                }
                else{
                    angle.push_back(make_pair(180*atan(y_diff/x_diff)/M_PI - 180,i));
                }
            }
        }

        for(int i  =0;i<n;i++){
            cout<<angle[i].first<<" "<<angle[i].second<<endl;
        }

        sort(angle.begin(),angle.end());
        

        if(angle[angle.size()-1].first - angle[0].first < 180){
            cout<<"IMPOSSIBLE\n";
            continue;
        }

        

    }
    return 0;
}