/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.
*/
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int solve(int arr[],int i,int j){
    if(i>j) return 0;
    if(t[i][j]!=-1) return t[i][j];
    return t[i][j]=max(arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1)),arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1)));
}
long long maximumAmount(int arr[], int n){
    memset(t,-1,sizeof(t));
    return solve(arr,0,n-1);
}
int main(){
      return 0;
}