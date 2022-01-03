/*
Given a n*n matrix where all numbers are distinct,
find the maximum length path (starting from any cell) such that
all cells along the path are in increasing order with a difference of 1. 
We can move in 4 directions from a given cell (i, j), i.e.,
 we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) 
 with the condition that the adjacent cells have a difference of 1.
*/
#include<bits/stdc++.h>
using namespace std;
const int n=4;
int t[n+1][n+1];
int solve(int arr[n][n],int i,int j){
      int len=1;
      if(i<0||i>=n||j<0||j>=n)      return 0;
      if(t[i][j]!=-1)   return t[i][j];
      if(i-1>=0&&arr[i-1][j]-arr[i][j]==1){
            return t[i][j]=len=1+solve(arr,i-1,j);
      }
      if(j-1>=0&&arr[i][j-1]-arr[i][j]==1){
            return t[i][j]=len=1+solve(arr,i,j-1);
      }
      if(i+1<n&&arr[i+1][j]-arr[i][j]==1){
            return t[i][j]=len=1+solve(arr,i+1,j);
      }
      if(j+1<n&&arr[i][j+1]-arr[i][j]==1){
            return t[i][j]=len=1+solve(arr,i,j+1);
      }
      return t[i][j]=len;
}
int longestPath(int arr[n][n]){
      int ans=1;
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  if(t[i][j]==-1)   t[i][j]=solve(arr,i,j);
                  ans=max(ans,t[i][j]);  
            }
            cout<<endl;
      }
      return ans;
}
int main(){
      memset(t,-1,sizeof(t));    
      int arr[n][n];
      arr[0][0]=1;
      arr[0][1]=2;
      arr[0][2]=3;
      arr[0][3]=4;
      arr[1][0]=8;
      arr[1][1]=7;
      arr[1][2]=6;
      arr[1][3]=5;
      arr[2][0]=9;
      arr[2][1]=10;
      arr[2][2]=11;
      arr[2][3]=12;
      arr[3][0]=16;
      arr[3][1]=15;
      arr[3][2]=14;
      arr[3][3]=13;
      cout<<longestPath(arr);
      return 0;
}