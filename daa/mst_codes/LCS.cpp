#include <bits/stdc++.h>
using namespace std;
void lcs(string X, string Y, int m, int n)
{
    int l[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                l[i][j] = 0;
            }
            //if alphabets match toh diagonal val +1
            else if (X[i-1] == Y[j-1])
            {
                l[i][j] = l[i - 1][j - 1] + 1;
            }
            //if prev col ki val is jyada then prev row
            else if (l[i][j - 1] > l[i - 1][j])
            {
                l[i][j] = l[i][j - 1];
            }
            else
            {
                l[i][j] = l[i - 1][j];
            }
        }
    }
    int index = l[m][n];

//for finding the subsequqnce of the two strings
    char lcs[index + 1];
    lcs[index] = '\0'; 
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
    	//diagonal wali val push
        if (X[i-1] == Y[j-1])
        {
            lcs[index - 1] = X[i-1]; 
            i--;
            j--;
            index--; 
        }
        //row wala arrow hai
        else if (l[i - 1][j] > l[i][j - 1])
            i--;
        else
        //col wala arrow hai
            j--;
    }   

	cout << "LCS of " << X << " and " << Y << " is " << lcs;
    cout<<endl<<"Maximum length of sub sequence is "<<l[m][n];

    return ;

}

int main()
{

    string X ="AGGTAB";
    string Y ="GXTXAYB";
    int m = X.length();
    int n = Y.length();
    lcs(X,Y,m,n);

    return 0;
}
