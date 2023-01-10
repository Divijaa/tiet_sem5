#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of vertices of graph "<<endl;
    cin>>n;
    int graph[n][n];
    cout<<"Enter the graph "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    int indegree[n];
    for(int i=0;i<n;i++)
    {
        indegree[i]=0;
    }
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        indegree[i]+=graph[i][j];
    }
}
int counteven=0;
int countodd=0;
for(int i=0;i<n;i++)
{
    if(indegree[i]%2==0)
    counteven++;
    else
    countodd++;
}
if(counteven==n && countodd==0)
{
    cout<<"Euler circuit"<<endl;
}
else if(countodd==2)
{
    cout<<"Euler path "<<endl;
}
else 
cout<<"Graph is not euler "<<endl;
}
