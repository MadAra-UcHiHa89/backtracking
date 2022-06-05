#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


// l-> start index of the substring, r-> end index of the substring
void permutations(string s,int start,int end)
{
if(start>=end) // i.e if single character then number of permuattion is the string itself. 
{
    cout<<s<<endl;
    return;
}

for(int i=start;i<=end;i++)
{
    // swapping start index and ith index cahracter
    swap(s[start],s[i]);
    permutations(s,start+1,end);
    // Backtracking
    swap(s[start],s[i]);
}

}


int main()
{
  string s;
  cout<<"Enter the string"<<endl;
  cin>>s;
  permutations(s,0,s.length()-1);
}