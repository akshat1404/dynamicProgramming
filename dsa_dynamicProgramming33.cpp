//Egg drop
//Find minimum attempts to find the critical floor
#include<bits/stdc++.h>
using namespace std;
int eggDrop(int n, int f){
        int t[n+1][f+1];
        for(int i=0;i<(n+1);i++)    t[i][0]=0;
        for(int j=1;j<(f+1);j++)    t[0][j]=0;
        for(int j=1;j<(f+1);j++)    t[1][j]=j;
        for(int i=2;i<(n+1);i++){
            for(int j=1;j<(f+1);j++){
                int a=0,b=j-1;
                int res=INT_MAX;
                while(a<=j-1&&b>=0){
                    res=min(res,max(t[i-1][a],t[i][b]));
                    a++;b--;
                }
                t[i][j]=res+1;
            }
        }
        return t[n][f];
}
int main(){
      return 0;
}