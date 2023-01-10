#include<iostream>
using namespace std;
int main()
{
    string s1 ;
    string s2 ;
    cout<<"enter the first string :";
    cin>>s1;
    cout<<"enter the second string :";
    cin>>s2;
    
    int N = s1.length();
    int M = s2.length();
    
     for (int i = 0; i <= N - M; i++) {
        int j;
 
        for (j = 0; j < M; j++)
            if (s1[i + j] != s2[j])
                break;
 
        if (j == M)
            cout << "Pattern found at index " << i <<endl;
	}
}
