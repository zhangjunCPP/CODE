#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum[10000];
int ans=1;
int now[10000],n;
void dfs(int x){
    if(x==n+1){
        for(int i=2;i<n;i++){
            int sum1=0;
            for(int j=1;j<i;j++){
                sum1=sum1*10+now[j];
            }
            int sum2=0;
            for(int j=i;j<=n;j++){
                sum2=sum2*10+now[j];
            }
            int t=sum1*sum2;
            if(t>ans) ans=t;
        }
    }
    for(int i=0;i<=9;i++){
        if(sum[i]){
            sum[i]--;
            now[x]=i;
            dfs(x+1);
            sum[i]++;
        }
    }
}
signed main(){
    string s;
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++){
        sum[s[i]-'0']++;
    }
    dfs(1);
    cout<<ans;
}