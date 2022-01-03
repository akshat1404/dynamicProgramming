/*
Given a rope of length n meters,
cut the rope in different parts of integer lengths in a way
that maximizes product of lengths of all parts.
You must make at least one cut.
Assume that the length of rope is more than 2 meters. 
*/
//Top down(memoized)
#include<bits/stdc++.h>
using namespace std;
int t[59];
int solve(int n){
      if(n==1)    return 1;
      if(t[n]!=-1)   return t[n];
      int ans=1;
      for(int i=1;i<=n/2;i++){
            int leftRes=max(i,solve(i));
            int rightRes=max(n-i,solve(n-i));
            ans=max(ans,leftRes*rightRes);
            t[n]=ans;
      }
      return t[n];
}
int maxProductCutting(int n){
      memset(t,-1,sizeof(t));
      return solve(n);
}
int main(){
      cout<<maxProductCutting(30);
      return 0;
}