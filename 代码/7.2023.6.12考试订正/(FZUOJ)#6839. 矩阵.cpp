#include<bits/stdc++.h>
using namespace std;
bitset<105> b[1505][1505][13];
int check(int i,int j,int mid){
    int k=log2(mid);
    int x1=i,x2=i+mid,y1=j,y2=j+mid;
    bitset<105> tmp= b[x1][y1][k]|b[x2-(1<<k)][y1][k]|b[x1][y2-(1<<k)][k]|b[x2-(1<<k)][y2-(1<<k)][k];
    return tmp.count();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            b[i][j][0].set(x);
        }
    }
    for(int k=1;k<=11;k++){
        for(int i=1;i+(1<<k)-1<=n;i++){
            for(int j=1;j+(1<<k)-1<=m;j++){
                b[i][j][k]=b[i][j][k-1]|b[i+(1<<(k-1))][j][k-1]|b[i][j+(1<<(k-1))][k-1]|b[i+(1<<(k-1))][j+(1<<(k-1))][k-1];
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=1,r=min(n-i+1,m-j+1);
            while(l<r){
                int mid=(l+r)>>1;
                if(check(i,j,mid)<k) l=mid+1;
                else r=mid;
            }
            int l1=l;
            if(check(i,j,l1)!=k) continue;
            l=1,r=min(n-i+1,m-j+1);
            while(l<r){
                int mid=(l+r+1)>>1;
                int tmp=check(i,j,mid);
                if(tmp<=k) l=mid;
                else r=mid-1;
            }
            ans+=(l-l1+1);
        }
    }
    cout<<ans;
}