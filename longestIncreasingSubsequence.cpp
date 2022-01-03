/*
The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val.
This means that the function returns the index of the next smallest number just greater than or equal to that number.
If there are multiple values that are equal to val, lower_bound() returns the index of the first such value.
The elements in the range shall already be sorted or at least partitioned with respect to val. 
Return Value: An iterator to the lower bound of val in the range.
If all the elements in the range compare less than val, the function returns last.
If all the elements in the range are larger than val,the function returns a pointer to the first element. 
*/
//IMPORTANT-->The elements in the range shall already be sorted or at least partitioned with respect to val. 
//Time Complexity : O(nlogn)
#include<bits/stdc++.h>
using namespace std;
//lower bound-->smallest number just greater than or equal to that number
//upper bound-->greater than value
/*
Input: 10 20 30 40 50
Output: lower_bound for element 30 at index 2
Input : 10 20 30 30 40 50
Output : upper_bound for element 30 is at index 4
*/
//For strictly increasing subsequence
int lengthOfLIS(vector<int>& arr){
      vector<int> v;
      for(int i=0;i<arr.size();i++){
            if(v.empty()||v[v.size()-1]<arr[i])      v.push_back(arr[i]);
            else{
                  int ind=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
                  //lower bound-->return iterator pointing to the smallest element greater than arr[i].
                  //for finding index we need to subtract v.begin()
                  v[ind]=arr[i];//We have to store this element so that the vector remains sorted.
            }
      }
      //vector v does not contain the longest increasing subsequence but it has the same length as longest increasing subsequence.
      return v.size();
}
/*
For non strictly increasing subsequence
int lengthOfLIS(vector<int>& arr){
      vector<int> v;
      for(int i=0;i<arr.size();i++){
            if(v.empty()||v[v.size()-1]<=arr[i])      v.push_back(arr[i]);
            else{
                  int ind=upper_bound(v.begin(),v.end(),arr[i])-v.begin();
                  //upper bound-->return iterator pointing to the smallest element greater than arr[i].
                  //for finding index we need to subtract v.begin()
                  v[ind]=arr[i];//We have to store this element so that the vector remains sorted.
            }
      }
      //vector v does not contain the longest increasing subsequence but it has the same length as longest increasing subsequence.
      return v.size();
}
*/
int main(){
      return 0;
}