#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <memory>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef  pair<ll,ll> pr;

ll solve(vector<pr> boxes,vector<pr> toys){
    /*for(ll i=0;i<boxes.size();i++) cout<<boxes[i].first<<" "<<boxes[i].second;
    cout<<endl;
    for(ll i=0;i<toys.size();i++) cout<<toys[i].first<<" "<<toys[i].second;
    cout<<endl;
    */
    if(boxes.size()==0||toys.size()==0) return 0;
    if(boxes.size()==1&&toys.size()==1){
        if(boxes[0].second==toys[0].second){
            return min(boxes[0].first,toys[0].first);
        }
        return 0;
    }
    ll mx=LLONG_MIN;
    if(boxes[0].second==toys[0].second){
        if(boxes[0].first>toys[0].first){
            ll cr=toys[0].first;
            vector<pr> boxes1=boxes;
            vector<pr> toys1=toys;
            boxes1[0].first-=cr;
            toys1.erase(toys1.begin());
            mx=max(mx,cr+solve(boxes1,toys1));
        }
        else{
            ll cr=boxes[0].first;
            vector<pr> boxes1=boxes;
            vector<pr> toys1=toys;
            toys1[0].first-=cr;
            boxes1.erase(boxes1.begin());
            mx=max(mx,cr+solve(boxes1,toys1));    
        }
    }
    vector<pr> toys1=toys;
    toys1.erase(toys1.begin());
    mx=max(mx,solve(boxes,toys1));
    vector<pr> boxes1=boxes;
    boxes1.erase(boxes1.begin());
    mx=max(mx,solve(boxes1,toys));
    return mx; 
}

int main(){
    ios_base::sync_with_stdio(false);   
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,m;
        cin>>n>>m;
        //cout<<n<<" "<<m<<endl;
        vector<pr> boxes;
        vector<pr> toys;
        for(ll j=0LL;j<n;j++){
            ll a,b;
            cin>>a>>b;
            //cout<<a<<" "<<b<<" ";
            boxes.push_back(make_pair(a,b));
        }
        //cout<<endl;
        for(ll j=0LL;j<m;j++){
            ll a,b;
            cin>>a>>b;
            //cout<<a<<" "<<b<<" ";
            toys.push_back(make_pair(a,b));
        }
        //cout<<endl;
        printf("Case #%d: %lld\n",i+1,solve(boxes,toys));
    }
    return 0;
}