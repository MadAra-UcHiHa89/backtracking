#include<iostream>
#include<algorithm>
using namespace std;


// Basically sort jobs in decreasing order of profit and then assign job from its deadline day if not then move left if no 
// day free then then ignore it and move to next job

class job
{
    public:
    int jobId;
    int deadline;
    int profit;

    job(int id,int d , int p)
    {
        jobId=id;
        deadline=d;
        profit=p;
    }
    job()
    {

    }

};

bool comparator(job j1, job j2)
{
    return j1.profit > j2.profit; // sorting in descending order i.e only swap when the expression is true
}

int jobIdToProfitMapper(job* jobs,int jobId,int n)
{
    for(int i=0;i<n;i++)
    {
        if(jobs[i].jobId==jobId)
        {
            return jobs[i].profit;
        }
    }
    return -1; // no job with that id
    
    
}
int main()
{
    int n;
    cout<<"Enter the number of jobs"<<endl;
    cin>>n;
    int days;
    cout<<"Enter the number of days"<<endl;
    cin>>days;
    job* jobs=new job[n];
    int* dayAssigned=new int[n]; // array storing which job is assigned to which day
    for(int i=0;i<days;i++)
    {
        dayAssigned[i]=-1; // initially no job assigned to that day
    }

    cout<<"Enter the jobid, deadline and profit of each job"<<endl;
    for(int i=0;i<n;i++)
    {
        int jobId,deadline,profit;
        cin>>jobId>>deadline>>profit;
        job j1(jobId,deadline,profit);
        jobs[i]=j1;
    }

    sort(jobs,jobs+n,comparator);
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<jobs[i].jobId<<" ";
    }

    for(int i=0;i<n;i++)
    {
        // Going from job with highest profit and assign it to the day with deadline less than or equal to its deadline if any daya aviable if not then ignore
        for(int j=jobs[i].deadline-1;j>=0;j--) // deadline -1 since day starts from 1 in input and in array index starts from 0 hence
        { // moving from day = dealine of job[i] to day = 0
            if(dayAssigned[j]==-1) // => No job assigned on that day thus can be assigned
            {
                dayAssigned[j]=jobs[i].jobId; // assigning job to that day
                break;
            }
        }
    }

    int profit=0;
    for(int i=0;i<days;i++)
    {
        if(dayAssigned[i]!=-1) // => A job has been assigned to that day
        {
           profit+=jobIdToProfitMapper(jobs,dayAssigned[i],n);
        }
    }

    cout<<"Maximum profit is: "<<profit<<endl;
    cout<<"Each day assigned to a job with id"<<endl;
    for(int i=0;i<days;i++)
    {
        cout<<dayAssigned[i]<<" ";
    }



    delete [] jobs;
    delete [] dayAssigned;

}

/*
5

3

1 2 100
2 1 19
3 2 27
4 1 25
5 3 15

*/