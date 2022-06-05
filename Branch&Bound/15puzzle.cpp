


// https://www.youtube.com/watch?v=osACXZAyb94


// a -> input matrix , t -> target matrix , check() compares the two matrices and returns true if they are equal
// we run while loop until input matrix and traget matrix are equal
// in loop First we find the position of blank space in input matrix
// Now after finding position of blank matrix we move in all four directions i.e up down left right (i.e move the blank space) (if its possible to move in that direcion)
// The matrix we get from each move is stored in temp matrix and we calculate the cost of each matrix individually (c(x)=f(x)+h(x)) f(x)-> height from top of tree kept track of by keeping a loop variable(i.e how many times this process is
// done that's the height from roor) h(x)-> number of mismatched non blank tiles as comapred to target matrix
// So which ever move has least cost we choose that move and make it the current matrix , we create another matrix r which stores the matrix with lowest cost. (Since we are doin it iteratively ) So if in cur move's cost < previous move's cost then r will be updated to the temp matrix.
// After all move's are done for curent stage we set input matrix a to r matrix
// and repeat the process until we reach the target matrix i.e check(current Matrix , target Matrix ) returns true

#include<iostream>
#include<vector>
using namespace std;


bool check(int** input,int** target,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(input[i][j]!=target[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// fx -> distance from root node (i.e the loop vairable which is initialized to 0)
int cost(int** input,int** target,int n,int fx)
{
    int mismatches=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(input[i][j]!=target[i][j] ) // Since couting  non blank tiles  mismatches & 0 -> indocates blank space/tile
            {
                mismatches++;
            }
        }
    }
    return fx+mismatches; // since c(x)=f(x)+h(x) , h(x)-> non blank mismatches

}


int main()
{
    int n;
    cout<<"Enter the size of puzzle"<<endl;
    cin>>n;

    int** inputMatrix=new int*[n];
    int** targetMatrix=new int*[n];
    int** intermediateMatrix=new int*[n];
    int** tempMatrix=new int*[n];
    for(int i=0;i<n;i++)
    {
        inputMatrix[i]=new int[n];
        targetMatrix[i]=new int[n];
        intermediateMatrix[i]=new int[n];
        tempMatrix[i]=new int[n];
    }
    cout<<"Enter the input matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>inputMatrix[i][j];
        }
    }
    cout<<"Enter the target matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>targetMatrix[i][j];
        }
    }

    int fx=0; // Looop variable / height of tree
    

    while(!check(inputMatrix,targetMatrix,n))
    {   int Dmin=INT_MAX;// MINIMUM COST OF EACH MOVE INITIALIAZTION
        int d; // just a temp variable to store cost of each move
        int blankRow=0,blankCol=0;// blank tile's position in input matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(inputMatrix[i][j]==0) // blank tile represented by 0 
                {
                    blankRow=i;
                    blankCol=j;
                    break;
                }
            }
        }
        // Now we'll move blank tile in all four directions
        // Moving up

        // first copy the input matrix to temp matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                tempMatrix[i][j]=inputMatrix[i][j];
            }
        }
        // Now moving up i.e swapping blank tile with tile above it i.e same column , row-1
        // only if its not the top row
        if(blankRow!=0)
        {
            tempMatrix[blankRow][blankCol]=tempMatrix[blankRow-1][blankCol]; // copying above tile's value to blank tile
            tempMatrix[blankRow-1][blankCol]=0; // blank tile value is set to 0 i.e of above tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    intermediateMatrix[i][j]=tempMatrix[i][j];
                }
            }
        }

        // Moving down
        // first copy the input matrix to temp matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                tempMatrix[i][j]=inputMatrix[i][j];
            }
        }
        // Now moving down i.e swapping blank tile with tile below it i.e same column , row+1
        // only if its not the last row
        if(blankRow!=n-1) 
        {
            tempMatrix[blankRow][blankCol]=tempMatrix[blankRow+1][blankCol]; // copying below tile's value to blank tile
            tempMatrix[blankRow+1][blankCol]=0; // blank tile value is set to 0 i.e of below tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    intermediateMatrix[i][j]=tempMatrix[i][j];
                }
            }
        }

        // Moving left
        // first copy the input matrix to temp matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                tempMatrix[i][j]=inputMatrix[i][j];
            }
        }
        // Now moving left i.e swapping blank tile with tile left it i.e same row , col-1
        // only if its not the first col
        if(blankCol!=0)
        {
            tempMatrix[blankRow][blankCol]=tempMatrix[blankRow][blankCol-1]; // copying left tile's value to blank tile
            tempMatrix[blankRow][blankCol-1]=0; // blank tile value is set to 0 i.e of left tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    intermediateMatrix[i][j]=tempMatrix[i][j];
                }
            }
        }

        // Moving right 
        // first copy the input matrix to temp matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                tempMatrix[i][j]=inputMatrix[i][j];
            }
        }
        // Now moving right i.e swapping blank tile with tile right it i.e same row , col+1
        // only if its not the last col since we cannot move right
        if(blankCol!=n-1)
        {
            tempMatrix[blankRow][blankCol]=tempMatrix[blankRow][blankCol+1]; // copying right tile's value to blank tile
            tempMatrix[blankRow][blankCol+1]=0; // blank tile value is set to 0 i.e of right tile

        }
         d=cost(tempMatrix,targetMatrix,n,fx);// cost of moving up
        if(d<Dmin) // current move has least cost hence it will be the inetrmediate matrix
        {
            Dmin=d;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    intermediateMatrix[i][j]=tempMatrix[i][j];
                }
            }
        }

        // Now setting the intermediate matrix as input matrix (i.e matrix due to the best possible move) // Also printing the intermedite matrix
        cout<<"Intermediate matrix "<<fx+1<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                inputMatrix[i][j]=intermediateMatrix[i][j];
                cout<<inputMatrix[i][j]<<" ";
            }
            cout<<endl;
        }

     fx++; // incrementing loop variable i.e height of tree after each iteration
    }
// After we ae out of the loop => we have reached the target matrix

cout<<"Target matrix"<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<targetMatrix[i][j]<<" ";
    }
    cout<<endl;
}







    for(int i=0;i<n;i++)
    {
        delete [] inputMatrix[i];
        delete [] targetMatrix[i];
        delete [] intermediateMatrix[i];
        delete [] tempMatrix[i];
    }
    delete [] inputMatrix;
    delete [] targetMatrix;
    delete [] intermediateMatrix;
    delete [] tempMatrix;
}


/*
input matrix:
1
2
3
4
5
6
0
8
9
10
7
11
13
14
15
12


target matrix:
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0



*/