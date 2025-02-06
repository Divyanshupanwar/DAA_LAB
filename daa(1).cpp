#include<bits/stdc++.h>
using namespace std;
void find_key(int arr[],int n,int key){
      int ct = 0;
    for(int i = 0;i<n;i++){
        ct++;
        if(arr[i]==key){
            cout<<"present"<<"total comparisons :"<<ct<<endl;
            return;
        }
    }
    cout<<"not present :"<<"total comparisons:"<<ct<<endl;

}
int main(){
int n;
cout<<"enter size of vector"<<endl;
cin>>n;
int arr[n];
cout<<"enter elements :"<<endl;
for(int i = 0;i<n;i++){
   cin>>arr[i];
}
int key;
cout<<"enter key to search:"<<endl;
cin>>key;
find_key(arr,n,key);
    return 0;
}
