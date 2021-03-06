#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

bool allExplored(bool* explored,int n)
{
    for(int i=0;i<n;i++)
    {
        if(!explored[i])
        {
            return false; // => A vertex hasnt been explored thus not all vertices have been explored
        }
    }
    return true;
}

int indexOfMinCostUnxploredVertex(bool* explored,int* costFromSource,int n)
{
    int minCost=INT_MAX;
    int minCostVertexIndex=-1;
    for(int i=0;i<n;i++)
    {
        if(!explored[i]) // => considering unexplored vertices
        {
            if(costFromSource[i]<minCost) // and min cost
            {
                minCost=costFromSource[i];
                minCostVertexIndex=i;
            }
        }
    }
        
    return minCostVertexIndex;
}

int main()
{
    int n;
    cout<<"Enter the number of vertices in graph"<<endl;
    cin>>n;
    int** graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];

    }
    cout<<"Enter the adjacency matrix of the graph"<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    int sourceVertex;
    cout<<"Enter the source vertex"<<endl;
    cin>>sourceVertex; // 
    int* costFromSource=new int[n]; // Array storing cost to reach from source to that vertex
    for(int i=0;i<n;i++)
    {
        if(i==sourceVertex)
        {
            costFromSource[i]=0; // i.e cost from source to source is 0
        }
        else
        {
            costFromSource[i]=INT_MAX; // initializing cost to reach from source to all other vertices to INT_MAX
        }
    }

   bool* explored=new bool[n]; // Array storing whether a vertex is explored or not
    for(int i=0;i<n;i++)
    {
       explored[i]=false; // => initially all vertices are unexplored
    }
     // So we select the vertex with min cost from unexplored vertices and perform relaxation on its adjacent vertices i.e if cost[i]+edge[i][j]<cost[j] then we update it.
     // we do this until all vertices are explored is 

 while(!allExplored(explored,n))
 {
     int minCostVertexIndex=indexOfMinCostUnxploredVertex(explored,costFromSource,n);
     explored[minCostVertexIndex]=true; // => we mark the vertex as explored
     for(int i=0;i<n;i++)
     {
         // Performing relaxation on all adjacent vertices of min cost vertex
         if(graph[minCostVertexIndex][i]!=0) // => adjacent vertex
         {
             if(costFromSource[minCostVertexIndex]+graph[minCostVertexIndex][i]<costFromSource[i]) // if relxation can be dome
             {
                 costFromSource[i]=costFromSource[minCostVertexIndex]+graph[minCostVertexIndex][i];
             }
         }
     }
 }

 cout<<"Cost from source vertex to all other vertices"<<endl;
 for(int i=0;i<n;i++)
 {
        cout<<"To :"<<i<<" "<<costFromSource[i]<<" "<<endl;
 }
     

 

    for(int i=0;i<n;i++)
    {
        delete [] graph[i];
    }
    delete [] graph;
    delete [] costFromSource;
    delete [] explored;


}

/*
no of vertices : 9
source 0

 0 4 0 0 0 0 0 8 0 
  4 0 8 0 0 0 0 11 0 
  0 8 0 7 0 4 0 0 2 
  0 0 7 0 9 14 0 0 0 
  0 0 0 9 0 10 0 0 0 
  0 0 4 14 10 0 2 0 0 
  0 0 0 0 0 2 0 1 6 
  8 11 0 0 0 0 1 0 7 
  0 0 2 0 0 0 6 7 0 



*/

