#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int numberOfSolutions=0; // Global Variable for storing the number of solutions


//Method-1 starting from 1st element i.e going from left to right in set 
void subSetSum(int sum,int i,int numberOfElements,vector<int> solutionVector,int* set)
{
    if(sum==0) // => This combination of elements is a solution
    {
        numberOfSolutions++;
        cout<<"Solution "<<numberOfSolutions<<" : "<<endl;
        cout<<"{ ";
        for(int i=0;i<solutionVector.size();i++)
        {
            cout<<solutionVector[i]<<" ";
        }
        cout<<" }";
        cout<<endl;
        return ;
    }
    if(sum<=0 || i>=numberOfElements)
    {
        return;
    }

    if(i>=numberOfElements)
    {
        return; // => Out of bound
    }

    vector<int> solutionVector1; // Copying the current solutions to the new vector
    vector<int> solutionVector2; // Copying the current solutions to the new vector
    for(int i=0;i<solutionVector.size();i++)
    {
        solutionVector1.push_back(solutionVector[i]);
        solutionVector2.push_back(solutionVector[i]);
    }
    // Incluing the current element in the solution vector 1
    solutionVector1.push_back(set[i]);
    subSetSum(sum-set[i],i+1,numberOfElements,solutionVector1,set); // sum-set[i] => current element at index i in set is included hence reduce um , i+1, => move to next element, solutionVector1 => include the current element in the solution vector

    // Excluding / not taking current element in the solution
    subSetSum(sum,i+1,numberOfElements,solutionVector2,set);

    return ;
}

// Method2 starting from last element & going to first 
// In this approach we are starting from the last element and moving to the first element in set and including & excluding the element
void subSetSum(int* set,int numberOfElements,int sum, vector<int> solution)
{
    if(sum==0  ) // => combination of elements is a solution
    {
        numberOfSolutions++;
        cout<<"Solution "<<numberOfSolutions<<" : "<<endl;
        cout<<"{ ";
        for(int i=0;i<solution.size();i++)
        {
            cout<<solution[i]<<" ";
        }
        cout<<" }";
        cout<<endl;
        return ;
    }
    if(numberOfElements<0)
    {
        return ;
    }
    vector<int> solution1; // Copying the current solutions to the new vector
    vector<int> solution2; // Copying the current solutions to the new vector
    for(int i=0;i<solution.size();i++)
    {
        solution1.push_back(solution[i]);
        solution2.push_back(solution[i]);
    }
    // Including the current element in the solution vector 1
    solution1.push_back(set[numberOfElements]);
    subSetSum(set,numberOfElements-1,sum-set[numberOfElements],solution1); // sum-set[i] => current element at index i in set is included hence reduce um , i+1, => move to next element, solutionVector1 => include the current element in the solution vector
    subSetSum(set,numberOfElements-1,sum,solution2);// Excluding / not taking current element in the solution
    return ;
}

int main()
{
    int sum,numberOfElemenets;
    cout<<"Enter the number of elements in the set"<<endl;
    cin>>numberOfElemenets;
    int* set=new int[numberOfElemenets];
    cout<<"Enter the elements of the set"<<endl;
    for(int i=0;i<numberOfElemenets;i++)
    {
        cin>>set[i];
    }

    cout<<"Enter the sum"<<endl;
    cin>>sum;
    vector<int> solutionVector;
    subSetSum(sum,0,numberOfElemenets,solutionVector,set);

// starting from the last element and moving to the first element in set and including & excluding the element hence passing last element;s index
    // subSetSum(set,numberOfElemenets-1,sum,solutionVector);


    delete [] set;
}