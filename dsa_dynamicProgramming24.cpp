//Sequence pattern matching
#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t){
    int m=s.length();
    int n=t.length();
    int table[m+1][n+1];
    for(int i=0;i<(m+1);i++)    table[i][0]=0;
    for(int j=1;j<(n+1);j++)    table[0][j]=0;
    for(int i=1;i<(m+1);i++){
        for(int j=1;j<(n+1);j++){
            if(s[i-1]==t[j-1]){
                table[i][j]=1+table[i-1][j-1];
            }else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }   
    int lcsLength=table[m][n];
    if(lcsLength==m)    return true;
    return false;
}
int main(){
    cout<<isMatch("hi","*?");
    return 0;
}