//Unbounded knapsack
#include<bits/stdc++.h>
using namespace std;
int knapSack(int N, int W, int val[], int wt[]){
        int t[N+1][W+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<(N+1);i++){
            for(int j=0;j<(W+1);j++){
                if(j>=wt[i-1]){
                    t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[N][W];
}
int main(){
      int length[]={1,2,3,4,5,6,7,8};
      int price[]={1,5,8,9,10,17,17,20};
      int L=8;
      int max_profit[L+1];//max_profit[i]--> max_profit from rod of length i
      max_profit[0]=0;
      for(int i=1;i<(L+1);i++){
            int max_val=INT_MIN;
            for(int j=0;j<i;j++){
                  max_val=max(max_val,price[j]+max_profit[i-j-1]);
                  //-1 to convert 1 based indexing into 0 based indexing
            }
            max_profit[i]=max_val;
      }
      cout<<max_profit[L]<<endl;
      return 0;
}