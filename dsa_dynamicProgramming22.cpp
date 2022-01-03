//Minimum number of deletions to make a string plindrome
#include<bits/stdc++.h>
using namespace std;
int minInsertions(string s){
      string s1=s;
      reverse(s.begin(),s.end());
      string s2=s;
      int l=s.length();
      int t[l+1][l+1];
      for(int i=0;i<(l+1);i++)      t[i][0]=0;
      for(int j=1;j<(l+1);j++)      t[0][j]=0;
      for(int i=1;i<(l+1);i++){
            for(int j=1;j<(l+1);j++){
                  if(s1[i-1]==s2[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                  }else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                  }
            }
      }
      int lcsLength=t[l][l];
      int ans=s.length()-lcsLength;
      return ans;
}
int main(){
      return 0;
}