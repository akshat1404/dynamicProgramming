#include<bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p){
    int m=s.length();
    int n=p.length();
    int t[m+1][n+1];
    for(int i=0;i<(m+1);i++){
        t[i][0]=false;
    }
    for(int j=1;j<(n+1);j++){
        t[0][j]=false;
    }
    t[0][0]=true;
    for(int j=1;j<(n+1);j++){
        if(p[j-1]=='*'){
            t[0][j]=t[0][j-1];//only '*' can make a empty sequence
        }
    }
    for(int i=1;i<(m+1);i++){
        for(int j=1;j<(n+1);j++){
            if(s[i-1]==p[j-1]||p[j-1]=='?'){
                t[i][j]=t[i-1][j-1];
            }else if(p[j-1]=='*'){
                t[i][j]=t[i-1][j]/*It can make a empty sequence*/||t[i][j-1];
            }else{
                t[i][j]=false;
            }
        }
    }
    return t[m][n];
}
int main(){
    cout<<isMatch("adceb","*a*b");
    return 0;
}