#include<iostream>
#include<set>
#include<iterator>
using namespace std;

// First we sort sets in increasing order of cost and then select sets such that 
// Basically we have a universal set , and we select that set which has max elemenst belonging in U , I.E 
// i.e intersection is maximum S intersection U is max , then we select that set and we 
// remove those elemnst in S from U and repeat the process until U beomes empty


class subset
{
    public:
    int cost;
    set<int> elements;
    string subsetName;
    bool status; // true => slected , false => not selected
    subset()
    {
        status=false;

    }
};

bool comparator(subset s1,subset s2)
{
    return s1.cost < s2.cost; // sorting in ascending order i.e only swap when the expression is true
}

int intersection(set<int> U,set<int> S)
{
    int commonElements=0;
    set<int>::iterator uItr;
    set<int>::iterator sItr;
    for(sItr=S.begin();sItr!=S.end();sItr++)
    {
        /// Each element of Set S is checked over each element of U
        for(uItr=U.begin();uItr!=U.end();uItr++)
        {
            if(*uItr==*sItr)
            {
                commonElements++;
                break;
            }
        }
    }
    return commonElements; 
}

bool allSelected(int* status,int n) // To check if all sets have been selected (Since there may be case when even after selecting all subsets , U wil not be empty i.e all elements arent included)
{
    for(int i=0;i<n;i++)
    {
        if(status[i]==0) // => a set which hasn't been selected yet
        {
            return false;
        }
    
    }
    return true;
}

// So everytime we want to select a set we'll go through all unincluded sets 
// and select that set which has max elements in intersection with U
// then remove those elements from U and repeat the process until U beomes empty
int main()
{
 int n;
 cout<<"Enter the number of elements in uinversal set"<<endl;
 cin>>n;
 set<int> U;
 cout<<"Enter the elements of universal set"<<endl;
 for(int i=0;i<n;i++)
 {
     int element;
     cin>>element;
     U.insert(element); //adding element in set U
 }
 int numberOfSubsets;
 cout<<"Enter the number of subsets"<<endl;
 cin>>numberOfSubsets;
 subset* subsets=new subset[numberOfSubsets];
 cout<<"Enter the name , cost , number of element in subset &  elements of subset"<<endl;
 for(int i=0;i<numberOfSubsets;i++)
 {
     string name;
     int cost;
     int m;
     cin>>name>>cost>>m;
     subsets[i].cost=cost;
     subsets[i].subsetName=name;
     for(int j=0;j<m;j++)
     {
            int element;
            cin>>element;
            subsets[i].elements.insert(element);
     }
 }

 // sorting the subsets based on cost 
 sort(subsets,subsets+numberOfSubsets,comparator);

int cost=0;
int counter=0;
 while(U.size()!=0 && counter<numberOfSubsets) // repeat it until U is empty && we'll only have to do it at max number o sets times since at each iteration we are selceting a set
 {
     // we select that set which has max elements in intersection with U
     int maxElementsInIntersection=0;
     int selectedSubsetIndex;
     set<int> selectedSubset;
     for(int i=0;i<numberOfSubsets;i++)
     {
         if(subsets[i].status==false) // => if the set has not been selected yet
         { // So we'll only choose from sets which have not been selected yet
             int commonElements=intersection(U,subsets[i].elements);
             if(commonElements>maxElementsInIntersection)
             {
                 maxElementsInIntersection=commonElements;
                 cout<<"maxElementsInIntersection"<<maxElementsInIntersection<<endl;
                 selectedSubsetIndex=i;
                 
             }
             
         }
     }
     // Thus we get the element with max elements in intersection with U starting with min cost
     // now we remove those elements from U and repeat the process until U beomes empty
     // & set that element's status to true i.e it has been selected
     subsets[selectedSubsetIndex].status=true;
     for(set<int>::iterator itr=subsets[selectedSubsetIndex].elements.begin();itr!=subsets[selectedSubsetIndex].elements.end();itr++)
     {
         U.erase(*itr); // remove element from U with value *itr
     }
     counter++;

 }

 // => Now we have selected subsets whose Union is U
cout<<"Subsets selected are:"<<endl;
 for(int i=0;i<numberOfSubsets;i++)
 {
     if(subsets[i].status)// => selected subset
     {
         cout<<subsets[i].subsetName<<" "<<"Status: "<<subsets[i].status<<endl;
         cost+=subsets[i].cost;
     }
 }
 
 cout<<endl<<"Total cost is "<<cost<<endl;


 delete [] subsets;

}

/*

5

1 2 3 4 5

3

S1 5 3 4 1 3
S2 10 2 2 5
S3 3 4 1 4 3 2



*/