#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter elements:"<<endl;
    
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    
    }
    int key;
    cout<<"enter key"<<endl;
    cin>>key;
    int count = 0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(mp[arr[it.first + key]]){
            count++;
        }
    }
    cout<<"number of subarrays with sum "<<key<<" is "<<count<<endl;


    return 0;
}