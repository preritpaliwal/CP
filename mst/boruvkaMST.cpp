#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int at,to,w;
};

class graph{
public:
    int v,e;
    Edge *edge;
};

class subset{
public:
    int parent;
    int rank;
};

graph* creategraph(int v,int e){
    graph *g = new graph;
    g->v = v;
    g->e = e;
    g->edge = new Edge[e];
    return g;
}

void addedge(Edge &ed,int at,int to,int w){
    ed.at = at;
    ed.to = to;
    ed.w = w;
}


int find(subset *sets,int i){
    if(i !=sets[i].parent){
        sets[i].parent = find(sets,sets[i].parent);
    }
    return sets[i].parent;
}

int union1(subset sets[],int x,int y){
    int px = sets[x].parent;
    int py = sets[y].parent;
    if(px==py){
        return 0;
    }
    if(sets[px].rank>sets[py].rank){
        sets[py].parent = px;
    }
    else if(sets[py].rank>sets[px].rank){
        sets[px].parent = py;
    }
    else{
        sets[px].parent = py;
        sets[py].rank++;
    }
    return 1;
}

void boruvkamst(graph *g){

    subset sets[g->v];
    int cheapest[g->v];
    for(int i = 0;i<g->v;i++){
        sets[i].parent = i;
        sets[i].rank = 0;
    }

    int numoftres = g->v;
    int MSTw = 0;

    while(numoftres>1){
        for(int i = 0;i<g->v;i++){
            cheapest[i] = -1;
        }
        for(int i = 0;i<g->e;i++){
            int s1 = find(sets,g->edge[i].at);
            int s2 = find(sets,g->edge[i].to);

            if(s1==s2){
                continue;
            }

            if(cheapest[s1]==-1 || g->edge[cheapest[s1]].w>g->edge[i].w){
                cheapest[s1] = i;
            }
            if(cheapest[s2]==-1 || g->edge[cheapest[s2]].w>g->edge[i].w){
                cheapest[s2] = i;
            }
        }
        for(int i = 0;i<g->v;i++){
            if(cheapest[i]!=-1){
                if(union1(sets,g->edge[i].at,g->edge[i].to)){
                    numoftres--;
                    MSTw += g->edge[cheapest[i]].w;
                }
            }
        }
    }
    printf("Weight of MST is %d\n", MSTw);
}

int main(){
    int v=4,e=5;
    graph *g = creategraph(v,e);
    addedge(g->edge[0],0,1,10);
    addedge(g->edge[1],0,2,6);
    addedge(g->edge[2],0,3,5);
    addedge(g->edge[3],1,3,15);
    addedge(g->edge[4],2,3,4);

    for(int i = 0;i<5;i++){
        cout<<g->edge[i].at<<" "<<g->edge[i].to<<" "<<g->edge[i].w<<endl;
    }
    boruvkamst(g);
}

