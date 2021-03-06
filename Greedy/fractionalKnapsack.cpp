#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class item
{
    public:
    int weight;
    int profit;
    int itemNo;
    float addedAmtInKnapsack;
    item(int no,int w,int p)
    {
        weight=w;
        profit=p;
        addedAmtInKnapsack=0;
        itemNo=no;
    }
    item()
    {    
        weight=0;
        profit=0;
        addedAmtInKnapsack=0;
    }

};

bool comparator(item item1,item item2)
{
    return (float)item1.profit / item1.weight > (float)item2.profit / item2.weight; // sorting in ascending order i.e only swap when the expression is true
}

// fractional knapsack , sort items based on profit by weight
// add item fully  if curKnapSackW+ w[i] <= W else if curKnapSackW+ w[i] > W then add fractionally
int main()
{
    int n;
    cout<<"Enter the number of items in knapsack"<<endl;
    cin>>n;
    item* items=new item[n];
    int capacity;
    cout<<"Enter the capacity of knapsack"<<endl;
    cin>>capacity;
cout<<"Enter the item no , weight & profit of each item"<<endl;

for(int i=0;i<n;i++)
{
    int itemNo,weight,profit;
    cin>>itemNo>>weight>>profit;
    item t1(itemNo,weight,profit);
    items[i]=t1;
}

// sorting based on profit/weight of each item
sort(items,items+n,comparator);
cout<<"After sorting"<<endl;
for(int i=0;i<n;i++)
{
    cout<<items[i].itemNo<<" ";
}
int curCapacity=0;
int profit=0;

for(int i=0;i<n&& curCapacity<capacity;i++)
{
    if(items[i].weight+curCapacity <=capacity)
    {
        items[i].addedAmtInKnapsack=1; // i.e taking full item
        profit+=items[i].profit;
        curCapacity+=items[i].weight;
    }
    else{
        // => Item cannnot be added fully and needs to be added fractionally
        int amtCanBeAdded=capacity-curCapacity;
        float fraction= (float)amtCanBeAdded/items[i].weight;
        items[i].addedAmtInKnapsack=fraction;
        profit+=items[i].profit*fraction;
        capacity+=amtCanBeAdded;
    }

}

cout<<"Max Profit "<<profit<<endl;
cout<<"Each item added in knapsack"<<endl;
for(int i=0;i<n;i++)
{
    cout<<items[i].itemNo<<" "<<items[i].addedAmtInKnapsack<<endl;
}

}
/*




*/