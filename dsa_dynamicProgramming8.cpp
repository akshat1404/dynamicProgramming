//Count the number of subsets with a given difference
#include<bits/stdc++.h>
using namespace std;
int main(){
      int arr[]={1,1,3,4};
      int diff=1,n=3;
      int sum=0;
      for(int i=0;i<n;i++){
            sum+=arr[i];
      }
      int total_sum=sum;
      sum/=2;
      int t[n+1][sum+1];
      memset(t,0,sizeof(t));
      for(int i=0;i<(n+1);i++){
            t[i][0]=1;
      }
      for(int i=1;i<(n+1);i++){
            for(int j=1;j<(sum+1);j++){
                  if(j>=arr[i-1]){
                        t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
                  }else{
                        t[i][j]=t[i-1][j];
                  }
            }
      }
      int s=(total_sum-diff)/2;
      int ans=t[n][s];
      if(total_sum%2==0&&diff%2==1||total_sum%2==1&&diff%2==0){
            ans=0;
      }
      cout<<ans<<endl;
      return 0;
}