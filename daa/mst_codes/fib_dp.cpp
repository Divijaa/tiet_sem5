#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n ;
	cin>> n;
	
	int fib[n + 2];
 	fib[0] = 0;
 	fib[1] = 1;
    for(int i = 2; i <= n; i++)
    {
       fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    cout<<"the answer is "<<fib[n];
}

//#include <iostream>
// 
//using namespace std;
// 
//int fib(int n)
//{
//    if(n==1)
//        return 1;
//    if(n==0)
//        return 0;
//    int f_oneback=1;
//    int f_twoback=0;
//    int f;
//    for(int i=1;i<n;i++)
//    {
//        f=f_oneback+f_twoback;
//        f_twoback=f_oneback;
//        f_oneback=f;
//    }
//    return f;
//}
