//Minimum number of insertion and deletion
#include<bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2){
      int m=word1.length();
      int n=word2.length();
      int t[m+1][n+1];
      for(int i=0;i<(m+1);i++)      t[i][0]=0;
      for(int j=1;j<(n+1);j++)      t[0][j]=0;
      for(int i=1;i<(m+1);i++){
            for(int j=1;j<(n+1);j++){
                  if(word1[i-1]==word2[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                  }else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                  }
            }
      }  
      int lcsLength=t[m][n];
      int ans=m+n-2*lcsLength;
      return ans;
}
int main(){

      return 0;
}