//Coin change 1 : max no. of ways
#include<bits/stdc++.h>
using namespace std;
long long int count(int S[], int m, int n) {
        long long int t[m+1][n+1];
        memset(t,0,sizeof(t));
        for(int i=0;i<(m+1);i++){
            t[i][0]=1;
        }
        for(int i=1;i<(m+1);i++){
            for(int j=0;j<(n+1);j++){
                if(j>=S[i-1]){
                    t[i][j]=t[i-1][j]+t[i][j-S[i-1]];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[m][n];
}
int main(){
      int coins[]={1,2,3};
      int m=3;
      int n=4;
      int table[n+1];
      memset(table,0,sizeof(table));
      table[0]=1;
      for(int i=0;i<m;i++){
            for(int j=coins[i];j<(n+1);j++){
                  table[j]+=table[j-coins[i]];
            }
      }
      cout<<table[n]<<endl;
      return 0;
}