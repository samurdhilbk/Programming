#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        //cout<<s1<<" "<<s2<<" "<<s3<<endl;
        map<char,int> map1;
        map<char,int> map2;
        for(int i=0;i<s2.size();i++) map1[s2[i]]=i;
        for(int i=0;i<s3.size();i++) map2[s3[i]]=i;
        ll num=0;
        for(int i=0;i<s1.size();i++){
            num+=map1[s1[i]]*(ll)pow((long double)(s2.size()),(long double)(s1.size()-1-i));
        }
        //cout<<"num "<<num<<endl;
        ll base=s3.size();
        vector<char> ans;
        while(num>0){
            ans.push_back(s3[num%base]);
            num=num/base;
        }
	cout<<"Case #"<<i+1<<": ";
        for(unsigned int i=ans.size();i-->0;) cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
