#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;  

int main(){

    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        double V,X;
        cin>>n>>V>>X;
        double sp=0.0,sm=0.0,rp=0.0,rm=0.0,R=0.0;
        for(int j=0;j<n;j++){
          double r,c;
          cin>>r>>c;  
          if(c-X>0.0){
            sp+=(c-X)*r;
            rp+=r;
          }
          else if(0.0<X-c){
            sm+=(X-c)*r;
            rm+=r;
          }
          else R+=r;  
        }
        if(sp==0.0||sm==0.0){
            if(R>0.0) printf("Case #%d: %.9f\n",i+1,V/R);
            else printf("Case #%d: IMPOSSIBLE\n",i+1);
        }
        else{
            if(sp-sm>0.0){
              printf("Case #%d: %.9f\n",i+1,(sp/sm)*V/(rp+(sp/sm)*(rm+R)));   
            }
            else printf("Case #%d: %.9f\n",i+1,V/(rp+R+(sp/sm)*rm));   
        }    
    }
    return 0;
}
