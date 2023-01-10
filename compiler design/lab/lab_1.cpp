#include<bits/stdc++.h>
using namespace std;
int main()
{
	int states;
	int terminals;
	cout<<"enter the number of terminals"<<endl;
	cin>> terminals;
	cout<<"enter the number of states"<<endl;
	cin>> states;
	
	vector<vector<int>> nfa_t;
	for(int i = 0 ; i < states ;i ++)
	{
		vector<int> temp(,0);
		for(int j = 0 ; j < terminals + 2 ; j++)
		{
			int a;
			cin>>a;
			temp.push_back(a);
		}
		
		nfa_t.push_back(temp);	
	}
	
	for(int i = 0 ; i < states ; i ++)
	{
		for(int j = 0 ; j < terminals+2 ; j++)
		{
			cout<<nfa_t[i][j]<<" ";
		}
		cout<<endl;
	}
