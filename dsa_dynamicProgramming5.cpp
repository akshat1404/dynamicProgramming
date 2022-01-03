//Equal sum partition
#include<bits/stdc++.h>
using namespace std;
int main(){
      int arr[]={1,5,11,21};
      int n=4;
      int total_sum=0;
      bool ans=false;
      for(int i=0;i<n;i++){
            total_sum+=arr[i];
      }
      if(total_sum%2!=0){
            ans=false;
      }else{
            int subset_sum=total_sum/2;
            bool t[n+1][subset_sum+1];
            memset(t,false,sizeof(t));
            for(int i=0;i<(n+1);i++){
                  t[i][0]=true;
            }
            for(int i=1;i<(n+1);i++){
                  for(int j=0;j<(subset_sum+1);j++){
                        if(j>=arr[i-1]){
                              t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
                        }else{
                              t[i][j]=t[i-1][j];
                        }
                  }
            }
            ans=t[n][subset_sum];
      }
      cout<<ans<<endl;
      return 0;
}