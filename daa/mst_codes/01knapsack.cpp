#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int profit[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight for element " << i + 1 << endl;
        cin >> profit[i];
        cin >> wt[i];
    }

    cout << "Enter the value of knapsack" << endl;
    int k;
    cin >> k;
    
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
                //agr toh weight jyda hai sidha upr se copy kre
            else if (wt[i-1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            //else choose max from jo upr wali row mei profit hai voh , 
			//and jo ab profit hoga and + voh bag mei dalne ke baad kitni jgha left usi row mei uss index pr kitna pda 
                dp[i][j] = max(dp[i - 1][j], profit[i-1] + dp[i - 1][j - wt[i-1]]);
        }
    }
    cout << "Maximum profit is " << dp[n][k] << endl;
   
    
   	for(int i = 0 ; i <= n ; i++)
   	{
   		for(int j = 0 ; j <= k ; j++)
   		{
   			cout<<dp[i][j]<<" ";
		   }
		   cout<<endl;
	   }

//15 1
//10 5
//9 3
//5 4
}
