#include <iostream>
#include <climits>
using namespace std;
const int v = 9;

int mindis(bool *sptset,int *dis){
    int mindis = INT_MAX;
    int index = -1;
    for(int i = 0;i<v;i++){
        if(sptset[i]){
            continue;
        }
        if(mindis>dis[i]){
            index = i;
            mindis = dis[i];
        }
    }
    return index;
}

void dijkstra(int g[v][v],int start){
    bool sptset[v];
    int distance[v];
    bool parent[v];
    for(int i = 0;i<v;i++){
        sptset[i] = false;
        distance[i] = INT_MAX;
    }
    distance[start] = 0;
    parent[start] = -1;

    for(int i = 0;i<v;i++){
        int k = mindis(sptset,distance);
        cout<<"k = "<<k<<endl;
        sptset[k] = true;
        for(int j = 0;j<v;j++){
            if(g[k][j] ){
                if(distance[j]>distance[k]+g[k][j]){
                    distance[j] = distance[k] + g[k][j];
                    parent[j] = k;
                }
            }
        }
    }

    for(int i = 0;i<v;i++){
        cout<<parent[i]<<" -> "<<i<<" " << distance[i]<<endl;
    }

}

int main(){
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}