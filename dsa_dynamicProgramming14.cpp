//Length of longest common subsequence
//Recursive
#include<bits/stdc++.h>
using namespace std;
int LCSrecursive(string a,string b,int m,int n){
      if(m==0||n==0){
            return 0;
      }
      if(a[m-1]==b[n-1]){
            return 1+LCSrecursive(a,b,m-1,n-1);
      }else{
            return max(LCSrecursive(a,b,m-1,n),LCSrecursive(a,b,m,n-1));
      }
}
int main(){
      string a="abcdgh";
      string b="abedfhr";
      int m=a.length();
      int n=b.length();;
      cout<<LCSrecursive(a,b,m,n)<<endl;
      return 0;
}
