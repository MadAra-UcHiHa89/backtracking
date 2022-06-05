#include<iostream>
#include<algorithm>
using namespace std;

int numberOfSolutions=0; // Global Variable for storing the number of solutions

// row-> row where the wueen needs to be placed , col -> the col where we want to place the queen
// n-> size of board
bool isSafe(bool** board,int row,int col,int n)
{
// checking for column if its safe to place in that column
for(int i=0;i<n;i++)
{
    if(board[i][col]==true)
    {
        return false; /// => another uqeen is already placed in that column thus we cannot place it.
    }
}

// now checking upper left diagonal & upper right diagonal (no need for lower digonals since uqeen are only placed in rows above the curennt row)

// upper left diagonal
for(int i=row,j=col;i>=0 && j>=0;i--,j--) // moving upper diagonal
{
  if(board[i][j])
  {
      return false; // => queen is attacing from upper left diagonal
  }
}

// upper right diagonal
for(int i=row,j=col;i>=0 && j<n;i--,j++) // moving row back col forward hence upper right diagonal
{
if(board[i][j])
{
    return false ; // => queen is attacing from upper right diagonal
}
}
return true; // => queen can be placed in that row and column since no other queen is attacing from that row and column

}

// Placing queen in ror : row , n -> size of rows
void nQueens(bool** board,int row,int n)
{
if(row>=n)
{
    numberOfSolutions++;
    cout<<"Solution "<<numberOfSolutions<<" : "<<endl;
 // => Queens have been placed successfully in all n rows 
 for(int i=0;i<n;i++)
 { cout<<"row "<<i<<" : ";
     for(int j=0;j<n;j++)
     {
        if(board[i][j])
        {
           cout<<"Q ";
        }
        else{
            cout<<"- ";
        }
     }
     cout<<endl;
 }
 cout<<endl;
return ;
}
// => Alll rows havent been filled with queens Thus we'll check 
// For each column if its safe to place the queen there , if yes then we'll place the queen in that column then fill next row , then after recursino call
// remove queen from there i.e backtrack 

for(int i=0;i<n;i++)
{
 if(isSafe(board,row,i,n)) // safe to place queen in that column of the row:row
 {
  board[row][i]=true; // placing the queen
  nQueens(board,row+1,n); // Now queen placed in cur row no need to plcae in other row
    board[row][i]=false; // backtracking
 }
}

}

int main()
{
    int n;
    cout<<"Enter the number of queens"<<endl;
    cin>>n;
    bool** board=new bool*[n];
    for(int i=0;i<n;i++)
    {
        board[i]=new bool[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=false;
        }
    }

     nQueens(board,0,n);

    for(int i=0;i<n;i++)
    {
        delete [] board[i];
    }
    delete [] board;
}