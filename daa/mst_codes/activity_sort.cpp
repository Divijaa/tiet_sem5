#include<bits/stdc++.h>
using namespace std;
//structure for activity
struct ele{
	int no, start , finish;
};

void sorting(ele s[] , int n)
{
	int i, j;
	//using bubble sort complexity = O(N2)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            
            if (s[j].finish > s[j+1].finish)
            {
                swap(s[j],s[j+1]);
            }
        }
    }
}

void activitySelection(ele s[] , int n)
{
	//sorting on the basis of finish time
	sorting(s, n);
	
	cout<<"the selected activities are:";
	int i = 0; 
	cout<<s[i].no<< " ";
	for(int j = 1 ; j < n ;j++)
	{
		//sj >= fi
		if(s[j].start >= s[i].finish)
		{
			cout<<s[j].no<< " ";
			i=j;
		}
	}
}
int main()
{
	ele s[]= { {1,5,9},{2,1,2},{3,3,4},{4,0,6},{5,5,7},{6,8,9}};

//	int m = 1;
//	for(int i = 0 ; i < m ; i++)
//	{
//		cin>>s[i].no;
//		cin>>s[i].start;
//		cin>>s[i].finish;
//	}
		int n = sizeof(s)/sizeof(s[0]);
	activitySelection(s,n);
	return 0;
}
