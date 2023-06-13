#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int,vector<int>,greater<int> > q;
signed main(){
   int Q;
   cin>>Q;
   int sum=0;
   for(int i=1;i<=Q;i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            q.push(x-sum);
        }
        else if(op==2){
            int x;
            cin>>x;
            sum+=x;
        }
        else {
            cout<<q.top()+sum<<"\n";
            q.pop();
        }
   }

}