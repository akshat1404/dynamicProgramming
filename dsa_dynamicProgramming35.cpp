/*
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:
Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
*/
#include<bits/stdc++.h>
using namespace std;
int editDistance(string s, string t){
        int m=s.length();
        int n=t.length();
        int dp[m+1][n+1];
        for(int i=0;i<(m+1);i++)    dp[i][0]=i;
        for(int j=1;j<(n+1);j++)    dp[0][j]=j;
        
        for(int i=1;i<(m+1);i++){
            for(int j=1;j<(n+1);j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    //dp[i-1][j-1]-->Replace
                    //dp[i-1][j]-->deleting from s/inserting to t
                    //dp[i][j-1]-->deleting from t
                }
            }
        }
        return dp[m][n];
}
int main(){
      return 0;
}