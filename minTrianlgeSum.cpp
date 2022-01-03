#include<bits/stdc++.h>
using namespace std;
/*
recursive+memoize
int t[201][201];
int solve(vector<vector<int>>& triangle,int index,int col,int n){
    if(index==n)    return 0;
    if(t[index][col]!=-1)   return t[index][col];
    return t[index][col]=min(solve(triangle,index+1,col,n),solve(triangle,index+1,col+1,n))+triangle[index][col];
}
int minimumTotal(vector<vector<int>>& triangle){
    memset(t,-1,sizeof(t));
    return solve(triangle,0,0,triangle.size());
}
*/
//Space Complexity : O(n)
//Time Complexity : O(n^2)
int minimumTotal(vector<vector<int>>& triangle){
    vector<int> t=triangle[triangle.size()-1];
    for(int i=triangle.size()-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            t[j]=triangle[i][j]+min(t[j],t[j+1]);
        }
    }
    return t[0];
}
int main(){
      return 0;
}