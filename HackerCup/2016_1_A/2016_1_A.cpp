#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#define N 100010

using namespace std;

bool yn(int *arr,int i, int j) {
    int count=0;
    for(int k=i+1;k<=j;k++) {
        if(arr[k-1]>=arr[k]) return false;
        count+=(arr[k]-arr[k-1]-1)/10;
    }
    return (j-i+1)+count<=4;
}

int solve(int *arr,int n) {
    int f[N];
    memset(f, 50,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=4;j++) if(i-j>=0)
            if(yn(arr,i-j+1, i)) {
                f[i]=min(f[i], f[i-j]+4-j);
            }
    }
    return f[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; 
    cin>>t;
    for(int i=0;i<t;i++) {
        int arr[N];
        int n;
        cin>>n;
        for(int j=1;j<=n;j++) cin>>arr[j];
        int ans=solve(arr,n);
        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}

