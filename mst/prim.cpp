#include<bits/stdc++.h>
using namespace std;
const int v = 5;

int minkey(int *key,bool *mstset){
    int minval = INT_MAX;
    int index = -1;
    for(int i = 0;i<v;i++){
        if(!mstset[i]){
            if(minval>key[i]){
                index = i;
                minval = key[i];
            }
        }
    }
    return index;
}

void printMST(int parent[], int graph[v][v])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < v; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[v][v]){
    bool mstset[v];
    int key[v];
    int parent[v];
    
    for(int i = 1;i<v;i++){
        mstset[i]=false;
        key[i] = INT_MAX;
    }
    mstset[0] = false;
    parent[0] = -1;
    key[0] = 0;

    for(int i = 0;i<v-1;i++){
        int u = minkey(key,mstset);
        mstset[u] = true;
        for(int j = 0;j<v;j++){
            if(graph[u][j] && !mstset[j]){
                if(graph[u][j]<key[j]){
                    key[j] = graph[u][j];
                    parent[j] = u; 
                }
            }
        }
    }

    printMST(parent,graph);

}

int main(){
    int graph[v][v] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    // Print the solution
    primMST(graph);

    return 0;
}