#include<bits/stdc++.h>
using namespace std;
bool find(vector<int>&arr){
    int key;
    cout<<"enter key:"<<endl;
    cin>>key;
    unordered_map<int,int>mp;
    for(int i = 0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(int i = 0;i<arr.size();i++){

        if(mp[key - arr[i]]){
            if(key -arr[i] == arr[i]){
            int val = mp[arr[i]]-1;
            if(val > 0){
            cout<<key-arr[i]<<" "<<arr[i]<<endl;
            return true;
            }
            }
            else{
                cout<<key-arr[i]<<" "<<arr[i]<<endl;
                return true;

            }
        }
    }
    return false;


}
int main(){
int n;
cout<<"enter size:"<<endl;
cin>>n;
vector<int>arr(n);
cout<<"enter size:"<<endl;
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
bool ans = find(arr);
if(ans){
    cout<<"yes!pair found"<<endl;
}
else cout<<"not found"<<endl;


    return 0;
}
