#include <bits/stdc++.h>
using namespace std;
int bs(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == 1)
            return mid;
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "enter size of array:" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "enter elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mid = bs(arr);
    if (mid == -1)
    {
        cout << "no ones in array" << endl;
        return 0;
    }
    while (mid < arr.size() && arr[mid] == 1)
    {
        mid++;
    }
    cout << "TOTAL ONES ARE:" << mid;

    return 0;
}