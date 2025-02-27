#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int lb, int rb, int &cmp, int &swp) {
    srand(time(0)); // Seed the random number generator
    // Select a random index for the pivot
    int pid = rand() % (rb - lb + 1) + lb;
    int pivot = arr[pid];
    
    // Swap pivot with the first element (so it will be in the right place later)
    swap(arr[lb], arr[pid]);
    swp++;
    
    int s = lb + 1;  // Start pointer
    int e = rb;      // End pointer
    
    while (s <= e) {
   
        while (s <= rb && arr[s] <= pivot) {
            cmp++;
            s++;
        }
        // Move the end pointer to the left until we find an element smaller than the pivot
        while (e >= lb && arr[e] > pivot) {
            cmp++;
            e--;
        }
        // If start pointer is still less than end pointer, swap elements
        if (s < e) {
            swap(arr[s], arr[e]);
            swp++;
        }
    }

    // Swap the pivot into its correct position
    swap(arr[lb], arr[e]);
    swp++;
    
    return e; // Return the pivot index
}
void  quick_sort(vector<int>&arr,int s,int e,int &cmp,int &swp){
    if(s >= e)return;
    int part = partition(arr,s,e,cmp,swp);
    quick_sort(arr,s,part-1,cmp,swp);
    quick_sort(arr,part+1,e,cmp,swp);

}
int main(){
int n;
cout<<"enter size of array:"<<endl;
cin>>n;;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];

}


int cmp = 0,swp = 0;
quick_sort(arr,0,n-1,cmp,swp);
cout<<"sorted array is"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }

cout<<"number of comparisons: "<<cmp<<endl;
cout<<"total no of swaps are:"<<swp<<endl;


    return 0;
}
