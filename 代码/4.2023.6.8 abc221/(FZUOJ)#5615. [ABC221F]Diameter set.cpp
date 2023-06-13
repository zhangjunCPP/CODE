#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
struct node{
    int v,nex;
}a[10000000];
int first[1000000],cnt;
void add(int u,int v){
    a[++cnt]={v,first[u]};
    first[u]=cnt;
}
int dep[1000000];
void dfs(int u,int fa){
    for(int i=first[u];i;i=a[i].nex){
        int v=a[i].v;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
int top,tmp[1000000],flag=0;
void dfs2(int u,int fa,int t){
    if(!flag) tmp[++top]=u;
    if(u==t) flag=1;
    for(int i=first[u];i;i=a[i].nex){
        int v=a[i].v;
        if(v==fa) continue;
        dfs2(v,u,t);
    }
    if(!flag) top--;
}
int ans[10000000];
int cntt;
void dfs3(int u,int fa,int id){
    ans[id]+=(dep[u]==cntt/2);
    for(int i=first[u];i;i=a[i].nex){
        int v=a[i].v;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs3(v,u,id);
    }
}
signed main(){
    int n,m;
    cin>>n;
    m=n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        m++;
        add(x,m),add(m,x);
        add(y,m),add(m,y);
    }
    dep[1]=0;
    dfs(1,0);
    int s=0;
    for(int i=1;i<=m;i++)if(dep[i]>dep[s]) s=i;
    dep[s]=0;
    dfs(s,0);
    int t=0;
    for(int i=1;i<=m;i++)if(dep[i]>dep[t]) t=i;
    cntt=dep[t];
    dfs2(s,0,t);
    int rt=tmp[(top+1)>>1];
    for(int i=first[rt];i;i=a[i].nex){
        int v=a[i].v;
        dep[v]=1;
        dfs3(v,rt,v);
    }
    int ans1=1,ans2=1;
    for(int i=first[rt];i;i=a[i].nex){
        int v=a[i].v;
        ans1=(ans1*(ans[v]+1)%mod)%mod;
        ans2=(ans2+ans[v]);
    }
    cout<<(ans1-ans2+mod)%mod;
}