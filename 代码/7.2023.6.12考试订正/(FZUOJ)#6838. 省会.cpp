#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,nex;
}a[10000000];
int first[1000000],cnt;
void add(int u,int v){
    a[++cnt]=node{v,first[u]};
    first[u]=cnt;
}
int n,b;
stack<int> q;
int cap[100000],city[100000],num;
void dfs(int u,int fa){
    int before=q.size();
    for(int i=first[u];i;i=a[i].nex){
        int v=a[i].v;
        if(v==fa) continue;
        dfs(v,u);
        int siz=q.size();
        if(siz-before>=b){
            num++;
            cap[num]=u;
            while(q.size()>before){
                int now=q.top();
                city[now]=num;
                q.pop();
            }
        }
    }
    q.push(u);
}
int main(){
    cin>>n>>b;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    if(!num) {cap[++num]=1;}
    while(!q.empty()){
        int now=q.top();
        city[now]=num;
        q.pop();
    }
    cout<<num<<"\n";
    for(int i=1;i<=n;i++)cout<<city[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=num;i++) cout<<cap[i]<<" ";
}