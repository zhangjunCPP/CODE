#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int sum[100010][35];
int ans=0;
int check(int l,int r){
	int tmp=0;
	for(int i=33;i>=0;i--){
		int x=sum[r][i]-sum[l-1][i];
		if(x) tmp+=(1<<i);
	}
	return tmp;
}
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=33;j>=0;j--){
			sum[i][j]=sum[i-1][j];
			if((a[i]>>j)&1) sum[i][j]++;
		}
	}
	for(int i=1;i<=n;i++){
		int l=i+1,r=n+1;
		int sum=i;
		while(l<r){ 
			int mid=(l+r)>>1;
			if(check(i,mid)>=m)r=mid;
			else l=mid+1,sum=mid;
		}
		ans+=sum-i; 
	}
	
	cout<<ans;
}