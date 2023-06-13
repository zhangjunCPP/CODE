#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int ans[10000000];
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        mp[x]++;
        mp[x+y-1+1]--;
    }
    int sum=0;
    int last=0;
    for(auto i:mp){
        ans[sum]+=i.first-last;
        sum+=i.second;
        last=i.first;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }


}