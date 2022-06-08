#include<iostream>
#include<algorithm>
using namespace std;

// Basically give an amount a already set denominations 
// We start from highest denomination and choose that denomination if , amt >= denomination else we choose the next lower denomination
int main()
{
    int denominations[]={1,2,5,10,20,50,100,500,1000};// we are hard coding denominations 
    // But can take from user just sort in decreasing order and start from highest denomination
    // and do the same procdeure
    int numberOfDenominations=9;
    int numberOfEachDenomination[numberOfDenominations]; // i.e each denomination has how many times it is used
    int amt;
    cout<<"Enter the amount whose change you want"<<endl;
    cin>>amt;
    for(int i=0;i<numberOfDenominations;i++)
    {
        numberOfEachDenomination[i]=0; // i.e initially no coin of each denomination is used
    }
    int curAmt=amt;
    int noOfCoins=0;
    while(curAmt>0)
    {
        for(int i=numberOfDenominations-1;i>=0;i--)
        {
            if(curAmt>=denominations[i]) // i.e since starting from higherst denomination => we'll get min number of coins
            {
                numberOfEachDenomination[i]++;
                curAmt-=denominations[i];
                noOfCoins++;
                break; // now we don't need to check for lower denominations , we'll start aain ni next oteration from highest denomination
            }
        }

    }
    cout<<"Number of coins used"<<noOfCoins<<endl;
    cout<<"Number of each denomination"<<endl;
    for(int i=0;i<numberOfDenominations;i++)
    {
       cout<<denominations[i]<<" "<<numberOfEachDenomination[i]<<endl;
    }

        
    
}