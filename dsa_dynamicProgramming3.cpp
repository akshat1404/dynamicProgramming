//Bottom up approach knapsack(tabulation)
#include<bits/stdc++.h>
using namespace std;
int main(){
      int n=100,W=1000;
      int t[n+1][W+1];
      int weight[n];
      int val[n];
      memset(t,-1,sizeof(t));
      for(int i=0;i<n+1;i++){
            t[i][0]=0;
      }
      for(int j=1;j<W+1;j++){
            t[0][j]=0;
      }
      for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                  if(j>=weight[i-1]){
                        t[i][j]=max(val[i-1]+t[i-1][j-weight[i-1]],t[i-1][j]);
                  }else{
                        t[i][j]=t[i-1][j];
                  }
            }
      }
      int ans=t[n][W];
      return 0;
}