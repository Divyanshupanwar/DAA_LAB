#include<bits/stdc++.h>
using namespace std;
void find(vector<int>arr1,vector<int>arr2){
    int i = 0,j=0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else j++;
    }
}



int main(){
   int n;
   cout<<"enter size:"<<endl;
   cin>>n;
   vector<int>arr1(n);
   cout<<"enter elements:"<<endl;
   for(int i = 0;i<n;i++){
    cin>>arr1[i];
   }
   int m;
   cout<<"enter size:"<<endl;
   cin>>m;
   vector<int>arr2(m);
   cout<<"enter elements:"<<endl;
   for(int i = 0;i<m;i++){
    cin>>arr2[i];
   }
   find(arr1,arr2);

    return 0;
}
