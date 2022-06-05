#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// curW-> current weight of knapsack , curP-> current profit of knapsack, 
// maxW-> max weight of knapsack , numberOfElements -> index of last element in set,(going from right to left in set)
// solution 2-d vector containing all soltions i.e  al possible combination where all elemenst are considered and curW<=maxW
// curSolution -> current solution vector since we need to add solution vector to final solution vector once all elemenst are considered i.e numberOfElement ==-1 i.e all elemenst considered & curW<=MaxW
//In solution vector we are strooing the index of elemnst included in the knapsack
void knapsack(int curW,int curP , int maxW,int numberOfElements,int* profit,int* weight,vector< vector<int> >& solution,vector<int> curSolution)
{

  if(numberOfElements ==-1 && curW<=maxW)
  {
      // Add the current solution to the final solution vector
      solution.push_back(curSolution);
      return ;
  }
  if(numberOfElements<0)
  {
        return ; // All elements traversed & curW of All eleenst in knapsac isnt less than or equalt to maxW hence skip
  }

  if(curW>maxW) // => no point in exploring further
  {
      return ;
  }

  // Including the current element in the solution vector
    vector<int> curSolution1;
    vector<int> curSolution2;
    for(int i=0;i<curSolution.size();i++)
    {
        curSolution1.push_back(curSolution[i]);
        curSolution2.push_back(curSolution[i]);
    }
    curSolution1.push_back(numberOfElements); // including the current element index in the solution vector i.e in the knapsack

// including the current element in the solution vector
    knapsack(curW+weight[numberOfElements],curP+profit[numberOfElements],maxW,numberOfElements-1,profit,weight,solution,curSolution1); // curW+weight[numberOfElements] => current weight of knapsack is increased by weight of current element(Since it has been included)
    // and numberOfElements is decreased by 1 i.e. we are considering next element in set i.e movinf left
    // curP+profit[numberOfElements] => current profit of knapsack is increased by profit of current element(Since it has been included)
    // curSolution1 => include the current element in the solution vector

// exclduing the current element in the solution vector
    knapsack(curW,curP,maxW,numberOfElements-1,profit,weight,solution,curSolution2); 
    // kust move left without including the current element in the solution vector 
return ;
}

int main()
{
    int numberOfElements;
    cout<<"Enter the number of elements"<<endl;
    cin>>numberOfElements;
    cout<<"Enter the Weight of each element"<<endl;
    int* weight=new int[numberOfElements];
    int* profit=new int[numberOfElements];
    for(int i=0;i<numberOfElements;i++)
    {
        cin>>weight[i];
    }
cout<<"Enter the profit of each element"<<endl;
    for(int i=0;i<numberOfElements;i++)
    {
        cin>>profit[i];
    }
int maxW;
cout<<"Enter the max weight of knapsack"<<endl;
cin>>maxW;
vector< vector<int> > solution; // Will contain all feasible soltions we'll traverse through it and find the max profit solution
vector<int> curSolution; // Will contain the current solution we'll traverse through it and find the max profit solution
knapsack(0,0,maxW,numberOfElements-1,profit,weight,solution,curSolution);
int maxProfit=-1;
vector<int> maxSolution; //Storig the max profit solution vector
for(int i=0;i<solution.size();i++)
{  int curProfit=0;
    for(int j=0;j<solution[i].size();j++)
    {
       curProfit+=profit[solution[i][j]]; //Since in solution vector we are strooing the index of elemnst included in the knapsack
    }
    if(curProfit>maxProfit)
    {
        maxProfit=curProfit;
        maxSolution=solution[i]; // assigning the max profit solution vector as current solution vector
    }
}

cout<<"Max profit is "<<maxProfit<<endl;
cout<<"The solution vector is "<<endl;
for(int i=0;i<maxSolution.size();i++)
{
    cout<<" "<<maxSolution[i]+1; // Element index is incremented by 1 since we are stroing the index of element in the solution vector
}

    delete [] weight;
    delete [] profit;
}