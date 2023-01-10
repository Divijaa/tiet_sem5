#include<bits/stdc++.h>
using namespace std;
struct item{
	int id,profit , weight ;
	float p_w , x; 
};
bool compare(item a , item b){
	//in decreasing order
    return (a.p_w>b.p_w);
}
int main()
{
	int n , k;
	cout<<"enter the number of items:";
	cin>>n;
	cout<<"enter the capacity of knapsack";
	cin>>k;
	
	item items[n];
	for(int i = 0 ; i < n ; i++)
	{
		items[i].id = i +1;
		cin>>items[i].profit;
		cin>>items[i].weight;
		items[i].p_w = items[i].profit/items[i].weight;
	}
	sort(items, items+n , compare);
	int i = 0 ; 
	int total_profit = 0;
	while(k > 0)
	{
		items[i].x = min(items[i].weight, k);
		k = k - items[i].x;
		cout<<k<<"imk";
		//to calculate the fraction of item that we are using
		items[i].x=items[i].x/items[i].weight;
		cout<<total_profit<<" ";
        total_profit+=items[i].profit*items[i].x;  
        i++;     
    }
    cout<<total_profit<<endl;
		
	}
//time complexity - O(nlogn)
