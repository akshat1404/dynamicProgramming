//Print longest common subsequence
#include<bits/stdc++.h>
using namespace std;
int main(){
      string a="abcdgh";
      string b="abedfhr";
      int m=a.length();
      int n=b.length();
      int t[m+1][n+1];
      for(int i=0;i<(m+1);i++){
            t[i][0]=0;
      }
      for(int j=0;j<(n+1);j++){
            t[0][j]=0;
      }
      for(int i=1;i<(m+1);i++){
            for(int j=1;j<(n+1);j++){
                  if(a[i-1]==b[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                  }else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                  }
            }
      }
      int i=m,j=n;
      string str;
      while(i>0&&j>0){
            if(a[i-1]==b[j-1]){
                  str.push_back(a[i-1]);
                  i--;j--;
            }else{
                  //Move in the direction of maximum
                  if(t[i][j-1]>t[i-1][j]){
                        j--;
                  }else{
                        i--;
                  }
            }
      }
      reverse(str.begin(),str.end());
      cout<<str<<endl;
      return 0;
}