//Matrix chain multiplication 
//Memoization
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int solve(int arr[],int i,int j,int ans){
      if(i>=j)    return 0;
      if(t[i][j]!=-1){
            return t[i][j];
      }
      for(int k=i;k<j;k++){
          ans=min(ans,solve(arr,i,k,ans)+solve(arr,k+1,j,ans)+arr[i-1]*arr[j]*arr[k]);
          t[i][j]=ans;  
      }
      return t[i][j];
}
int main(){   
      memset(t,-1,sizeof(t));
      int arr[]={40,20,30,10,30};
      cout<<solve(arr,1,4,INT_MAX);
      return 0;
}