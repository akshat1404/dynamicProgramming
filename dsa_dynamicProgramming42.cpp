#include<bits/stdc++.h>
using namespace std;
class Box{
      public:
      int h,l,w;
};
static bool compare(Box b1,Box b2){
      if((b1.l*b1.w)>(b2.l*b2.w))   return true;
      else return false;            
}
int maxHeight(int height[],int width[],int length[],int n){
      int num=3*n;
      Box b[num];
      int j=0;
      for(int i=0;i<n;i++){
            b[j].h=length[i];
            b[j].l=width[i];
            b[j].w=height[i];
            b[j+1].h=width[i];
            b[j+1].l=length[i];
            b[j+1].w=height[i];
            b[j+2].h=height[i];
            b[j+2].l=length[i];
            b[j+2].w=width[i];
            j+=3;
      }
      sort(b,b+num,compare);
      int t[num];
      t[0]=b[0].h;
      int ans=0;
      for(int i=1;i<num;i++){
            int maxHeight=0;
            for(int j=0;j<i;j++){
                  if((maxHeight<t[j])&&((b[i].l<b[j].l&&b[i].w<b[j].w)||(b[i].l<b[j].w&&b[i].w<b[j].l))){
                        maxHeight=t[j];
                  }
            }
            t[i]=maxHeight+b[i].h;
            ans=max(ans,t[i]);
      }
      return ans;
}    
int main(){
      int length[] = {1,4,3};
      int width[] = {2,5,4};
      int height[] = {3,6,1};
      cout<<maxHeight(height,width,length,3);
      return 0;
}