#include<iostream>
#include<algorithm>
using namespace std;

class tape
{
    public:
    int number;
    int readTime;
    tape(int number , int readTime)
    {
        this->number=number;
        this->readTime=readTime;
    }
    tape()
    {

    }
};

bool comparator(tape tape1,tape tape2)
{
    return tape1.readTime<tape2.readTime; // sorting in ascending order i.e only swap when the expression is true
}

// Basically sort taoes in incresing order and then we'll store the tapes in optimal form
// read time is read time of all tapes before + read time of current tape
int main()
{
    int n;
    cout<<"Enter the number of tapes"<<endl;
    cin>>n;
    tape* tapes=new tape[n];
    cout<<"Enter the tape no & read time of each tape"<<endl;
    for(int i=0;i<n;i++)
    {
         int readTime,tapeNo;
         cin>>tapeNo>>readTime;
         tape t1(tapeNo,readTime);
         tapes[i]=t1;
    }

    sort(tapes+0,tapes+n,comparator); // sort in ascending order
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<tapes[i].number<<" ";
    }
    int TotalReadTime=0;
    int retrivalTime=0;
    for(int i=0;i<n;i++)
    {
        retrivalTime+=tapes[i].readTime; // since read time to read a tape is equal to read time of previous tapes + read time of current tape
        cout<<"Tape No "<<tapes[i].number<<" Read Time "<<retrivalTime<<endl;
        TotalReadTime+=retrivalTime;
    }

cout<<"Total read time"<<(float)TotalReadTime/n<<endl;
delete [] tapes;
}

/*

3

1 2
2 5
3 4

*/