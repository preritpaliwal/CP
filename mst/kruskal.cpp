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

bool comp(Edge a,Edge b){
    return a.w<b.w;
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

void kruskalmst(graph *g){

    Edge mst[g->v-1];
    int noofedge = 0;
    int i = 0;

    sort(g->edge,g->edge+g->e,comp);

    subset sets[g->v];
    for(int i = 0;i<g->v;i++){
        sets[i].parent = i;
        sets[i].rank = 0;
    }

    while(i<g->e && noofedge<g->v-1){
        Edge cur = g->edge[i++];
        if(union1(sets,cur.at,cur.to)){
            mst[noofedge] = cur;
            noofedge++;
        }
    }
    cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (i = 0; i <noofedge; ++i)
    {
        cout << mst[i].at << " -- " << mst[i].to
            << " == " << mst[i].w << endl;
        minimumCost = minimumCost + mst[i].w;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost
        << endl;
    return;
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
    kruskalmst(g);
}

