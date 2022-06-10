#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// Basically we need to fit as many items as possible without exceeding capacity container
// So we sort based on weight of items and fill it until item[i].weight > capacity then we stop

class item
{
public:
string name;
int weight;
item()
{

}

};

bool comparator(item item1,item item2)
{
    return item1.weight < item2.weight; // sorting in ascending order i.e only swap when the expression is true
}

int main()
{
    int n;
    cout<<"Enter the number of items"<<endl;
    cin>>n;
    item* items=new item[n];

    cout<<"Enter the name & weight of each item"<<endl;
    for(int i=0;i<n;i++)
    {
        string name;
        int weight;
        cin>>name>>weight;
        item t1;
        t1.name=name;
        t1.weight=weight;
        items[i]=t1;
    }

    sort(items,items+n,comparator);// sorting in ascending order of weight
    int capacity;
    cout<<"Enter the capacity of container"<<endl;
    cin>>capacity;
    int itemsAdded=0;// Since if all items added and still curCapacity < capacity then stop
    int curCapacity=0;
    vector<item> itemsAddedVector;
   for(int i=0;i<n && curCapacity<capacity;i++)
   {
       if(items[i].weight+curCapacity <= capacity)
       {
           curCapacity+=items[i].weight;
           itemsAdded++;
           itemsAddedVector.push_back(items[i]);
       }
       else
       {
           break; // => item cannot be added and all further items have greater weight hence cannot be added
       }
   }
   cout<<"No of Items added are"<<itemsAdded<<endl;
   for(int i=0;i<itemsAddedVector.size();i++)
   {
         cout<<itemsAddedVector[i].name<<" ";
   }

    delete [] items;
}

/*
4

i1 2
i2 3
i3 4
i3 5

5

Expected output: i1 i2
Ouput: i1 i2
*/

