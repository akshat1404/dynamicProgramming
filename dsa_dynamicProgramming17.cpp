//Length of Longest common substring
#include<bits/stdc++.h>
using namespace std;
int main(){
      string a="abcdgh";
      string b="xycdgi";
      int m=a.length();
      int n=b.length();
      int t[m+1][n+1];
      int ans=0;
      for(int i=0;i<(m+1);i++)      t[i][0]=0;
      for(int j=1;j<(n+1);j++)      t[0][j]=0;
      for(int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
                  if(a[i-1]==b[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                  }else{
                        t[i][j]=0;
                  }
                  ans=max(ans,t[i][j]);
            }
      }
      cout<<ans;
      return 0;
}