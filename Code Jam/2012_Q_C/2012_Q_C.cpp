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

int main(){
 
    ios_base::sync_with_stdio(false);   
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll a,b;
        unsigned long long ans=0;
        cin>>a>>b;
        bool arr[b+1];
        uninitialized_fill_n(arr, b+1, false);
        for(ll j=a;j<=b;j++){
            if(arr[j]) continue;
            else{
                string s=to_string(j);
                unsigned int len=s.size();
                set<ll> sett;
                sett.insert(j);
                for(unsigned int k=1;k<len;k++){
                    string tmp=s.substr(k,len-k)+s.substr(0,k);
                    if(tmp[0]=='0') continue;
                    string::size_type sz = 0;
                    ll num=stoll(tmp,&sz,0);
                    if((num<=b)&&(num>=a)){
                        sett.insert(num);
                        arr[num]=true;   
                    }
                }
                unsigned long long c=sett.size();
                ans+=c*(c-1)/2;
            }
        }
        printf("Case #%d: %lld\n",i+1,ans);    
    }
    return 0;
}