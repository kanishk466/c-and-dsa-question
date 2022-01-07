#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid)
{
    int painterCount = 1;//suru me humare pass painter 1 hoga
    int partSum = 0;//yahan pr partiion sum naam ka variable taaki hum partion ka sum store kara sake
    //
    for (int i = 0; i < n; i++)
    {
        if (partSum+arr[i]<=mid)//check karenge ki partition  or array of index ka sum agar mid ki value se chota hai to //
            //aap partion or array of index ko jod do or usko partsum me store kara lo
        {
            partSum+=arr[i];
        }
        //upar waali condition fail hone me hum 
        //painter ki value badha denge //
        
  
        else
        {   // pahle humari painter ki value 1 thi to  ab wah  2 ho jayegi 
            painterCount++;
            //check karenge ki agar painter ki value input painter ki value se jyada hai or agara array of index ki value jyada hai mid se to return false kar do.
            if (painterCount>m || arr[i]>mid)
            {
                return false;
            }
            //upar waali condition agar fail ho jaati hai tab aap array of index ki value partition me store kara lo
            else
            {
              partSum =arr[i];
            }
        }
    }
    return true;
}
//is question me hum search space logic use kar rahe hai taaki hum binary search laga sake
int painterPartition(int arr[], int n, int m)
{
    //yahan pr hum initialise kar rahe start of index  
    int s = 0;
    int sum = 0;
    //humne ek sum naam ka variable banaya hai jo ki 0 store kia hai
    //aur ek loop cahla dia hai jo ki array of index or sum ki value ko add karega or sum me store karega
    //kyu ? humne sum ko array of index joda hai, kyu ki humara end is array me sum of array hoga
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;//isko hum mid ki value store karne ke liye banaye haia
    while (s <= e)//humara loop tab tak chalega tab tak humara s ki value se badi ho jaye
    {
        if (isPossible(arr, n, m, mid))//possible solution me hummid ki value store kara lenge
        {//or mid ko left me le jayenge
            ans = mid;
            e = mid - 1;
        }
        else
        {//agar possible solution nhi hai to mid ko right me le jao
            s = mid + 1;
        }
        mid = s + (e - s) / 2;//mid ko phir se upadte kar do // or ans return kar do
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
