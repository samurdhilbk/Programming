#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sieveOfEratosthenes(vector<ll> &primacity,ll n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for (ll p=2; p<=n; p++){
		if (prime[p] == true){
		    primacity[p]=1;
			for (ll i=p*2; i<=n; i += p){
				prime[i] = false;
				primacity[i]++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	vector<ll> primacity;
	primacity.resize(10000007,0);
	sieveOfEratosthenes(primacity,10000000);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll a,b,k;
        cin>>a>>b>>k;
        ll ans=0LL;
        for(ll j=a;j<=b;j++) if(primacity[j]==k) ans++;
        printf("Case #%d: %lld\n",i+1,ans);
    }
	return 0;
}
