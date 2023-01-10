#include <bits/stdc++.h>
using namespace std;
# define d 256
 
void badChartable( string str, int size,int badchar[d])
{
    int i;
    for (i = 0; i < d; i++)
        badchar[i] = -1;
        //put uski last occurence 
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}
 
void search( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
 
    int badchar[d];
    badChartable(pat, m, badchar);
 
    int s = 0; 
    while(s <= (n - m))
    {
        int j = m - 1;
 
        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
 
        if (j < 0)
        {
            cout << "pattern occurs at shift = " << s << endl;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
        //skipping with the help of bad char rule and good suffix rule
            s += max(1, j - badchar[txt[s + j]]);
    }
}
 
/* Driver code */
int main()
{
    string txt= "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}
