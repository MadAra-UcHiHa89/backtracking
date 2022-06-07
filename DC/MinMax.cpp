#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int,int> minMax(int* arr, int si,int ei)
{
    if(si>=ei)
    {
        pair<int,int> p;
        p.first=arr[si];
        p.second=arr[si];
        return p;
    }
    int mid=(si+ei)/2;
    pair<int,int> p1=minMax(arr,si,mid);
    pair<int,int> p2=minMax(arr,mid+1,ei);

    pair<int,int> ans;
    ans.first=max(p1.first,p2.first); // first element of pair is the max element and seci d is the min element;
    ans.second=min(p1.second,p2.second);
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;

    int* arr=new int[n];
  cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    pair<int,int> ans=minMax(arr,0,n-1);
    cout<<"Max element is "<<ans.first<<endl;
    cout<<"Min element is "<<ans.second<<endl;


    delete [] arr;

}