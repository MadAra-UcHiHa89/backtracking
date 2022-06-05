#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// We create graphColour()function taking vertex we want to colour as arhument , if its safe to asiign that 
// vertex with colour  i.e no adjacent vertex has the same colour we assign that colour to that vertex
// and colour the next vertex i.e v+1 until v==nuberOfvertices i.e all vertices are coloured or if a vertex cant be assigned 
// any colour then we return and backtrack try other combination 
// array of colours is used to keep track of the colour of each vertex
// an array of colours which stroes all colours (numbers basicaly) 
// https://www.youtube.com/watch?v=miCYGGrTwFU

int numberOfSolutions=0;

// isSafe to assign vertex:vertex the colour : colour if all adjacent vertics of vertex have different colour than the color: colour
bool isSafe(int** graph,int vertex, int colour,int numberOfVertices,int* assignedColour)
{
    for(int i=0;i<numberOfVertices;i++)
    {
        if(graph[vertex][i]!=0 && assignedColour[i]==colour)
        {
            return false; // i.e adjacent vertex has same colour => that colour cant be assigned
        }
    }
    return true; // If all adjacent vertices have different colour than the color: colour

}

// vertex-> which vertex to colour , graph-> graph matrix , colour-> array of colours , numberOfVertices-> number of vertices
// assignedColourToVertex-> array holding which vertex has been asigned which colour
void graphColour(int** graph,int vertex,int numberOfVertices,int numberOfColours,int* assignedColourToVertex,int* colours)
{
    if(vertex==numberOfVertices) // => all vertices have been coloured and are safe
    {
        // Thus cuurent assignedColourToVertex is a solution
        numberOfSolutions++;
        cout<<"Solution "<<numberOfSolutions<<" : ";
        for(int i=0;i<numberOfVertices;i++)
        {
            cout<<assignedColourToVertex[i]<<" ";
        }
        cout<<endl;
        return ;
        
    }

    //Else  =>  all vertices havent been asiigned colours which are safe
    // => we need to assign vertex : ertex a colour thus loop through all colours and check if its safe to assign that coulour to vertex

    for(int i=0;i<numberOfColours;i++)
    {
        if(isSafe(graph,vertex,colours[i],numberOfVertices,assignedColourToVertex))
        {
            // => The colour can beassigned to that vertex
            assignedColourToVertex[vertex]=colours[i]; // assigning the vertex :vertex colour : colours[i]
            graphColour(graph,vertex+1,numberOfVertices,numberOfColours,assignedColourToVertex,colours); // recursively calling the function for next vertex i.e vertex+1
            assignedColourToVertex[vertex]=-1; // backtracking
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
    for(int i=0;i<numberOfVertices;i++)
    {
        for(int j=0;j<numberOfVertices;j++)
        {
            cin>>graph[i][j]; // 0 => no edge bw vertices
        }
    }

    int numberOfColours;
    cout<<"Enter the number of colours"<<endl;
    cin>>numberOfColours;

    int* colours=new int[numberOfColours];
    for(int i=0;i<numberOfColours;i++)
    {
        colours[i]=i+1; // 1st colour is 1 , 2nd colour is 2 and so on
    }

    int* asssignedColourToVertex=new int[numberOfVertices]; // array holding which colour is assigned to which vertex

   for(int i=0;i<numberOfVertices;i++)
   {
         asssignedColourToVertex[i]=-1; // -1 => no colour is assigned to that vertex
   }

graphColour(graph,0,numberOfVertices,numberOfColours,asssignedColourToVertex,colours);


    for(int i=0;i<numberOfVertices;i++)
    {
        delete [] graph[i];
    }
    delete [] graph;
    delete [] colours;
    delete [] asssignedColourToVertex;
}

/*
number of vertices: 4
matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
number of colours 3

*/