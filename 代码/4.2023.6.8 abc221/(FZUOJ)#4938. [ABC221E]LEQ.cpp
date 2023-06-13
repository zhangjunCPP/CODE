#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[500000],b[500000];
int ans=0;
int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans%mod;
}
int n;
int lowbit(int x){
    return x&(-x);
}
int tree[500000];
void add(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        tree[i]=(tree[i]+val)%mod;
    }
}
int query(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans=(tree[i]+ans)%mod;
    }
    return ans%mod;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+qpow(2,i-1)*query(a[i])%mod)%mod;
        add(a[i],qpow(qpow(2,i),mod-2)%mod);
    }
    cout<<ans;
}