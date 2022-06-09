#include<iostream>
#include<math.h>
using namespace std;


int length(int a) // calulating number of digits
{
    int count=0;
    while(a!=0)
    {
        a/=10;
        count++;
    }
    return count;
}

long karat(long x , long y)
{
    if(x<10 && y<10)
    {
        return x*y; // i.e if both numbers are of 1 digit then simply multiply
    }

    long n=max(length(x),length(y)); // size will be the max of digits of both numbers
    long half= (long)ceil(n/2); // Taking ceil since if size is odd then we'll  , ex: 3/2 == 1 , but now we'll get 2
    long a= x / (long)pow(10,(double)half); //// first half of x   since pow returns double data type and expects double
    long b= x% (long)pow(10,(double)half);// second half of x
    long c=y/ (long)pow(10,(double)half); // first half of y
    long d=y% (long)pow(10,(double)half);// second half of y

    // now ac and bd
    long ac=karat(a,c); // first half of number's multiplicatioon
    long bd=karat(b,d); // second part of number's multiplication
    long ad_bx=karat(a+b,c+d)-ac-bd; // i.e mult of sum of both parts - first half of both mul - second part of both mul


    return ac*(long)pow(10,2*half) +ad_bx*(long)pow(10,half)+bd;


}

int main()
{
    int n1,n2;
    cout<<"Enter two numbers"<<endl;
    cin>>n1>>n2;
    cout<<"Mutltiplcaition is"<<" :"<<karat(n1,n2)<<endl;

}