#include<bits/stdc++.h>
using namespace std;
void count_sort(vector<int>&arr){
    int n  = arr.size();
    int maxval = INT_MIN;
    for(int i = 0;i<n;i++){
        if(arr[i] > maxval)maxval = arr[i];

    }
    vector<int>B(maxval+1,0);
    for(int i = 0;i<n;i++){
        B[arr[i]]++;
    }
    int maxoccur = 0;
    int val = 0;
    for(int i = 0;i<=maxval;i++){
        if(B[i] > maxoccur){
            maxoccur = B[i];
            val = i;
        }
    }

    cout<<val<<"has maxoccurance is :"<<maxoccur<<endl;
    for(int i = 1;i<=maxval;i++){
        B[i]+=B[i-1];
    }
    vector<int>C(n);
    for(int  i = n-1;i>= 0;i--){
        C[B[arr[i]]-1] = arr[i];
        B[arr[i]]--;

    }
    arr = C;

}
int main(){
int n;
cout<<"enter size of array:"<<endl;
cin>>n;
cout<<"enter elemets:"<<endl;
vector<int>arr(n);
for(int i = 0;i<n;i++){
    cin>>arr[i];

}
count_sort(arr);
cout<<"sorted array is"<<endl;
for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
     
    }
    return 0;

}