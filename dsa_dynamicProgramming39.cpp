/*
Given a rope of length n meters,
cut the rope in different parts of integer lengths in a way
that maximizes product of lengths of all parts.
You must make at least one cut.
Assume that the length of rope is more than 2 meters. 
*/
//Recursive
#include<bits/stdc++.h>
using namespace std;
int solve(int n){
      if(n==1)    return 1;
      int ans=1;
      for(int i=1;i<=n/2;i++){
            int leftRes=max(i,solve(i));
            int rightRes=max(n-i,solve(n-i));
            ans=max(ans,leftRes*rightRes);
      }
      return ans;
}
int maxProductCutting(int n){
      return solve(n);
}
int main(){
      cout<<maxProductCutting(10);
      return 0;
}