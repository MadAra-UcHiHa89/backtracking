#include<iostream>
#include<algorithm>
using namespace std;

// Basically the grredy choice property is that we select the (which hasnt been included) edge with min weight & inclusion of that edge 
// Should not form a cycle. We do this until Vertices - 1 edges are added then we have the MST
// For checking if edge forms a cycle we'll compare their parents i.e source and detination of vertices of that edge's parent if same parent then 
// addition weill result in a cycle else wont result in a cycle
// => sort all edges in increasing order of weight and then we'll add them one by one in mst by following above and until egdes added are v-1 


// Initailly the parent of vertex is itself 
// recursive function to find parent of vertex


class edge
{
 public:
 int source;
 int destination;
 int weight;
 bool included;
 edge(int source,int destination,int weight)
 {
     this->source=source;
     this->destination=destination;
     this->weight=weight;
     this->included=false;
 }
 edge()
 {
     included=false;
 }
};

bool comparator(edge e1,edge e2)
{
    return e1.weight<e2.weight;
}

// Initailly the parent of vertex is itself 
// recursive function to find parent of vertex
// parent -> array storing parents of all vertices, 
// if parent[vertex]==vertex then parent is found since parent is itslef
// if its differnt i.e parent[vertex]!=vertex then => parent of that vertex is not itself its someone else 
// so we find parent of vertex at parent[vertex] that'll be the parent of vertex 
int findParent(int* parent , int vertex)
{
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    else
    {
        return findParent(parent,parent[vertex]);
    }

}

int main()
{
    int noOfEdges,noOfVertices;
    cout<<"Enter the number of edges & vertices in the graph"<<endl;
    cin>>noOfEdges>>noOfVertices;

    edge* edges=new edge[noOfEdges]; // storing all edges of the graph
    cout<<"Enter the source , destination & weight of edge"<<endl;
    for(int i=0;i<noOfEdges;i++)
    {
        int source,destination,weight;
        cin>>source>>destination>>weight;
        edge e1(source,destination,weight);
        edges[i]=e1;
    }

    // sort the edges based on weight in incerasing order
    sort(edges,edges+noOfEdges,comparator);
    int* parent=new int[noOfVertices]; // array storing parents of all vertices
    for(int i=0;i<noOfVertices;i++)
    {
        parent[i]=i; // initially all vertices are their own parent
    }
    int edgesAdded=0;

    while(edgesAdded!=noOfVertices-1)
    {
        for(int i=0;i<noOfEdges;i++)
        {
            // Selecting edge which hasnt been included yet and whose onclusion doesnt result in a cyle i.e parent[source]!=parent[destination]
            if(edges[i].included==false) // => edge hasnt been inlcuded
            {
               int sourceParent=findParent(parent,edges[i].source);
               int destinationParent=findParent(parent,edges[i].destination);
               if(sourceParent!=destinationParent) // => edge doesnt form a cycle
               {
                   edges[i].included=true;
                   edgesAdded++;
                   parent[sourceParent]=destinationParent; // updating parent of one vertex to be parent of other vertex
                   break;
               }
            }
         }
     }

    cout<<"Edges in the MST are: "<<endl;
    int cost=0;
    for(int i=0;i<noOfVertices;i++)
    {
        if(edges[i].included)
        {
            cout<<edges[i].source<<"->"<<edges[i].destination<<" weight: "<<edges[i].weight<<endl;
            cost+=edges[i].weight;
        }
    }
    
    cout<<"Total cost of MST is: "<<cost<<endl;

    delete [] edges;
    delete [] parent;
}
/*
no of edges 5
no of vertices 4

edges:

0 1 10
1 3 15
2 3 4
2 0 6
0 3 5

*/