#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int len=s.length();
    int sum=0;
    for(int i=0;i<len;i++){ 
        if(s[i]!=t[i]) sum++;
    }
    if(sum==0){
        cout<<"Yes";
    }
    else if(sum==2){
        int flag=-1;
        for(int i=0;i<len;i++){
            if(s[i]!=t[i]&&flag==-1){
                flag=i;
            }
            else if(s[i]!=t[i]&&flag!=-1){
                if(i!=flag+1){cout<<"No";return 0;}
                swap(s[flag],s[i]);
            }
        }
        
        for(int i=0;i<len;i++)
            if(s[i]!=t[i]) {cout<<"No";return 0;}
        cout<<"Yes";
    
    }
    else {
        cout<<"No";
    }
}