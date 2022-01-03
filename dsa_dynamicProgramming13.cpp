//Coin change 2 : minimum number of coins to make a particular value
#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int M, int V){ 
	int t[M+1][V+1];
      for(int i=0;i<(M+1);i++){
            t[i][0]=0;
      }
      for(int j=1;j<(V+1);j++){
            t[0][j]=INT_MAX-1;//We are doing +1 in line 15 so to avoid overflow,we initialize it with INT_MAX-1
      }
      for(int i=1;i<(M+1);i++){
            for(int j=1;j<(V+1);j++){
                  if(j>=coins[i-1]){
                        t[i][j]=min(t[i-1][j],t[i][j-coins[i-1]]+1);
                  }else{
                        t[i][j]=t[i-1][j];
                  }
            }
      }
      if(t[M][V]==INT_MAX-1) return -1;
	return t[M][V];
}
int main(){
      int coins[3]={3,7,4};
      int V=49;
      cout<<minCoins(coins,3,V);
      return 0;
}