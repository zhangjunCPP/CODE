#include<bits/stdc++.h>
using namespace std;
char to[10000];
int main(){
    to['0']='1';
    to['1']='2';
    to['2']='3';
    to['3']='4';
    to['4']='5';
    to['5']='6';
    to['6']='7';
    to['7']='8';
    to['8']='9';
    to['9']='0';

    char ch[10];
    cin>>ch[1]>>ch[2]>>ch[3]>>ch[4];
    if(ch[1]==ch[2]&&ch[1]==ch[3]&&ch[1]==ch[4]) puts("Weak");
    else if(ch[2]==to[ch[1]]&&ch[3]==to[ch[2]]&&ch[4]==to[ch[3]]) puts("Weak");
    else puts("Strong");
}