#include<bits/stdc++.h>
using namespace std;
long long countWays(int n){
        long long t[n+1];
        t[0]=1;
        for(int i=1;i<(n+1);i++){
            if(i>3){
                t[i]=(t[i-1]+t[i-2]+t[i-3])%1000000007;
            }else{
                int x=0;
                for(int j=0;j<i;j++){
                    x+=t[j];
                }
                t[i]=x;
            }
        }
        return t[n];
}
int main(){
      return 0;
}