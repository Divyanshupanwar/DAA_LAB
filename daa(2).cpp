#include<bits/stdc++.h>
using namespace std;
void bs(vector<int>&arr,int key){
//using binary search
int s = 0;
int e = arr.size()-1;
int ct = 0;
while(s<=e){
        ct++;
    int mid = s+ (e-s)/2;
    if(arr[mid] == key){
        cout<<"value found at "<<key<<"total comparisons are:"<<ct<<endl;
        return;

    }
    if(arr[mid] > key){
        e = mid-1;
    }
    else{
        s = mid+1;
    }
}
cout<<"value not found "<<"total comparisons :"<<ct<<endl;
}

int main(){
int n;
cout<<"enter size of vector"<<endl;
cin>>n;
vector<int>arr;
cout<<"enter elements:(in sorted manner)"<<endl;
for(int i = 0;i<n;i++){
    int temp;
    cin>>temp;
    arr.push_back(temp);

}
int key;
cout<<"enter no to be search:"<<endl;
cin>>key;
bs(arr,key);
return 0;
}
