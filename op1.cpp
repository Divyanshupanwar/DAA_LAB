#include<bits/stdc++.h> 
using namespace std;
int utill(vector<int>&arr,int s,int e,int &cmp){
 int mid = s+(e-s)/2;
 int n1 = mid-s+1;
 int n2 = e-mid;
 vector<int>ls(n1),rs(n2);
 for(int i = 0;i<n1;i++){
 ls[i] = arr[s+i];
 }
 for(int  j = 0;j<n2;j++){
 rs[j] = arr[mid+1+j];                                                                        
 }
 int i = 0,j = 0,k= s;
 int res = 0;
 while(i<n1 && j <n2){
    cmp++;
    if(ls[i] <= rs[j]){
    arr[k++] = ls[i++];
    }
    else{
    arr[k++] = rs[j++];
    res += (n1-i);
    
 }
 }
 while(i<n1){
 arr[k++] = ls[i++];
 }
 while(j < n2){
 arr[k++] = rs[j++];
 }
  return res;
 }
int merge_sort(vector<int>&arr,int s,int e,int &cmp){
   if(s >=e){
     return 0;
     }
     int res = 0;
     int mid  = s+(e-s)/2;
     res += merge_sort(arr,s,mid,cmp);
     res += merge_sort(arr,mid+1,e,cmp);
    res +=  utill(arr,s,e,cmp);
    return res;
}
  
int main(){
int n;
cout<<"enter size of array:"<<endl;
cin>>n;
vector<int>arr(n);
cout<<"enter elements:"<<endl;
for(int i = 0;i<n;i++){
cin>>arr[i];
}
int cmp = 0;
int inversions = merge_sort(arr,0,n-1,cmp);
cout<<"sorted:array is->"<<endl;
for(int i = 0;i<n;i++){
cout<<arr[i]<<" ";
}
cout<<"Total inversions are:"<<inversions<<endl;
cout<<"total no of comparisons  are:"<<cmp<<endl;


return 0;
}
