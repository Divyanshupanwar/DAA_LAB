#include<bits/stdc++.h>
using namespace std;
void bs(vector<int>&arr,int key,int s,int e,int ct){
    while(s<=e){
        ct++;
    int mid = s+ (e-s)/2;
    if(arr[mid] == key){
        cout<<"value found at "<<mid<<"total comparisons are:"<<ct<<endl;
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


void jump_search(vector<int>&arr,int key){
    int ct = 0;
    int n = arr.size()-1;
    if(arr[0] == key){
        ct++;
        cout<<"number of comparisons ="<<1<<endl;
    }
    int i = 1;
    while(i < arr.size() && arr[i] <= key){
        i = i*2;

    }
    bs(arr,key,i/2,min(i,n),ct);


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
jump_search(arr,key);
    return 0;
}
