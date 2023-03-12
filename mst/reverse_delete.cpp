#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int at,to,w;
};

struct Graph{
    int v,e;
    Edge *edges;
};

Graph* creategraph(int v,int e){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->v = v;
    g->e = e;
    g->edges = (Edge *)malloc(sizeof(Edge)*e);
}

void add_edge(Edge &e,int at,int to,int w){
    e.at = at;
    e.to = to;
    e.w = w;
}

bool comp(Edge a,Edge b){
    return a.w>b.w;
}

struct subset{
    int parent,rank;
};

int find(subset *sets,int key){
    if(key != sets[key].parent){
        sets[key].parent = find(sets,sets[key].parent);
    }
    return sets[key].parent;
}

int union1(subset *sets,int a,int b){
    int pa = find(sets,a);
    int pb = find(sets,b);
    if(pa==pb){
        return 0;
    }
    if(sets[pa].rank>sets[pb].rank){
        sets[pb].parent = pa;
    }
    else if(sets[pb].rank>sets[pa].rank){
        sets[pa].parent = pb;
    }
    else{
        sets[pa].parent = pb;
        sets[pb].rank++;
    }
    return 1;
}

bool bridge(Graph *g,int index,bool *deleted){
    subset sets[g->v];
    for(int i = 0;i<g->v;i++){
        sets[i].parent = i;
        sets[i].rank = 0;
    }
    int noofset = g->v;
    for(int i = 0;i<g->e;i++){
        if(index == i){
            continue;
        }
        if(deleted[i]){
            continue;
        }
        if(union1(sets,g->edges[i].at,g->edges[i].to)){
            noofset--;
            cout<<noofset;
        }
    }
    cout<<endl;
    if(noofset==1){
        return false;
    }
    if(noofset==2){
        return true;
    }
    cout<<"kuch gadbad hai"<<endl;
    return true;
}

void reversedeletemst(Graph *g){
    sort(g->edges,g->edges+g->e,comp);

    int mst_w = 0;
    bool deleted[g->e];
    for(int i = 0;i<g->e;i++){
        deleted[i] = false;
    }
    for(int i = 0;i<g->e;i++){
        if(bridge(g,i,deleted)){
            mst_w += g->edges[i].w;
        }
        else{
            deleted[i] = true;
        }
    }

    cout<< "Total weight of MST is " <<mst_w<<endl;

}

int main(){
    int v = 9;
    int e = 14;
    Graph *g = creategraph(v,e);
    add_edge(g->edges[0],0,1,4);
    add_edge(g->edges[1],0,7,8);
    add_edge(g->edges[2],1,2,8);
    add_edge(g->edges[3],1,7,11);
    add_edge(g->edges[4],2,3,7);
    add_edge(g->edges[5],2,8,2);
    add_edge(g->edges[6],2,5,4);
    add_edge(g->edges[7],3,4,9);
    add_edge(g->edges[8],3,5,14);
    add_edge(g->edges[9],4,5,10);
    add_edge(g->edges[10],5,6,2);
    add_edge(g->edges[11],6,7,1);
    add_edge(g->edges[12],6,8,6);
    add_edge(g->edges[13],7,8,7);

    reversedeletemst(g);
}