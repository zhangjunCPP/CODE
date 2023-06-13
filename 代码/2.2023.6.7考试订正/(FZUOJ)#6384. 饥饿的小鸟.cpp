#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,a[1000000];
int ans=0;
void solve(int x,int now){
	for(int i=x+l;i>x&&now;i--){
		if(i>=n) {ans+=now;return;}
		if(a[i]){
			int tmp=min(a[i],now);
			a[i]-=tmp;
			now-=tmp;
			solve(i,tmp);
		}
	}
}
signed main(){
	cin>>n>>l;
	for(int i=1;i<n;i++) cin>>a[i];
	solve(0,0x3f3f3f3f);
	cout<<ans;
}