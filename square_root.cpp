//Square root using binary search
#include<iostream>
using namespace std;
int sqrt(int n){
    int s=0;
    int e=n;
    int mid =((s/2)+(e/2));
    int ans=-1;
    while (s<=e)
    {    int square =mid*mid;//suare formula
        if (square==n)//yahan pr hum check kar rahe hai ki square humara agar n ke equal hai to return mid kar do
        {
            return mid;
        }//yahan pr agar square chota hai n se to hum start ko mid+1 kar de rahe hai
        else if (square<n)
        {
            ans=mid;//mid ko hum ans me store kar denge
            s=mid+1;
        }//agar humare square ki value jyada hai n se to end ko mid -1 kar denge
        else{
            e=mid-1;
        }
        mid=((s/2)+(e/2));
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number to  find a square root of ="<<endl;
    cin>>n;
    cout<<"the square root of a number is = "<<sqrt(n);

    return 0;
}