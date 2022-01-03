//Minimum subset sum difference
#include<bits/stdc++.h>
using namespace std;
int main(){
      int arr[]={2,3,7};
      int n=3;
      int sum=0;
      for(int i=0;i<n;i++){
            sum+=arr[i];
      }
      int total_sum=sum;
      sum/=2;
      bool t[n+1][sum+1];
      memset(t,false,sizeof(t));
      for(int i=0;i<(n+1);i++){
            t[i][0]=true;
      }
      for(int i=1;i<(n+1);i++){
            for(int j=1;j<(sum+1);j++){
                  if(j>=arr[i-1]){
                        t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
                  }else{
                        t[i][j]=t[i-1][j];
                  }
            }
      }
      int s1;
      for(int i=sum;i>=0;i--){
            if(t[n][i]==true){
                  s1=i;
                  break;
            }
      }
      int ans=total_sum-2*s1;
      cout<<ans<<endl;
      return 0;
}