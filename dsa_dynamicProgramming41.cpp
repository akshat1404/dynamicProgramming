/*
Given n dice each with m faces, numbered from 1 to m,
find the number of ways to get sum X.
X is the summation of values on each face when all the dice are thrown.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
      int m=6,n=3,x=8;
      int t[n+1][x+1];
      memset(t,0,sizeof(t));
      for(int j=1;j<=x&&j<=m;j++)   t[1][j]=1;
      for(int i=2;i<(n+1);i++){
            for(int j=1;j<(x+1);j++){
                  for(int k=1;k<j&&k<=m;k++){
                        t[i][j]+=t[i-1][j-k];
                  }
            }
      }
      cout<<t[n][x]<<endl;
      return 0;
}