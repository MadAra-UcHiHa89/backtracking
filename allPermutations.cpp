#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// basically suppose we have string ABC , then we call func(BC) which gives all permutation of BC and we append A to LAST OF ALL PERMUATIONS)
// Then we call func(AC) which gives all permutation of AC and we append B to LAST OF ALL PERMUATIONS of AC)
// Then we call func(AB) which gives all permutation of AB and we append C to LAST OF ALL PERMUATIONS of AB)
// Basically run a loop from i=0 toi=length-1 and call func on substrings by exlcuing that character i.e str[i] and  after getting all permuatations of substring append that character to last.
// Base case is when length of string ==1


vector<string> allPermutations(string str)
{
    if(str.length()==1) // => Base case legth of string 1 , => all permuatations are just string itself
    {
  vector<string> solution;
    solution.push_back(str);
    cout<<"Str: "<<str<<endl;
    return solution;
    }
 vector<string> solution;
    // => We'll break the string at each character and call allPermutations on each substring
    for(int i=0;i<str.length();i++)
    {
        if(i==0) // => first character then substring will be str[1] to str[legth-1]
        {
          string subStr=str.substr(1,str.length()-1); //substr(pos,len) == subst from [pos,pos+len) pos-> which index should substr start from , & leghth => how many characters  from the initial charcater should be included in the substring I.E LEGTH OF SUBTRING
            vector<string> subStrPermutations=allPermutations(subStr);
           
            for(int j=0;j<subStrPermutations.size();j++)
            { 
                cout<<subStrPermutations[j]+subStr[i]<<" INSIDE"<<endl;
               solution.push_back(subStrPermutations[j]+subStr[i]);
            }
        }
        else if(i==str.length()-1) // =>last character of string to be ecluded
        {
           string subStr=str.substr(0,str.length()-1);// Strating from first index upto second last index eleemnt since lehth is second argument 
           vector<string> subStrPermutations=allPermutations(subStr);
            for(int j=0;i<subStrPermutations.size();j++)
            {
                 cout<<subStrPermutations[j]+subStr[i]<<" INSIDE"<<endl;
                solution.push_back(subStrPermutations[j]+str[i]); //Appending the exlucded character to permuatations of all substrings
            }
        }
        else{ // => element characer in middle of string 
        string subStr=str.substr(0,i) + str.substr(i+1,str.length()-i); // str.legth()-1-i => since we need last index-1 characters from i+1 th index INCLUDING I+1 th index
        vector<string> subStrPermutations=allPermutations(subStr);
        for(int j=0;j<subStrPermutations.size();j++)
        {
                       cout<<subStrPermutations[j]+subStr[i]<<" INSIDE"<<endl;
            solution.push_back(subStrPermutations[j]+str[i]);
        }

        }
    }

    return solution;
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    vector<string> permutations;
    
    permutations=allPermutations(str);

    for(int i=0;i<permutations.size();i++)
    {
        cout<<permutations[i]<<endl;
    }

}