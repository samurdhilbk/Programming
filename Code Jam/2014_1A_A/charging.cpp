#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef long long ll;

ll count(ll n)
{
    ll count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    string s;
    map<ll,ll> mp;
    for(int i=0;i<t;i++){
        int n,l;
        cin>>n>>l;
        vector<ll> ports;
        vector<ll> devices;
        vector<ll> keys;
        map<ll,ll> ones;
        for(int j=0;j<n;j++){
            char *ptr;
            cin>>s;
            ports.push_back(strtoll(s.c_str(),&ptr,2));
        }
        for(int j=0;j<n;j++){
            char *ptr;
            cin>>s;
            devices.push_back(strtoll(s.c_str(),&ptr,2));
        }
        sort(devices.begin(),devices.end());
        ll q=devices[0];
        for(int j=0;j<n;j++){
            ll y=q^ports[j];
            ones[y]=count(y);
            keys.push_back(y);
        }
        ll mn=LLONG_MAX;
        for(int j=0;j<n;j++){
            ll key=keys[j];
            vector<ll> vec=ports;
            for(int k=0;k<n;k++){
                vec[k]=vec[k]^key;
            }
            sort(vec.begin(),vec.end());
            if(vec==devices){
                mn=min(mn,ones[key]);
            }
        }
        if(mn==LLONG_MAX) printf("Case #%d: NOT POSSIBLE\n",i+1);
        else printf("Case #%d: %lld\n",i+1,mn);
    }
    return 0;
}
