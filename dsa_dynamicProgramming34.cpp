//Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int a[]){
       int t[n];
       t[0]=1;
       for(int i=1;i<n;i++){
           int maxLen=0;
           for(int j=0;j<i;j++){
               if(a[j]<a[i]){
                   maxLen=max(t[j],maxLen);
               }
           }
           t[i]=maxLen+1;
       }
       int ans=1;
       for(int i=1;i<n;i++){
           ans=max(ans,t[i]);
       }
       return ans;
}
int main(){
      return 0;
}