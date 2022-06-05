#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Checking if the vertex: vertex has edge from vertex at curI-1 in cycleArr , & it isnt already present in cyclic array
bool isSafe(int** graph,int curI,int* cycleArr,int vertex,int numberOfVertices)
{
    if(graph[cycleArr[curI-1]][vertex]==0)
    {
      return false; //=> No edge bw vertex at curI-1 and vertex we want to place => hence we cannot place the vertex
    }

    // => There's an edge
    for(int i=0;i<numberOfVertices;i++)
    {
        if(cycleArr[i]==vertex)
        {
            return false; // => vertex is already present in cycleArr so cannot put it
        }
    }

// Check if filling last element in cucleArr
    if(curI==numberOfVertices-1) // i.e last element in the cyclearr => we need to check if there's an edge bw vertex & first vertex i.e 0
    {
        if(graph[vertex][cycleArr[0]]==0)
        {
            return false; // => No edge bw vertex and first vertex in cycleArr
        }
    }

    return true; // if all else true => we can place the vertex

}

void HamiltonianCycle(int** graph,int numberOfVertices,int* cycleArr,int curI,vector<int> curSolution, vector< vector<int> >& solutions,int* availableVertices)
{
    if(curI==numberOfVertices) // =>  all elemenst of the array have been filled 
    {
        // => can insert the current solition to solutions
        solutions.push_back(curSolution);
        return ; 
    }

    // => Cycle isnt complete since all elemenst havent been filled
    //checking for all avaiable vertices  if the vertex can be inserted at that index  or not
    for(int i=0;i<numberOfVertices-1;i++)
    { 
       
       if(isSafe(graph,curI,cycleArr,availableVertices[i],numberOfVertices)) // => we can place the vertex at the index
       { 
            vector<int> curSolution1;
           // => inserting the vertex into the solution vector
           for(int j=0;j<curSolution.size();j++)
           {
               curSolution1.push_back(curSolution[j]);
           }
           curSolution1.push_back(availableVertices[i]); /// inserting current safe vertex
           cycleArr[curI]=availableVertices[i]; // => inserting the vertex into the cycleArr
           HamiltonianCycle(graph,numberOfVertices,cycleArr,curI+1,curSolution1,solutions,availableVertices); // => recursively calling the function
           cycleArr[curI]=-1; // => removing the vertex from the cycleArr
       }

    }
    return ;

}

int main()
{
    int numberOfVertices;
    cout<<"Enter the number of vertices"<<endl;
    cin>>numberOfVertices;
    int** graph=new int*[numberOfVertices];
    for(int i=0;i<numberOfVertices;i++)
    {
        graph[i]=new int[numberOfVertices];
    }
    cout<<"Enter the adjacency matrix"<<endl;

    // Initializing the graph 0 => No edge
  

    // Taking the adjacency matrix as input
    for(int i=0;i<numberOfVertices;i++)
    {  
        for(int j=0;j<numberOfVertices;j++)
        {
            cin>>graph[i][j];
        }
    }

    // Taking 0th vertex as the stating vertex of the cycle
    // Hamiltoninan cycle,  we create number of vertices sized array and 1st element being the start vertex and we fill next elemnst of array , if that elemnet does not occur eralier and and if its connected to the previous element (edge exists)

    int* cycleArr=new int[numberOfVertices];
    for(int i=0;i<numberOfVertices;i++)
    {
        cycleArr[i]=-1; // -1 => not visited / needs to be filled
    }
    cycleArr[0]=0; // 0th element is the starting vertex of the cycle
    int* availableVertices=new int[numberOfVertices-1]; // numberOfvertices -1 since 0 will not be incuded to fill remaining elements of cyclic array
    for(int i=0;i<numberOfVertices-1;i++)
    {
        availableVertices[i]=i+1; // except 0 all can be used
    }


vector<vector<int> > solutions;
vector<int> curSolution;

HamiltonianCycle(graph,numberOfVertices,cycleArr,1,curSolution,solutions,availableVertices); // curI -> 1 since first element / vertex in cycle array is 0
int numberOfSolutions=0;
if(solutions.size()==0)
{
    cout<<"No Hamiltonian Cycle"<<endl;
}
else
{
    cout<<"Hamiltonian Cycle"<<endl;
    for(int i=0;i<solutions.size();i++)
    {
        cout<<cycleArr[0]<<"->";
        for(int j=0;j<solutions[i].size();j++)
        {
            cout<<solutions[i][j]<<"->";
        }
        cout<<cycleArr[0];
        cout<<endl;
    }
}


    for(int i=0;i<numberOfVertices;i++)
    {
        delete [] graph[i];
    }

 delete [] graph;
 delete [] cycleArr;
 delete [] availableVertices;
   
}
/*

0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 0 0


*/