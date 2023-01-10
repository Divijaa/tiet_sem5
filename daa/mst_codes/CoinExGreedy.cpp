#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum ;
    cout<<"enter the sum value:";
    cin>>sum;
    int n;
    cout<<"enter the number of coins:";
    cin>> n;
    vector<int> coins;
    cout<<"enter the values of coins:";
    for(int i = 0 ; i < n ;i++)
    {
        int temp;
        cin>>temp;
        coins.push_back( temp);
    }
    
    sort(coins.begin() , coins.end());
    vector<int> answer;
    for(int i = coins.size() - 1 ; i >= 0 ; i --)
    {
        while (sum >= coins[i])
        {
            sum -= coins[i];
            answer.push_back(coins[i]);
        }
    }
    cout<<"the coins used are : ";
    for(int i = 0 ; i< answer.size() ;i++)
    {
        cout<<answer[i];
    }
    cout<<endl;
    cout<<"the minimum number of coins required are "<< answer.size();
}
