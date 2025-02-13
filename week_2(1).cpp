#include<bits/stdc++.h>
using namespace std;
int bs(vector<int>&ans,int key){
    int s = 0;
    int e = ans.size()-1;
    while(s <= e){
        int mid = s+(e-s)/2;
        if(ans[mid] == key){
            return mid;
        }
        else if(ans[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

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
cout<<"enter key to search:"<<endl;
cin>>key;
int mid = bs(arr,key);
if(mid == -1){
    cout<<"element not found !"<<endl;
    return 0;
}
int fs = mid;
while(fs >=0 && arr[fs] == key){
     fs--;
}
fs++;
int ls = mid;
while(ls < arr.size() && arr[ls] == key){
    ls++;
}
ls--;
cout<<"total no of copies for given key are:"<<ls-fs+1<<endl;
return 0;

}