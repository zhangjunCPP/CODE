#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int> s;
signed main(){
    int n,m;
    cin>>n>>m;
    s.insert(0x7fffffff),s.insert(-0x7fffffff);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    int ans=0x7fffffff;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        auto now=s.lower_bound(x);
        ans=min(ans,llabs(x-*now));
        ans=min(ans,llabs(x-*(--now)));
    }
    cout<<ans;
}