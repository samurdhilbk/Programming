#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef long long ll;

ll add(ll x,ll y,ll b){
    if(x+y<b) return x+y;
    return (x+y)%b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,m;
        cin>>n>>m;
        vector<ll> vec;
        for(ll j=0;j<n;j++) vec.push_back(j+1);
        ll ind=0;
        while(vec.size()>1){
            ind=ind%vec.size();
            ind=add(ind,m,vec.size());
            //cout<<vec[ind]<<" ";
            vec.erase(vec.begin()+ind);
        }
        //cout<<endl;
        cout<<vec[0]<<endl;
    }
    return 0;
}
