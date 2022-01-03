//Subset sum problem
#include<bits/stdc++.h>
using namespace std;
int main(){
      int arr[]={2,3,7,8,10};
      int n=5,sum=14;
      bool t[n+1][sum+1];
      memset(t,false,sizeof(t));
      for(int i=0;i<(n+1);i++){
            t[i][0]=true;//Empty subset can give sum 0
      }
      for(int j=1;j<(sum+1);j++){
            t[0][j]=false;//If we have no element,no sum can be achieved 
      }
      for(int i=1;i<(n+1);i++){
            for(int j=0;j<(sum+1);j++){
                  if(arr[i-1]<=j){
                        t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                  }else{
                        t[i][j]=t[i-1][j];
                  }
            }
      }
      cout<<t[n][sum]<<endl;
      return 0;
}