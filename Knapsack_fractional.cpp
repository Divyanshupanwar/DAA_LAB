#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<double>&a,vector<double>&b){
    return a[2]>b[2];

}
void knapsack(int &cap,vector<vector<double>>&v){
    int total = 0;
    for(auto it:v){
        if(cap == 0)break;
         if(cap - it[0] >= 0){
              total += it[1];
              cap -= it[0];
         }
         else{
          double part = it[2] * cap;
          total += part;
         }
    }
    cout<<"total profit :"<<total<<endl;



}
int main(){
    int cap;
    cout<<"enter capacity"<<endl;
    cin>>cap;
    vector<vector<double>>v(3,vector<double>(3));
    for(int i = 0;i<3;i++){
               cout<<"enter weight and profit:"<<"for item "<<i+1<<endl;
               cin>>v[i][0]>>v[i][1];
               v[i][2] = v[i][1]/v[i][0];

               
        }
    sort(v.begin(),v.end(),cmp);
    knapsack(cap,v);




    return 0;
}
