#include <stdio.h>
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define MOD 1000000007
typedef long long ll; 

ll find_part(vector<ll> &vec,map<unsigned int,ll> &mp_part,unsigned int b);

ll solve(vector<ll> &vec,map<unsigned int,ll> &mp_part,ll n){
    //cout<<"In solve"<<endl;
    if(vec.size()==1) return 1;
    if(vec.size()==2){
        if(vec[0]<vec[1]) return 3;
        else return 2;
    }
    else{
            ll sm=0;
            for(unsigned int i=vec.size();i-->0;){
                for(unsigned int j=i;j-->0;){
                    if(vec[j]<vec[i]) sm+=(find_part(vec,mp_part,j)+1)%MOD;
                }
            }
            return (sm+n)%MOD;
    }
}

ll find_part(vector<ll> &vec,map<unsigned int,ll> &mp_part,unsigned int b){
    //cout<<"In find_part "<<b<<endl;
    if(b==0) return 0;
    else if(mp_part.find(b)!=mp_part.end()){
      //cout<<"Yes"<<endl;
      return mp_part[b];  
    }     
    else{
        //cout<<"Here"<<endl;
        ll sm=0;
        for(unsigned int k=b;k-- > 0; ){
            //cout<<"Here2 "<<k<<endl;
            if(vec[k]<vec[b]) sm+=(find_part(vec,mp_part,k)+1)%MOD;
        }
        mp_part[b]=sm;
        //cout<<"find_part sm "<<sm<<endl;
        return sm;
    }
}

int main()

{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        ll n,m,X,Y,Z;
        cin>>n>>m>>X>>Y>>Z;
        vector<ll> A;
        vector<ll> vec;
        map<unsigned int,ll> mp_part;
        for(ll j=0;j<m;j++){
            ll in;
            cin>>in;
            A.push_back(in);
        }
        for(ll j=0;j<n;j++){
            vec.push_back(A[j%m]);
            A[j%m]=(X*A[j%m]+Y*(j+1))%Z;
        }

        printf("Case #%d: %lld\n",i+1,solve(vec,mp_part,n));
    }
    return 0;
}