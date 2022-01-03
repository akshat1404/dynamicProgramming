//Knapsack Recursive
#include<bits/stdc++.h>
using namespace std;
int knapsack_recursive(int W,int val[],int weight[],int n){
      if(W==0||n==0) return 0;
      else if(W>=weight[n-1]){
            return max(val[n-1]+knapsack_recursive(W-weight[n-1],val,weight,n-1)/*value after including the item*/,knapsack_recursvie(W,val,weight,n-1)/*value without including the item*/);
      }
      else if(W<weight[n-1]){
            return knapsack_recursive(W,val,weight,n-1);
      }
}
int main(){
      return 0;
}