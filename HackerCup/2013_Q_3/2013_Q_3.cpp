#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n,k;
        cin>>n>>k;
        //vector<ll> vec;
        //vec.resize(n,LLONG_MAX);
        ll a,b,c,r;
        cin>>a>>b>>c>>r;
        vector<ll> vec;
        vec.resize(n,LLONG_MAX);
        vec[0]=a;
        //cout<<a<<" ";
        //cout<<"here"<<endl;
        for(int j=1;j<k;j++){
            vec[j]=(b*vec[j-1]+c)%r;
            //cout<<vec[j]<<" ";
        }
        /*
        for(int j=0;j<k;j++){
            ll tmp;
            cin>>tmp;
            vec[j]=tmp;
        }
        */
        ll point=-1;
        ll ind=k;
        ll p;
        vector<ll> vec1=vec;
        sort(vec1.begin(),vec1.begin()+k);
        for(ll j=0;j<=k;j++){
            if(!binary_search(vec1.begin(),vec1.begin()+k,j)) {p=j;break;}; 
        }
        vec[ind]=p;
        //cout<<vec[ind]<<" ";
        ind++;
        point++;
        while(ind<n){
            vector<ll> vec1=vec;
            sort(vec1.begin()+point+1,vec1.begin()+point+1+k);
            for(ll j=min(p+1,vec[point]);j<=k;j++){
                if(!binary_search(vec1.begin()+point+1,vec1.begin()+point+1+k,j)) {p=j;break;}; 
            }
            vec[ind]=p;
            //cout<<vec[ind]<<" ";
            point++;
            ind++;
        }
        printf("Case #%d: %lld\n",i+1,vec[n-1]);
    }
    return 0;
}
