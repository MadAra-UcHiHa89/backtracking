#include<iostream>
#include<algorithm>
#include <string_view>
#include<utility>
using namespace std;

// Partitioning wrt lastelement
int partition(int* arr,int si,int ei)
{
    int i=si; // i-> represents the what would be the posisiton of pivot element (here last element) after partitioning
    // We travserse through all element eecpt last element
    // and if element is less than or equal to pivot then we swap the element with elemen at i (since i is index where to left of it are lements less than or equal to pivot and to rightof it are greater )
    //  since that elemnst is less than or equal to pivoit => it should be left of i thus we swap with element at i and increement i  

    int pivot=arr[ei]; // pivot is the last element

    for(int j=si;j<=ei-1;j++) // traversing from start indeex to end index -1 (excluding pivot element )
    {

    if(arr[j]<=pivot) // => element needs to be on left of ith index i.e pivot's left
    {
        int temp=arr[j]; // swapping 
        arr[j]=arr[i];
        arr[i]=temp;
        i++;
    }

    }
    // now swapping pivot element with element at i since i reprensts poisiiton of pivot element after partitioning
    int temp=arr[ei];
    arr[ei]=arr[i];
    arr[i]=temp;
    return i; // i is the position of pivot element after partitioning
}

void quickSort(int* arr, int si,int ei)
{
    if(si>=ei)
    {
        return ; //already sorted
    }
   int pivPos=partition(arr,si,ei);
   quickSort(arr,si,pivPos-1); // will sort left half of the pivot since pivot at correct pos
   quickSort(arr,pivPos+1,ei); // will sort the right half of the pivot
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
    quickSort(arr,0,n-1);
    cout<<"Sorted array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


    delete [] arr;
}
