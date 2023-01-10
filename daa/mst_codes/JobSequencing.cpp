#include<bits/stdc++.h>
using namespace std;
struct jobs{
	string id;
	int deadline , profit;
};

bool jobCompare(jobs j1 , jobs j2)
{
	//decreasing order
	return j1.profit > j2.profit;
}

JobScheduling(jobs arr[] , int n)
{
	sort(arr, arr+n , jobCompare);
	
	int JobSeq[n];
	bool slot[n];
	
	for(int i = 0 ; i < n ; i++)
	{
		slot[i] = false;
	}
	
	for(int i = 0 ; i < n ; i ++)
	{
		for( int j = min(n,arr[i].deadline)-1 ; j >=0 ; j--)
		{
			cout<<"j"<<j<<" ";
			if(slot[j] == false)
			{
				JobSeq[j] = i;
				cout<<JobSeq[j]<<" ";
				slot[j] = true;
				break;
			}
		}
	}
	// Print the result
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[JobSeq[i]].id << " ";
}


int main()
{
//	jobs arr[] = { { "J1", 2, 100 },{ "J2", 1, 19 },{ "J3", 2, 27 },{ "J4", 1, 25 },{ "J5", 3, 15 }};
   jobs arr[] = { { "J1", 2, 100 },{ "J2", 1, 10 },{ "J3", 2, 15 },{ "J4", 1, 27 }};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    // Function call
    JobScheduling(arr, n);
    return 0;
}
//time complex O(n2)
