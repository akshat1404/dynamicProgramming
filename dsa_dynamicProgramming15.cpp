//Length of longest common subsequence
//Top down
#include<bits/stdc++.h>
using namespace std;
int LCSrecursive(string &a,string& b,int m,int n,int t[][1001]){
      if(m==0||n==0){
            return 0;
      }
      if(t[m][n]!=-1){
            return t[m][n];
      }
      if(a[m-1]==b[n-1]){
            return t[m][n]=1+LCSrecursive(a,b,m-1,n-1,t);
      }else{
            return t[m][n]=max(LCSrecursive(a,b,m-1,n,t),LCSrecursive(a,b,m,n-1,t));
      }
}
int main(){
      string a="abcdgh";
      string b="abedfhr";
      int m=a.length();
      int n=b.length();
      int t[1001][1001];
      memset(t,-1,sizeof(t));
      cout<<LCSrecursive(a,b,m,n,t)<<endl;
      return 0;
}