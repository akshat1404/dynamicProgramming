//Palindrome Partitioning Memoization
#include<bits/stdc++.h>
using namespace std;
int t[2001][2001];
bool isPalindrome(string& str,int i,int j){
      while(i<=j){
            if(str[i]!=str[j]){
                  return false;
            }
            i++;j--;
      }
      return true;
}
int solve(string& s,int i,int j,int ans){
      if(t[i][j]!=-1)   return t[i][j];
      if(i>=j)    return 0;
      if(isPalindrome(s,i,j)){
            t[i][j]=0;
            return 0;
      }
      for(int k=i;k<j;k++){
            ans=min(ans,solve(s,i,k,ans)+solve(s,k+1,j,ans)+1);
            t[i][j]=ans;
      }
      return t[i][j]=ans;
}
int minCut(string s){
      memset(t,-1,sizeof(t));
      return solve(s,0,s.length()-1,INT_MAX);
}
int main(){
      cout<<minCut("abcb");
      return 0;
}