//Top Down approach
//Knapsack Memoization-->made by modifying recursive knapsack
#include<bits/stdc++.h>
using namespace std;
int t[101][1001];
int knapsack_memoization(int W,int val[],int weight[],int n){
      if(n==0||W==0){
            return 0;
      }
      if(t[n][W]!=-1) return t[n][W];
      else if(W>=weight[n-1]){
            return t[n][W]=max(val[n-1]+knapsack_memoization(W-weight[n-1],val,weight,n-1)/*value after including the item*/,knapsack_memoization(W,val,weight,n-1)/*value without including the item*/);
      }
      else if(W<weight[n-1]){
            return t[n][W]=knapsack_memoization(W,val,weight,n-1);
      }
}
int main(){
      memset(t,-1,sizeof(t));
      return 0;
}