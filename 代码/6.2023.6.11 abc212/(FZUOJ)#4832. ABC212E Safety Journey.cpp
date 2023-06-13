#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int dp[5005][5005];// dp[i][j]现在是第i天，该城市是j
int x[10000],y[100000];
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
    }
    dp[0][1]=1;
    int sum=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(sum-dp[i-1][j]+mod)%mod;
        }
        for(int j=1;j<=m;j++){
            dp[i][x[j]]=(dp[i][x[j]]-dp[i-1][y[j]]+mod)%mod;
            dp[i][y[j]]=(dp[i][y[j]]-dp[i-1][x[j]]+mod)%mod;
        }
        sum=0;
        for(int j=1;j<=n;j++){
            sum=(sum+dp[i][j])%mod;
        }
    }
    cout<<dp[k][1];
}