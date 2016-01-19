#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef pair<int,int> pr;
typedef pair<pr,vector<vector<char> > > PR;

void change(vector<vector<char> > &grid,vector<pr> &lasers){
    for(int i=0;i<lasers.size();i++){
        pr p=lasers[i];
        int j=p.first;
        int k=p.second;
        if(grid[j][k]=='^') {grid[j][k]='>';continue;}
        if(grid[j][k]=='>') {grid[j][k]='v';continue;}
        if(grid[j][k]=='v') {grid[j][k]='<';continue;}
        if(grid[j][k]=='<') {grid[j][k]='^';continue;}
    }
}

bool can(vector<vector<char> > &grid,vector<pr> &lasers,pr pos,int r,int c){
    int J=pos.first;
    int K=pos.second;
    for(int i=0;i<lasers.size();i++){
        pr p=lasers[i];
        int j=p.first;
        int k=p.second;
        if(grid[j][k]=='^'){
            for(int g=j-1;g>=0;g--){
                char c=grid[g][k];
                if(c=='^'||c=='>'||c=='v'||c=='<'||c=='#') break;
                if(g==J&&k==K) return false;
            }
        }
        if(grid[j][k]=='>'){
            for(int g=k+1;g<c;g++){
                char c=grid[j][g];
                if(c=='^'||c=='>'||c=='v'||c=='<'||c=='#') break;
                if(j==J&&g==K) return false;
            }
        }
        if(grid[j][k]=='v'){
            for(int g=j+1;g<r;g++){
                char c=grid[g][k];
                if(c=='^'||c=='>'||c=='v'||c=='<'||c=='#') break;
                if(g==J&&k==K) return false;
            }
        }
        if(grid[j][k]=='<'){
            for(int g=k-1;g>=0;g--){
                char c=grid[j][g];
                if(c=='^'||c=='>'||c=='v'||c=='<'||c=='#') break;
                if(j==J&&g==K) return false;
            }
        }
    }
    return true;
}

bool search(vector<PR> &visited,PR state){
    sort(visited.begin(),visited.end());
    return binary_search(visited.begin(),visited.end(),state);
}

int bfs(vector<vector<char> > &grid,vector<pr> &lasers,pr pos,int r,int c){
    int level=0;
    vector<pr> nodes;
    nodes.push_back(pos);
    vector<PR> visited;
    while(nodes.size()!=0&&level<1000){
        level++;
	cout<<level<<endl;
        change(grid,lasers);
        vector<pr> nodes1;
        for(int i=0;i<nodes.size();i++){
            int y=nodes[i].second;
            int x=nodes[i].first;
            visited.push_back(make_pair(nodes[i],grid));
            if(x+1<r){
                if(can(grid,lasers,make_pair(x+1,y),r,c)){
                    if(grid[x+1][y]=='G') return level;
                    else if(grid[x+1][y]=='.'&&!(search(visited,make_pair(make_pair(x+1,y),grid)))) nodes1.push_back(make_pair(x+1,y));
                }
            }
            if(x-1>=0){
                if(can(grid,lasers,make_pair(x-1,y),r,c)){
                    if(grid[x-1][y]=='G') return level;
                    else if(grid[x-1][y]=='.'&&!(search(visited,make_pair(make_pair(x-1,y),grid)))) nodes1.push_back(make_pair(x-1,y));
                }
            }
            if(y+1<c){
                if(can(grid,lasers,make_pair(x,y+1),r,c)){
                    if(grid[x][y+1]=='G') return level;
                    else if(grid[x][y+1]=='.'&&!(search(visited,make_pair(make_pair(x,y+1),grid)))) nodes1.push_back(make_pair(x,y+1));
                }
            }
            if(y-1>=0){
                if(can(grid,lasers,make_pair(x,y-1),r,c)){
                    if(grid[x][y-1]=='G') return level;
                    else if(grid[x][y-1]=='.'&&!(search(visited,make_pair(make_pair(x,y-1),grid)))) nodes1.push_back(make_pair(x,y-1));
                }
            }    
        }
        nodes=nodes1;
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int r,c;
        cin>>r>>c;
        vector<vector<char> > grid;
        vector<pr> lasers;
        grid.resize(r);
        pr start;
        for(int j=0;j<r;j++){
            grid[j].resize(c);
            for(int k=0;k<c;k++){
                char c;
                cin>>c;
                if(c=='S'){
                    start=make_pair(j,k);
                    grid[j][k]='.';
                } 
                else grid[j][k]=c;
                if(c=='^'||c=='>'||c=='v'||c=='<') lasers.push_back(make_pair(j,k));
            }
        }
        int res=bfs(grid,lasers,start,r,c);
        if(res!=-1) printf("Case #%d: %d\n",i+1,res);
        else printf("Case #%d: impossible\n",i+1);
    }
    return 0;
}
