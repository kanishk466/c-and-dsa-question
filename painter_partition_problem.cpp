#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid)
{
    int painterCount = 1;
    int partSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (partSum+arr[i]<=mid)
        {
            partSum+=arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount>m || arr[i]>mid)
            {
                return false;
            }
            else
            {
              partSum =arr[i];
            }
        }
    }
    return true;
}
int painterPartition(int arr[], int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int arr[] = {  5,10, 15,20 };
    int n = sizeof(arr) / sizeof(int);
    int m;
    cout << "enter the value" << endl;
    cin >> m;
    cout<<"the minimum partition is ="<<painterPartition(arr,n,m)<<endl; 
    return 0;
}