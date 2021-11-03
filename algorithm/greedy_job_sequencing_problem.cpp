// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;

//A structure to represent a job
struct Job
{
    char id;
    int deadline;
    int profit;// Profit if job is over before or on deadline
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

//Returns minimum number of platforms required
void printJobScheduling(Job jobs[], int num)
{
    //sort in decreasing order of profit
    sort(jobs, jobs+num, comparison);

    int result[num]; //to store result
    bool time_slot[num]; //keep track of free time slot

    for(int i=0; i<num; ++i) //initialise all the slot to free
        time_slot[i] = false;

    //iterate through all given jobs
    for(int i=0; i<num; ++i)
    {
        //find free slot for this job
        for(int j=min(num, jobs[i].deadline)-1; j>=0; j--)
        {
            //if the slot is not occupied
            if(time_slot[j]==false)
            {
                result[j] = i; //Add this job to result
                time_slot[j] = true; // make this slot occupied
                break;
            }
        }
    }

    for(int i=0; i<num; ++i)
        if(time_slot[i])
            cout << jobs[result[i]].id << ' ';
}

int main()
{
    Job jobs[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int job_count = sizeof(jobs)/sizeof(jobs[0]);
    cout << "The maximum profit sequence of jobs\n";

    printJobScheduling(jobs, job_count);

    return 0;
}
