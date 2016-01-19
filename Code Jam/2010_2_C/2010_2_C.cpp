#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>

using namespace std;

typedef long long ll;

bool checkEmpty(vector<bitset<1000000> > grid){
    bitset<1000000> zero;
    for(int i=0;i<grid.size();i++){
        if(grid[i]!=zero) return false;
    }
    return true;
}

ll solve(vector<bitset<1000000> > grid){
    int len=grid.size();
    if(checkEmpty(grid)) return 0;
    vector<bitset<1000000> > bgn;
    bgn.resize(len);
    bgn[0]=grid[0];
    for(int i=1;i<len;i++){
        bgn[i]=(grid[i]&(grid[i-1]^(grid[i]>>1)))|(grid[i-1]&(grid[i]>>1));
    }
    return 1+solve(bgn);                                   
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll r;
        cin>>r;
        ll nums[r][4];
        ll mx=LLONG_MIN;
        ll my=LLONG_MIN;
        for(ll j=0;j<r;j++){
            for(int k=0;k<4;k++){
                ll tmp;
                cin>>tmp;
                nums[j][k]=tmp;
            }
            mx=max(mx,nums[j][2]);
            my=max(my,nums[j][3]);
        }
        vector<bitset<1000000> > grid;
        bitset<1000000> foo;
        //cout<<foo<<endl;
        grid.resize(my+1,foo);
        for(ll j=0;j<r;j++){
                for(ll k=(nums[j][1]-1);k<nums[j][3];k++){
                    for(ll g=(mx-nums[j][2]+1);g<(mx-nums[j][0]+2);g++){
                        //cout<<k<<" "<<g<<endl;
                        if(!grid[k+1][g]) grid[k+1].set(g,1);
                    }
                }
        }
        printf("Case #%d: %lld\n",i+1,solve(grid));        
    }
    return 0;
}
