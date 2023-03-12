#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define fom(i,a,n) for(ll i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll> 
#define pll pair<ll,ll>
#define vvll vector<vector<ll>> 
#define qll queue<ll>
#define qpll queue<pair<ll,ll>>
#define vpll vector<pair<ll,ll>>
#define vpsll vector<pair<string,ll>>
#define vvll vector<vector<ll>> 
#define pq priority_queue
#define F first
#define S second
#define mod 1000000007
#define INF 1e18
using namespace std;
void print(vll v){
    fo0(i,v.size()){cout<<v[i]<<" ";}
    cout<<endl;}

class Contributor{
    public :
    string name;
    ll no_skills;
    vpsll skills;
    Contributor(string name,ll no_skills){
        this->name=name;
        this->no_skills=no_skills;
        this->skills.resize(no_skills);
    }
    void Print(){
        cout<<"Name : "<<name<<endl;
        cout<<"No of skills : "<<no_skills<<endl;
        cout<<"Skills : ";
        fo0(i,skills.size()){
            cout<<skills[i].F<<" ";
        }
        cout<<endl;
    }
};

class Project{
    public :
    string name;
    ll days;
    ll score;
    ll best_before_days;
    ll no_of_roles;
    vpsll roles;
    Project(string name,ll days,ll score,ll best_before_days,ll no_of_roles){
        this->name=name;
        this->days=days;
        this->score=score;
        this->best_before_days=best_before_days;
        this->no_of_roles=no_of_roles;
        this->roles.resize(no_of_roles);
    }
    void Print(){
        cout<<"Project Name : "<<this->name<<endl;
        cout<<"Days : "<<this->days<<endl;
        cout<<"Score : "<<this->score<<endl;
        cout<<"Best Before Days : "<<this->best_before_days<<endl;
        cout<<"No of Roles : "<<this->no_of_roles<<endl;
        cout<<"Roles : "<<endl;
        fo0(i,this->roles.size()){
            cout<<this->roles[i].F<<" "<<this->roles[i].S<<endl;
        }
    }
};

vector<Contributor> contributors;
vector<Project> projects;
map<string,vpll> skill_to_list_of_contributors;
vector<string> list_of_skills;

int main()
{
    fast
    fstream fout;
    string word;
    fout.open("input_data/a_an_example.in.txt");
    ll c,p;
    fout>>c;
    fout>>p;
    string name;
    ll no_skills;
    fo0(i,c){
        fout>>name;
        fout>>no_skills;
        Contributor c(name,no_skills);
        fo0(j,no_skills){
            fout>>word;
            c.skills[j].first=word;
            fout>>c.skills[j].second;
            if(skill_to_list_of_contributors.find(word)==skill_to_list_of_contributors.end()){
                vpll v;
                v.pb(mp(c.skills[j].S,i));
                skill_to_list_of_contributors[word]=v;
                list_of_skills.push_back(word);
            }
            else{
                skill_to_list_of_contributors[word].pb(mp(c.skills[j].S,i));
            }
        }
        contributors.pb(c);
        // cout<<c.name<<" "<<c.no_skills<<endl;
        // print(c.skills);
    }

    string project_name;
    ll days,score,best_before_days,no_of_roles;
    fo0(i,p){
        fout>>project_name;
        fout>>days;
        fout>>score;
        fout>>best_before_days;
        fout>>no_of_roles;
        Project p(project_name,days,score,best_before_days,no_of_roles);
        fo0(j,no_of_roles){
            fout>>word;
            p.roles[j].first=word;
            fout>>p.roles[j].second;
        }
        projects.pb(p);
        // cout<<p.name<<" "<<p.days<<" "<<p.score<<" "<<p.best_before_days<<" "<<p.no_of_roles<<endl;
        // print(p.roles);
    }
    fout.close();
    fo0(i,c){
        contributors[i].Print();
    }
    fo0(i,p){
        projects[i].Print();
    }

    fo0(i,list_of_skills.size()){
        sort(skill_to_list_of_contributors[list_of_skills[i]].begin(),skill_to_list_of_contributors[list_of_skills[i]].end());
    }

    vll can_do_project;
    vll cannot_do_project;

    fo0(i,projects.size()){
        ll flag=0;
        fo0(j,projects[i].roles.size()){
            if(skill_to_list_of_contributors.find(projects[i].roles[j].first)==skill_to_list_of_contributors.end()){
                flag=1;
                break;
            }
            else{
                ll k=0;
                while(k<skill_to_list_of_contributors[projects[i].roles[j].first].size()){
                    if(skill_to_list_of_contributors[projects[i].roles[j].first][k].S-1>=projects[i].roles[j].second ){
                        break;
                    }
                    k++;
                }
                if(k==skill_to_list_of_contributors[projects[i].roles[j].first].size()){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            can_do_project.pb(i);
        }
        else{
            cannot_do_project.pb(i);
        }
    }

    return 0;
}