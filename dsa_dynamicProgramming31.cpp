//Scrambled string recursive 
#include<bits/stdc++.h>
using namespace std;
bool solve(string a,string b){
      if(a.compare(b)==0)     return true;
      if(a.length()<=1)       return false;
      for(int i=1;i<a.length();i++){
            int n=a.length();
            bool cond1=(solve(a.substr(0,i),b.substr(n-i,i))==true)&&(solve(a.substr(i,n-i),b.substr(0,n-i))==true);
            bool cond2=(solve(a.substr(0,i),b.substr(0,i))==true)&&(solve(a.substr(i,n-i),b.substr(i,n-i))==true);
            bool res=cond1|cond2;
            if(res==true){
                  return true;
            }
      }
      return false;
}
bool isScramble(string s1,string s2){
      memset(t,false,sizeof(t));
      return solve(s1,s2);
}
int main(){
      cout<<isScramble("great","atreg");
      return 0;
}