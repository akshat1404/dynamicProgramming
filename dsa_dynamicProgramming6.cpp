//Number of subsets with given sum
#include<bits/stdc++.h>
using namespace std;
int main(){
      /*int arr[]={2,3,5,6,8,10};
      int sum=10,n=3;*/
      int arr[]={0,0,1};
      int n=3,sum=0;
      int t[n+1][sum+1];
      memset(t,0,sizeof(t));
      for(int i=0;i<(n+1);i++)      t[i][0]=1;
      int ans=0;
      for(int i=1;i<(n+1);i++){
            for(int j=0;j<(sum+1);j++){
                  if(j>=arr[i-1]){
                        t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
                  }else{
                        t[i][j]=t[i-1][j];
                  }
            }
      }
      cout<<t[n][sum]<<endl;
      return 0;
}