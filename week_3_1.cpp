#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    int cmp = 0, swp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int mi_index = i;
        for (int j = i + 1; j < n; j++)
        {
            cmp++;
            if (arr[j] < arr[mi_index])
                mi_index = j;
        }
        swp++;
        swap(arr[i], arr[mi_index]);
    }
    cout << "array sorted using selection sort" << "and Total Comparisons are:" << cmp << "total swaps are:" << swp << endl;
}
void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    int cmp = 0, swp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            cmp++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swp++;
            }
        }
    }
    cout << "array sorted using Bubble sort" << "and Total Comparisons are:" << cmp << "total swaps are:" << swp << endl;
}
void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    int cmp = 0, swp = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        cmp++;
        while (j >= 0 && arr[j] > key)
            5

            {
                arr[j + 1] = arr[j];
                swp++;
                cmp++;
                j--;
            }

        arr[j + 1] = key;
    }
    cout << "sorting done using insertion sort" << "total comparisons are:" << cmp << "total insertionsn are:" << swp << endl;
}
void print_array(vector<int> arr)
{
    cout << "printing array" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
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
    insertion_sort(arr);
    // selection_sort(arr);
    print_array(arr);

    return 0;
}