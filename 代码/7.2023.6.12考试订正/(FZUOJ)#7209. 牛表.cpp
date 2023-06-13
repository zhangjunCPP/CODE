#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=2010;
struct node{
	int id,dis;
    bool operator<(const node&b) const {
        return dis>b.dis;
    }
};
int P,t;
int ans=0;
int tmp=1;
int dis[N];
bool vis[N];
void solve(int u){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<node>q;
	dis[u]=0;
	q.push({u,0});
	while(!q.empty()){
		int id=q.top().id;
		q.pop();
		if(vis[id])continue;
		vis[id]=true;
		for(int j=max((long long)1,id-20);j<min(P,id+20);j++){
			int v=id*j%P;
			if(dis[id]+abs(id-j)<dis[v]){
				dis[v]=dis[id]+abs(id-j);
				q.push({v,dis[v]});
			}
		}
	}
	for(int i=1;i<P;i++){
		ans=(ans+dis[i]*tmp%mod)%mod;
		tmp=(tmp*t)%mod;
	}
	return;
}

signed main(){

	cin>>P>>t;
	for(int i=1;i<P;i++)solve(i);
	cout<<ans;
	
	return 0;
}