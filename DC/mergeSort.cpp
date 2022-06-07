#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merge(int* arr,int si,int mid,int ei)
{
    // creating a temp array which will store the merged array
    int n=ei-si+1;
    int* temp=new int[n];
    int tempArrIndex=0; // index of element in temp to be filled
    int i,j;
    for(i=si,j=mid+1;i<=mid&&j<=ei;)
    {
        if(arr[i]<arr[j])
        {
            temp[tempArrIndex]=arr[i];
            tempArrIndex++; // so as to fill the next element in temp array
            i++;
        }
        else if(arr[i]>arr[j]) // => secind part element less => put iit int the array
        {
         temp[tempArrIndex]=arr[j];
         tempArrIndex++;
         j++;
        }
        else{
            // => both equal we'll fill from first array
            temp[tempArrIndex]=arr[i];
            tempArrIndex++;
            i++;
        }
    }

    // => One of the array's element has been filled in temp array and we just need to copy remaining elements from other array into temp
    if(i>mid) // => first array fully filled thus copy all from second arr
    {
        for(int k=j;k<=ei;k++)
        {
            temp[tempArrIndex]=arr[k];
            tempArrIndex++;
        }
    }
    else if(j>ei) //  => second array fully filled thus copy all from first arr
    {
        for(int k=i;k<=mid;k++)
        {
            temp[tempArrIndex]=arr[k];
            tempArrIndex++;
        }

    }

    // => Now we have the merged array in temp array
    // copying it in the original array
    for(int k=si,l=0;i<=ei&&l<n;k++,l++)
    {
        arr[k]=temp[l];
    }

    delete [] temp;
}

void mergeSort(int* arr,int si,int ei)
{
    if(si>=ei)
    {
        return ; // since empty array or array with 1 element is already sorted
    }

    int mid=(si+ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
    return ;

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
    mergeSort(arr,0,n-1);
    cout<<"Sorted array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


    delete [] arr;

}