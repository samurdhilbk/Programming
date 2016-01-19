#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

typedef long int li;

li minKey(vector<li> key, vector<bool> mstSet,li V)
{

    li min = LONG_MAX;
    li min_index;

    for (li v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min) {

    min = key[v];
    min_index = v;
    }

    return min_index;
}

void printMST(vector<li> parent, li V, vector<vector<li> > &graph)
{
   long long sm=0; 
   for (li i = 1; i < V; i++)
      sm+=graph[parent[i]][i];
   cout<<sm<<endl; 
}

void primMST(vector<vector<li> > &graph,li V)
{
     vector<li> parent; 
     vector<li> key;   
     vector<bool> mstSet;  
 
     for (li i = 0; i < V; i++)
        key.push_back(LONG_MAX), mstSet.push_back(false),parent.push_back(0);
 
     key[0] = 0;     
     parent[0] = -1; 
 
     for (li count = 0; count < V-1; count++){
        li u = minKey(key, mstSet,V);
 
        mstSet[u] = true;
 
        for (li v = 0; v < V; v++)

          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     printMST(parent, V, graph);
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    li n,s,m;
    cin>>n>>m;
    vector<vector<li> > graph;
    for(li j=0;j<n;j++){
        vector<li> tmp;
        for(li k=0;k<n;k++) tmp.push_back(LONG_MAX);
        graph.push_back(tmp);
    } 
    for(li j=0;j<m;j++){
        li x,y,r;
        cin>>x>>y>>r;
        graph[x-1][y-1]=min(graph[x-1][y-1],r);
        graph[y-1][x-1]=min(graph[y-1][x-1],r);
    }
    for(li j=0;j<n;j++){
        for(li k=0;k<n;k++) if(graph[j][k]==LONG_MAX) graph[j][k]=0;
    }
    cin>>s;
    primMST(graph,n);
    return 0;
}