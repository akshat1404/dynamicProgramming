#include<bits/stdc++.h>
using namespace std;
bool isInterleave(string s1,string s2,string s3){
    int n1=s1.length();
    int n2=s2.length();
    int n3=s3.length();
    if(n1+n2!=n3)   return false;
    bool t[n1+1][n2+1];
    t[0][0]=true;
    for(int i=1;i<=n1;i++)  t[i][0]=(t[i-1][0]&&s1[i-1]==s3[i-1]);
    for(int j=1;j<=n2;j++)  t[0][j]=(t[0][j-1]&&s2[j-1]==s3[j-1]);
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            t[i][j]=(t[i-1][j]&&s1[i-1]==s3[i+j-1])||(t[i][j-1]&&s2[j-1]==s3[i+j-1]);
            //We will check if i'th char of s1==(i+j)'th char in s3 or if j'th char of s2==(i+j)'th char in s3.
            //After that we will check that if s3 is still formed by interleaving of s1 and s2 without including i'th char of s1 or j'th char of s2.(and without including (i+j)'th char if s3 of course)
        }
    }
    return t[n1][n2];
}
int main(){
    return 0;
}