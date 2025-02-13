#include<bits/stdc++.h>
using namespace std;
void find_pairs(vector<int>&arr){
    int n = arr.size();;
    for(int i = n-1;i>1;i--){
        int s = 0;
        int e  = i-1;
        int sum = arr[i];
        while(s<e){
            if(arr[s] + arr[e] == sum){
            cout<<s+1<<" "<<e+1<<" "<<i+1<<endl;
            return;

            }
            else if(arr[s]+ arr[e] <sum){
                s++;
            }
            else{
                e--;
            }
    }
}
cout<<"no pairs found"<<endl;
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
    find_pairs(arr);



    return 0;
}
