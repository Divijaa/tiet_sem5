#include<bits/stdc++.h>
using namespace std;


int CoinExhange(int coins[],int n,int amt){
    int dp[n+1][amt+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=amt;j++)
		{
			//first col ko 0 se
            if(j==0) dp[i][j]=0;
            //first row ko inf se 
            else if(i==0) dp[i][j]=1e5;
            //if coin ki val is more than j toh upr wali row copy kro
            else if (coins[i-1]>j) dp[i][j]=dp[i-1][j];
            //else choose min from upr wali row and 1 + uss index ki val jitna j mei se minus krke bcha hai
            else dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
        }
    }
 	for(int i = 0 ; i <= n ; i++)
   	{
   		for(int j = 0 ; j <= amt ; j++)
   		{
   			cout<<dp[i][j]<<"  ";
		   }
		   cout<<endl;
	   }
    return dp[n][amt]>1e4 ? -1 : dp[n][amt];

}
int main(){
    int coins[4]={2,3,5,10};
    int amt=15;

    cout<<"Minimum number of coins needed to make the given amount is "<<CoinExhange(coins,3,amt)<<endl;

}
