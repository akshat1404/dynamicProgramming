//Rod cutting problem
#include<bits/stdc++.h>
using namespace std;
//Best Method
int cutRod(int price[], int n){
        int t[n+1];
        t[0]=0;
        for(int i=1;i<(n+1);i++){
            int left=1,right=i-1;
            int val=price[i-1];
            while(left<=right){
                val=max(val,t[left]+t[right]);
                left++;right--;
            }
            t[i]=val;
        }
        return t[n];
}    
//Method 1 : Similar to bounded knapsack
int cutRod(int price[], int n){
        int length[n];
        for(int i=0;i<n;i++){
            length[i]=i+1;
        }
        int t[n+1][n+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<(n+1);i++){
            for(int j=0;j<(n+1);j++){
                if(j>=length[i-1]){
                    t[i][j]=max(t[i-1][j],t[i][j-length[i-1]]+price[i-1]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][n];
}    
int main(){
      int length[]={1,2,3,4,5,6,7,8};
      int price[]={1,5,8,9,10,17,17,20};
      int L=8;
      //Method 2 : using 1 dimension array
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