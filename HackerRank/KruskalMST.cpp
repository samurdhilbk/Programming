#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;

class Edge{
    public:
    ll src, dest, weight;
};

class Graph{
    public:
    ll V, E;
    vector<Edge> edges;
    Graph(ll,ll);
};

Graph::Graph(ll V, ll E){
    this->V = V;
    this->E = E;   
    edges.resize(E);
}

class Subset{
    public:
    ll parent;
    ll rank;
};

ll find(Subset subsets[], ll i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}

void Union(Subset subsets[], ll x, ll y)
{
    ll xroot = find(subsets, x);
    ll yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool myComp(const Edge &a, const Edge &b){
    return a.weight<b.weight;
}

void KruskalMST(Graph graph){
    cout<<graph.V<<" "<<graph.E<<endl;
    ll V = graph.V;
    Edge result[V];
    ll e = 0;
    ll i = 0;
    
    sort(graph.edges.begin(), graph.edges.end(),myComp);

    Subset subsets[V];

    for (ll v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    cout<<"here1"<<endl;
    while (e < V - 1){
        cout<<"here10"<<endl;
        Edge next_edge = graph.edges[i++];
        cout<<"here9"<<endl;
        ll x = find(subsets, next_edge.src);
        ll y = find(subsets, next_edge.dest);
        cout<<"here3"<<endl;
        if (x != y)
        {
            cout<<"here5"<<endl;
            result[e++] = next_edge;
            cout<<"here4"<<endl;
            Union(subsets, x, y);
        }
    }
    cout<<"here2"<<endl;
    ll sm=0;
    for (i = 0; i < e; ++i)
        sm+=result[i].weight;
    cout<<sm<<endl;
    return;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    ll n,s,m;
    cin>>n>>m;
    vector<Edge> eds;
    map<pr,unsigned long int> mp;
    ll num_edges=0;
    for(ll j=0;j<m;j++){
        cout<<"in"<<endl;
        ll x,y,r;
        cin>>x>>y>>r;
        ll x1=min(x,y);
        ll y1=max(x,y);
        if(mp.find(make_pair(x1,y1))!=mp.end()){
            unsigned long int ind=mp[make_pair(x1,y1)];
            eds[ind].weight=min(eds[ind].weight,r);
        }
        else{
            Edge edge;
            edge.src=x1;
            edge.dest=y1;
            edge.weight=r;
            mp[make_pair(x1,y1)]=eds.size();
            eds.push_back(edge);   
            num_edges++;
        }
    }
    cin>>s;
    cout<<num_edges<<endl;
    Graph graph(n, num_edges);
    for(int i=0;i<num_edges;i++) graph.edges[i]=eds[i];
    cout<<"here"<<endl;
    KruskalMST(graph);
    return 0;
}
