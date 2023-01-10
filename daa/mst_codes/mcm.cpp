#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
    /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the */
 
    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++)
    {
    	//because hume diagonal values fill krni hai
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            //for value of k ----- i<=k<j
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                //because hume min lena hai jaha k ki value more than one value hai
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n - 1];
}
 
// Driver Code
int main()
{
    int p[] = {30,35,15,5,10,20,25 };
    int size = sizeof(p) / sizeof(p[0]);
 
    cout << "Minimum number of multiplications is "
        << MatrixChainOrder(p, size);

    return 0;
}
//time complex O(n3)
