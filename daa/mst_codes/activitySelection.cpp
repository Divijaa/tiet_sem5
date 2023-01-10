#include<bits/stdc++.h>
using namespace std;
//structure for activity
struct ele{
	int no, start , finish;
};


activityCompare(ele s1 , ele s2)
{
	return (s1.finish < s2.finish);
}
activitySelection(ele s[] , int n)
{
	//sorting on the basis of finish time
	sort(s, s+n , activityCompare);
	
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
//time complex O(n)
