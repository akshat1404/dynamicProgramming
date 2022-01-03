//Matrix chain multiplication 
//Recursive
#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int i,int j,int ans){
      if(i>=j)    return 0;
      for(int k=i;k<j;k++){
          int tempans=solve(arr,i,k,ans)+solve(arr,k+1,j,ans)+arr[i-1]*arr[k]*arr[j];
          ans=min(ans,tempans);
      }
      return ans;
}
int main(){   
      int arr[]={40,20,30,10,30};
      cout<<solve(arr,1,4,INT_MAX);
      return 0;
}